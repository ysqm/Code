package main

import "fmt"

var a, b int

func main() {
	a, b = 7, 5
	for i := 1; i < b; i++ {
		fmt.Print(i)
		defer fmt.Print(a)
	}
	fmt.Print(6)
}
