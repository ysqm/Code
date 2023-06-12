package main

import (
	"fmt"
	"net"
	"sync"
)

type Server struct {
	Ip   string
	Port int

	OLmap  map[string]*User
	mplock sync.RWMutex

	Message chan string
}

func Newserver(Ip string, Port int) *Server {
	server := &Server{
		Ip:      Ip,
		Port:    Port,
		OLmap:   make(map[string]*User),
		Message: make(chan string),
	}
	return server
}

func (this *Server) ListenMessage() {
	for {
		msg := <-this.Message

		this.mplock.Lock()
		for _, cli := range this.OLmap {
			cli.C <- msg
		}
		this.mplock.Unlock()
	}
}

func (this *Server) Boardcast(user *User, msg string) {
	sendmsg := "[" + user.Addr + "]" + user.Name + ":" + msg
	this.Message <- sendmsg
}

func (this *Server) Hander(conn net.Conn) {
	//fmt.Println("链接建立成功")
	user := NewUser(conn)

	this.mplock.Lock()
	this.OLmap[user.Addr] = user
	this.mplock.Unlock()

	this.Boardcast(user, "已上线")

	select {}
}

func (this *Server) Start() {
	//Soceket.listen
	listener, err := net.Listen("tcp", fmt.Sprintf("%s:%d", this.Ip, this.Port))
	if err != nil {
		fmt.Println("net.listen error:", err)
	}
	//关闭端口
	defer listener.Close()
	go this.ListenMessage()
	for {
		conn, err := listener.Accept()
		if err != nil {
			fmt.Println("Listener accept error:", err)
			continue
		}
		go this.Hander(conn)
	}
}

