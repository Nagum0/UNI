package main

import (
	"feladatok/gtrees"
	"fmt"
)

func main() {
    root := gtrees.NewGTreeNodeK(1)
    root.Child1 = gtrees.NewGTreeNodeK(2)
    root.Child1.Sibling = gtrees.NewGTreeNodeK(3)
    root.Child1.Sibling.Sibling = gtrees.NewGTreeNodeK(4)
    root.Child1.Child1 = gtrees.NewGTreeNodeK(5)
    root.Child1.Sibling.Sibling.Child1 = gtrees.NewGTreeNodeK(6)
    root.Child1.Sibling.Sibling.Child1.Sibling = gtrees.NewGTreeNodeK(7)
    fmt.Println(gtrees.GTreeToString(root, 0))

    tree := "{1 [2 (5)] [3] [4 (6) (7)]}"
    convTree := gtrees.FromStringToGTree(tree)
    fmt.Println(gtrees.GTreeToString(convTree, 0))

    fmt.Println(gtrees.AreEqual(root, convTree))
}
