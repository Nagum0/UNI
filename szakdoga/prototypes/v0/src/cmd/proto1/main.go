package main

import (
	"os"
	"proto1/src/pkg"
)

func main()  {
	args := os.Args[1:]
	
	switch args[0] {
	case "init":
		pkg.Init()
	case "add":
		pkg.Add(args[1])
	}
}
