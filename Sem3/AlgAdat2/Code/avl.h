#ifndef AVL_H
#define AVL_H

#include <stdbool.h>

typedef struct Node Node;
Node* new_node(int key);

void AVLinsert(Node** t, int k, bool* d);
void leftSubTreeGrown(Node** t, bool* d);
void rightSubTreeGrown(Node** t, bool* d);
void balanceMMm(Node** t, Node** l);
void balanceMMp(Node** t, Node** l);
void balancePPp(Node** t, Node** r);
void balancePPm(Node** t, Node** r);

void print(Node* t);
void delete_nodes(Node* t);

#endif