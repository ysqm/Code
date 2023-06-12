package main

import (
	"errors"
	"go/ast"
)
//import "fmt"

// type List_Node
type list_node struct {
	data interface{}
	next *list_node
}

var size int

type List struct {
	head,tail *list_node
}

func (this *List) Push_back(x interface{}){
	if this.head == nil {
		this.tail = &(list_node{x,nil})
		this.head = this.tail
	} else {
		this.tail.next = &(list_node{x,nil})
		this.tail = this.tail.next
	}
	size++
}

func (this List) Size() int {
	return size
}

//[1-size] 插入
func (this *List) Insert(x int,value interface{}) error {
	if x > size {
		return errors.New("invalid parameter value")
	} else {
		if(x == size )

		if x == 1 {
			this.head = &(list_node{value,this.head})
		} else {
			cur := this.head
			var lst *list_node
			for i := 1 ; i < x ; i++ {
				lst = cur
				cur = cur.next
			}
			cur = &(list_node{value,cur.next})
			lst.next = cur
		}
		return nil
	}
}

func (this *List) Delete(x int) error {
	if x >= size {
		return errors.New("invalid parameter value")
	} else {
		if x == 1 {
			//cur := this.head
			this.head = this.head.next
			//delete(ast.InterfaceType{},)
		} else {
			cur := this.head
			for i := 2 ; i < x ; i++ {
				cur = cur.next
			}
			cur.next = cur.next.next
		}
		return nil
	}
}

func (this *List) Find(x interface{}) int {
	cur := this.head
	sum := 0
	for cur != nil {
		sum++
		if cur.data == x {
			return sum
		}
		cur = cur.next
	}
	return -1
}

func main() {
	var x List
	x

}
