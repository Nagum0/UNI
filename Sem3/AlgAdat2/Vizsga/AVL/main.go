package main

import (
	"avl/avl"
	"fmt"
)

func main() {
    d := false
    var root *avl.Node[int] = nil
    avl.AVLInsert(&root, 10, &d)
    avl.AVLInsert(&root, 11, &d)
    avl.AVLInsert(&root, 9, &d)
    avl.AVLInsert(&root, 17, &d)
    avl.AVLInsert(&root, 20, &d)
    avl.AVLInsert(&root, 8, &d)
    avl.AVLInsert(&root, 25, &d)
    avl.AVLInsert(&root, 28, &d)
    fmt.Println(root.String())
}
