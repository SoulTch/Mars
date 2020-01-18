package main

import "C"

func main () {
	for i := 0; i < 30; i++ {
		C.go(i)
	}
}