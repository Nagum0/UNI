package graphs

import (
	"feladatok/symbols"
	"fmt"
)

type AdjList []*Edge

func NewAdjList(n int) AdjList {
    l := make([]*Edge, n)
    
    for i := 0; i < n; i++ {
        l[i] = NewEdge(i)
    }

    return l
}

func (l AdjList) String() string {
    s := ""
    
    for i := 0; i < len(l); i++ {
        s += fmt.Sprintf("%d -> %v\n", i, l[i].Next.String())
    }

    return s
}

type Edge struct {
    V    int
    Next *Edge
}

func NewEdge(val int) *Edge {
    return &Edge{
        V: val,
        Next: nil,
    }
}

func (edge *Edge) String() string {
    if edge == nil {
        return symbols.EMPTY_SET
    }

    s := fmt.Sprintf("%d -> ", edge.V)
    p := edge.Next

    for p != nil {
        s += fmt.Sprintf("%d -> ", p.V)
        p = p.Next
    }

    s += symbols.EMPTY_SET

    return s
}

func (a AdjList) Transponent(n int, at *AdjList) {
    *at = NewAdjList(n)

    for i := n - 1; i >= 0; i-- {
        p := a[i].Next
        
        for p != nil {
            u := p.V
            q := NewEdge(i)
            q.Next = (*at)[u].Next
            (*at)[u].Next = q
            p = p.Next
        }
    }
}

func (g AdjList) InOutCounts(n int, in, out *[]int) {
    *in = make([]int, n)
    *out = make([]int, n)

    for i := 0; i < n; i++ {
        p := g[i].Next

        for p != nil {
            (*out)[i]++
            (*in)[p.V]++
            p = p.Next
        }
    }
}
