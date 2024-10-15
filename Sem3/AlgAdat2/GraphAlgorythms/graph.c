#include "graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

int main() {
    int n = 3;

    bool vertexMatrix[3][3] = {
        {false, true, false},
        {true, false, true},
        {false, true, false}
    };

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            printf("%d ", vertexMatrix[i][j]);
        }
        printf("\n");
    }

    Edge* A[n];

    fromVertexMatrixToEdgeList(vertexMatrix, A, n);
    
    for (int i = 0; i < n; i++) {
        printf("[%d] -> ", i);
        print_edge(A[i]);
    }

    int ins[] = {0,0,0};
    int outs[] = {0,0,0};
    in_amount_out_amount(A, ins, outs, n);

    for (int i = 0; i < n; i++) {
        printf("[%d] in: %d; out: %d\n", i, ins[i], outs[i]);
    }

    Edge* AT[n];
    
    transponent_edge_list(A, AT, n);

    for (int i = 0; i < n; i++) {
        printf("[%d] -> ", i);
        print_edge(AT[i]);
    }


    for (int i = 0; i < n; i++) {
        free_edges(A[i]);
        free_edges(AT[i]);
    }

    return 0;
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
