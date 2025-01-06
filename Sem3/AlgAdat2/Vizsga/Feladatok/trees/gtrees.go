package trees

import (
	"fmt"
	"strconv"
	"strings"
)

type GTreeNode struct {
    Key     int
    Child1  *GTreeNode
    Sibling *GTreeNode
}

func NewGTreeNode() *GTreeNode {
    return &GTreeNode{
        Child1: nil,
        Sibling: nil,
    }
}

func NewGTreeNodeK(k int) *GTreeNode {
    return &GTreeNode{
        Key: k,
        Child1: nil,
        Sibling: nil,
    }
}

func GTreeToString(node *GTreeNode, d int) string {
    var openBracket string
    var closeBracket string
    
    switch d {
        case 0:
            openBracket = "{"
            closeBracket = "}"
        case 1:
            openBracket = " ["
            closeBracket = "]"
        default:
            openBracket = " ("
            closeBracket = ")"
    }

    s := fmt.Sprintf("%v%v", openBracket, node.Key)

    if node.Child1 != nil {
        s += GTreeToString(node.Child1, d + 1)
    }

    s += closeBracket

    if node.Sibling != nil {
        s += GTreeToString(node.Sibling, d)
    }

    return s
}

func FromStringToGTree(tree string) *GTreeNode {
    tree = strings.ReplaceAll(tree, " ", "")
    idx := 0
    root := parse(tree, &idx)
    return root
}

func parse(tree string, idx *int) *GTreeNode {
    // Consume the opening brackets
    if tree[*idx] == '{' || tree[*idx] == '[' || tree[*idx] == '(' {
        *idx += 1
    }

    // Parse the value & create the node
    start := *idx
    for *idx < len(tree) && tree[*idx] >= '0' && tree[*idx] <= '9' {
        *idx += 1
    }
    key, _ := strconv.Atoi(tree[start:*idx])
    node := NewGTreeNodeK(key)

    // Parse children
    if *idx < len(tree) && (tree[*idx] == '{' || tree[*idx] == '[' || tree[*idx] == '(') {
        child := parse(tree, idx)
        node.Child1 = child
    }

    // Consume the closing brackets
    if *idx < len(tree) && (tree[*idx] == '}' || tree[*idx] == ']' || tree[*idx] == ')') {
        *idx += 1
    }
    
    // Parse siblings
    if *idx < len(tree) && (tree[*idx] == '{' || tree[*idx] == '[' || tree[*idx] == '(') {
        sibling := parse(tree, idx)
        node.Sibling = sibling
    }

    return node
}

func AreEqual(n1, n2 *GTreeNode) bool {
    if n1 == nil && n2 == nil {
        return true
    }

    if n1 == nil || n2 == nil {
        return false
    }

    if n1.Key != n2.Key {
        return false
    }

    return AreEqual(n1.Child1, n2.Child1) && AreEqual(n1.Sibling, n2.Sibling)
}

func Height(t *GTreeNode) int {
    if t == nil {
        return 0
    }

    if t.Child1 != nil {
        return 1 + Height(t.Child1)
    }

    return Height(t.Sibling)
}
