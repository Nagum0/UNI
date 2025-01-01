package avl

import (
	"fmt"
	"math"
)

type Ordered interface {
    int | int8 | int16 | int32 | int64 | uint | uint8 | uint16 | uint32 | uint64 | float32 | float64 | string
}

type Node[T Ordered] struct {
    key         T
    b           int
    Left, Right *Node[T]
}

func NewNode[T Ordered]() *Node[T] {
    return &Node[T] {
        b: 0,
        Left: nil,
        Right: nil,
    }
}

func NewNodeKey[T Ordered](k T) *Node[T] {
    return &Node[T] {
        key: k,
        b: 0,
        Left: nil,
        Right: nil,
    }
}

func (node Node[T]) String() string {
    s := "["

    if node.Left != nil {
        s += node.Left.String()       
    }

    s += fmt.Sprintf(" %v(%v) ", node.key, node.b)

    if node.Right != nil {
        s += node.Right.String()
    }
    
    s += "]"
    return s
}

func AVLInsert[T Ordered](t **Node[T], k T, d *bool) {
    if *t == nil {
        *t = NewNodeKey(k)
        *d = true
    } else {
        if k < (*t).key {
            AVLInsert(&(*t).Left, k, d)
            if *d {
                leftSubTreeGrown(t, d)
            }
        } else if k > (*t).key {
            AVLInsert(&(*t).Right, k, d)
            if *d {
                rightSubTreeGrown(t, d)
            }
        } else {
            *d = false
        }
    }
}

func leftSubTreeGrown[T Ordered](t **Node[T], d *bool) {
    if (*t).b == -1 {
        l := (*t).Left
        if l.b == -1 {
            balanceMMm(t, &l)
        } else {
            balanceMMp(t, &l)
        }
        *d = false
    } else {
        (*t).b = (*t).b - 1
        *d = (*t).b < 0
    }
}

func rightSubTreeGrown[T Ordered](t **Node[T], d *bool) {
    if (*t).b == 1 {
        r := (*t).Right
        if r.b == 1 {
            balancePPp(t, &r)
        } else {
            balancePPm(t, &r)
        }
        *d = false
    } else {
        (*t).b = (*t).b + 1
        *d = (*t).b > 0
    }
}

func balancePPp[T Ordered](t, r **Node[T]) {
    (*t).Right = (*r).Left
    (*r).Left = *t
    (*t).b, (*r).b = 0, 0
    *t = *r
}

func balanceMMm[T Ordered](t, l **Node[T]) {
    (*t).Left = (*l).Right
    (*l).Right = *t
    (*t).b, (*l).b = 0, 0
    *t = *l
}

func balancePPm[T Ordered](t, r **Node[T]) {
    l := (*r).Left
    (*t).Right = l.Left
    (*r).Left = l.Right
    l.Left = *t
    l.Right = *r
    (*t).b = -int(math.Floor(float64(l.b + 1) / 2))   
    (*r).b = int(math.Floor(float64(1 - l.b) / 2))
    l.b = 0
    *t = l
}

func balanceMMp[T Ordered](t, l **Node[T]) {
    r := (*l).Right
    (*l).Right = r.Left
    (*t).Left = r.Right
    r.Left = *l
    r.Right = *t
    (*l).b = -int(math.Floor(float64(r.b + 1) / 2))
    (*t).b = int(math.Floor(float64(1 - r.b) / 2))
    r.b = 0
    *t = r
}
