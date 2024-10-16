#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool are_equal(bool A[N][N], Edge** Adj, int n);

int main() {
    bool A[N][N] = {
        {false, false, true},
        {false, false, true},
        {false, false, false}
    };

    Edge* Adj[N];
    Adj[0] = new_edge(3);
    Adj[1] = new_edge(3);
    Adj[2] = NULL;

    bool l = are_equal(A, Adj, N);
    printf("Are equal: %d\n", l);
    
    for (int i = 0; i < N; i++) {
        free(Adj[i]);
    }

    return 0;
}

bool are_equal(bool A[N][N], Edge** Adj, int n) {
    for (int i = 0; i < n; i++) {
        Edge* p = Adj[i];
        
        if (p == NULL) {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == true) {
                    return false;
                }
            }
        } 
        else {
            for (int j = 0; j < n; j++) {
                if (A[i][j] == true && p != NULL && p->v == j) {
                    p = p->next;
                }
                else if (A[i][j] == false && p != NULL && p->v != j) {
                    continue;
                }
                else {
                    return false;
                }
            }
        }
    }

    return true;
}

void transponent_edge_list(Edge **A, Edge **AT, int n) {
    for (int i = 0; i < n; i++) {
        AT[i] = NULL;
    }

    for (int i = 0; i < n; i ++) {
        Edge* p = A[i];

        while (p != NULL) {
            int u = p->v;
            Edge* q = new_edge(i);
            q->next = AT[u];
            AT[u] = q;
            p = p->next;
        }
    }
}

void in_amount_out_amount(Edge **A, int ins[], int outs[], int n) {
    for (int i = 0; i < n; i++) {
        Edge* p = A[i];

        while (p != NULL) {
            int u = p->v;
            outs[u]++;
            ins[i]++;
            p = p->next;
        }
    }
}

void fromVertexMatrixToEdgeList(bool A[N][N], Edge** B, int n) {
    for (int i = 0; i < n; i++) {
        B[i] = NULL;

        for (int j = n - 1; j >= 0; j--) {
            if (A[i][j]) {
                Edge* p = new_edge(j);
                p->next = B[i];
                B[i] = p;
            }
        }
    }
}

Edge* new_edge(int v) {
    Edge* edge = (Edge*)malloc(sizeof(Edge));

    if (edge == NULL) {
        fprintf(stderr, "ERROR WHILE ALLOCATING MEMORY FOR EDGE\n");
        exit(1);
    }
    
    edge->v = v;
    edge->next = NULL;

    return edge;
}

void free_edges(Edge *edge) {
    Edge* current_edge = edge->next;

    while (current_edge != NULL) {
        Edge* p = current_edge->next;
        free(current_edge);
        current_edge = p;
    }

    free(edge);
}

void print_edge(Edge *edge) {
    Edge* p = edge;

    while (p != NULL) {
        printf("%d -> ", p->v);
        p = p->next;
    }

    printf("NULL\n");
}
