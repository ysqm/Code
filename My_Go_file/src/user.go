package main

import "net"

type User struct {
	Name string
	Addr string
	C    chan string
	conn net.Conn
}

func NewUser(conn net.Conn) *User {
	Useraddr := conn.RemoteAddr().String()
	user := &User{
		Name: Useraddr,
		Addr: Useraddr,
		C:    make(chan string),
		conn: conn,
	}
	return user
}

func (this *User) ListenMessage() {
	for {
		msg := <-this.C

		this.conn.Write([]byte(msg + "\n"))
	}
}
