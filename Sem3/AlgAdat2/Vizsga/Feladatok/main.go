package main

import (
	"feladatok/trees"
	"fmt"
)

func main() {
    root := trees.NewGTreeNodeK(1)
    root.Child1 = trees.NewGTreeNodeK(2)
    root.Child1.Sibling = trees.NewGTreeNodeK(3)
    root.Child1.Sibling.Sibling = trees.NewGTreeNodeK(4)
    root.Child1.Child1 = trees.NewGTreeNodeK(5)
    root.Child1.Sibling.Sibling.Child1 = trees.NewGTreeNodeK(6)
    root.Child1.Sibling.Sibling.Child1.Sibling = trees.NewGTreeNodeK(7)
    fmt.Println(trees.GTreeToString(root, 0))

    tree := "{1 [2 (5)] [3] [4 (6) (7)]}"
    convTree := trees.FromStringToGTree(tree)
    fmt.Println(trees.GTreeToString(convTree, 0))

    fmt.Println(trees.AreEqual(root, convTree))

    fmt.Println(trees.Height(convTree))

    t := "{0 [1 [2 [3 (4)]]]}"
    t1 := trees.FromStringToGTree(t)
    fmt.Println(trees.Height(t1))
}
