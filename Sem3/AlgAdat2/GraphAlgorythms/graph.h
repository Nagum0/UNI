#include <stdbool.h>

#ifndef GRAPH_H
#define GRAPH_H

#define N 3

typedef struct Edge {
    int v;
    struct Edge* next;
} Edge;

// Edge tools
Edge* new_edge(int v);
void free_edges(Edge* edge);
void print_edge(Edge* edge);

// Algorythms written during class
void fromVertexMatrixToEdgeList(bool A[N][N], Edge** B, int n);
void in_amount_out_amount(Edge* A[], int ins[], int outs[], int n);
void transponent_edge_list(Edge* A[], Edge* AT[], int n);

#endif 
