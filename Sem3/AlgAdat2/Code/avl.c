#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>
#include "avl.h"

typedef struct Node {
	int key;
	int b;
	struct Node* left;
	struct Node* right;
} Node;

Node* new_node(int key) {
	Node* node = (Node*) malloc(sizeof(Node));

	if (node == NULL) {
		printf("FAILED TO CREATE NODE\n");
		exit(1);		
	}

	node->key = key;
	node->b = 0;
	node->left = NULL;
	node->right = NULL;

	return node;
}

void AVLinsert(Node** t, int k, bool* d) {
	if (*t == NULL) {
		(*t) = new_node(k);
		*d = true;
	}
	else if (k < (*t)->key) {
		AVLinsert(&(*t)->left, k, d);

		if (*d) {
			leftSubTreeGrown(t, d);
		}
	}
	else if (k > (*t)->key) {
		AVLinsert(&(*t)->right, k, d);

		if (*d) {
			rightSubTreeGrown(t, d);
		}
	}
	else {
		*d = false;
	}
}

void leftSubTreeGrown(Node** t, bool* d) {
	if ((*t)->b == -1) {
		Node* l = (*t)->left;

		if (l->b == -1) {
			balanceMMm(t, &l);
		}
		else {
			balanceMMp(t, &l);
		}

		*d = false;
	}
	else {
		(*t)->b -= 1;
		*d = ((*t)->b < 0);
	}
}

void rightSubTreeGrown(Node** t, bool* d) {
	if ((*t)->b == 1) {
		Node* r = (*t)->right;

		if (r->b == 1) {
			balancePPp(t, &r);
		}
		else {
			balancePPm(t, &r);
		}

		*d = false;
	}
	else {
		(*t)->b += 1;
		*d = ((*t)->b > 0);
	}
}

void balanceMMm(Node** t, Node** l) {
	(*t)->left = (*l)->right;
	(*l)->right = *t;
	(*t)->b = 0;
	(*l)->b = (*t)->b;
	*t = *l;
}

void balanceMMp(Node** t, Node** l) {
	Node* r = (*l)->right;
	(*t)->left = r->right;
	(*l)->right = r->left;
	r->left = (*l);
	r->right = (*t);
	(*l)->b = -floor((r->b + 1) / 2);
	(*t)->b = floor((1 - r->b) / 2);
	r->b = 0;
	*t = r;
}

void balancePPp(Node** t, Node** r) {
	(*t)->right = (*r)->left;
	(*r)->left = *t;
	(*t)->b = 0;
	(*r)->b = (*t)->b;
	*t = *r;
}

void balancePPm(Node** t, Node** r) {
	Node* l = (*r)->left;
	(*t)->right = l->left;
	(*r)->left = l->right;
	l->left = (*t);
	l->right = (*r);
	(*t)->b = -(floor((l->b + 1) / 2));
	(*r)->b = floor((1 - l->b) / 2);
	l->b = 0;
	*t = l;
}

void inorder_print(Node* t, int n) {
	if (t != NULL) {
		printf("(");

		if (t->left != NULL)
			inorder_print(t->left, n + 1);

		printf(" [%d] %d ", n, t->key);

		if (t->right != NULL)
			inorder_print(t->right, n + 1);

		printf(")");
	}
}

void AVLremMin(Node** t, Node** minp, bool* d) {
	if ((*t)->left == NULL) {
		*minp = *t;
		*t = (*minp)->right;
		(*minp)->right = NULL;
		*d = true;
	}
	else {
		AVLremMin(&(*t)->left, minp, d);

		if (*d) {
			leftSubTreeShrunk(t, d);
		}
	}
}

void leftSubTreeShrunk(Node** t, bool* d) {
	if ((*t)->b == 1) {
		balancePP(t, d);
	}
	else {
		(*t)->b += 1;
		*d = ((*t)->b == 0);
	}
}

void balancePP(Node** t, bool* d) {
	Node* r = (*t)->right;

	if (r->b == -1) {
		balancePPm(t, &r);
	}
	else if (r->b == 0) {
		balancePP0(t, &r);
		*d = false;
	}
	else if (r->b == 1) {
		balancePPp(t, &r);
	}
}

void balancePP0(Node **t, Node** r) {
	(*t)->right = (*r)->left;
	(*r)->left = *t;
	(*t)->b = 1;
	(*r)->b = -1;
	*t = *r;
}

void AVLdel(Node** t, int k, bool* d) {
	if (*t != NULL) {
		if (k < (*t)->key) {
			AVLdel(&(*t)->left, k, d);

			if (*d) {
				leftSubTreeShrunk(t, d);
			}
		}
		else if (k > (*t)->key) {
			AVLdel(&(*t)->right, k, d);

			if (*d) {
				rightSubTreeShrunk(t, d);
			}
		}
		else if (k == (*t)->key) {
			AVLdelRoot(t, d);
		}
	}
	else {
		*d = false;
	}
}

void AVLdelRoot(Node** t, bool* d) {
	if ((*t)->left == NULL) {
		Node* p = *t;
		*t = p->right;
		free(p);
		*d = false;
	}
	else if ((*t)->right == NULL) {
		Node* p = *t;
		*t = p->left;
		free(p);
		*d = false;
	}
	else if ((*t)->left != NULL && (*t)->right != NULL) {
		rightSubTreeMinToRoot(t, d);

		if (*d) {
			rightSubTreeShrunk(t, d);
		}
	}
}

void rightSubTreeShrunk(Node** t, bool* d) {
	if ((*t)->b == - 1) {
		balanceMM(t, d);
	}
	else {
		(*t)->b -= 1;
		*d = ((*t)->b == 0);
	}
}

void balanceMM(Node** t, bool* d) {
	printf("not implemented\n");
	exit(1);
}

void balanceMM0(Node** t, Node** l) {
	printf("not implemented\n");
	exit(1);	
}

void rightSubTreeMinToRoot(Node** t, bool* d) {
	Node* p = NULL;
	AVLremMin(t, &p, d);
	p->left = (*t)->left;
	p->right = (*t)->right;
	p->b = (*t)->b;
	free(t);
	t = &p;
}


void print(const char* msg, Node* t) {
	printf("%s\n   { ", msg);
	inorder_print(t, 0);
	printf(" }\n");
}

void delete_nodes(Node* t) {
	if (t == NULL) {
		return;
	}

	delete_nodes(t->left);
	delete_nodes(t->right);
	free(t);
}