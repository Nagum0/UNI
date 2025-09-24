package graphs

import (
	"fmt"
)

type VertexMatrix [][]int

func NewVertexMatrix(n int) VertexMatrix {
    m := [][]int{}
    
    for i := 0; i < n; i++ {
        s := []int{}

        for j := 0; j < n; j++ {
            s = append(s, 0)
        }

        m = append(m, s)
    }

    return m
}

// Transform a VertexMatrix into an AdjList.
func (c VertexMatrix) Transform(n int, g *AdjList) {
    *g = NewAdjList(n)

    for i := 0; i < n; i++ {
        var e *Edge

        for j := 0; j < n; j++ {
            if c[i][j] == 1 {
                p := NewEdge(j)
                p.Next = e
                e = p
            }
        }

        (*g)[i].Next = e
    }
}

func (m VertexMatrix) String() string {
    s := "    "
    n := len(m)
    
    for i := 0; i < n; i++ {
        s += fmt.Sprintf("%d ", i)
    }

    s += "\n\n"

    for i := 0; i < n; i++ {
        s += fmt.Sprintf("%d   ", i)

        for j := 0; j < n; j++ {
            s += fmt.Sprintf("%d ", m[i][j])
        }

        s += "\n"
    }

    return s
}
