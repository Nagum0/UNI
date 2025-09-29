package main

import (
	"os"
	"proto1/src/pkg"
)

func main()  {
	args := os.Args[1:]
	
	switch args[0] {
	case "get":
		pkg.Get(args[1])
	case "init":
		pkg.Init()
	case "add":
		pkg.Add(args[1])
	case "commit":
		pkg.Commit(args[1])
	case "branch":
		pkg.Branch(args[1])
	case "checkout":
		pkg.Checkout(args[1])
	}
}
