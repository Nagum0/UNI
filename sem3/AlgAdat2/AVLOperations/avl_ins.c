#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

typedef struct Node Node;
Node* new_node(int key);

// AVL Insertion:
void AVLinsert(Node** t, int k, bool* d);
void leftSubTreeGrown(Node** t, bool* d);
void rightSubTreeGrown(Node** t, bool* d);
void balanceMMm(Node** t, Node** l);
void balanceMMp(Node** t, Node** l);
void balancePPp(Node** t, Node** r);
void balancePPm(Node** t, Node** r);

// AVL Tools:
void print(const char* msg, Node* t);
void delete_nodes(Node* t);

int main() {
    Node* x = new_node(15);	
	bool d = false;

	AVLinsert(&x, 10, &d);
	AVLinsert(&x, 20, &d);
	AVLinsert(&x, 3, &d);
	AVLinsert(&x, 18, &d);
	AVLinsert(&x, 25, &d);
	AVLinsert(&x, 17, &d);
	AVLinsert(&x, 22, &d);
	AVLinsert(&x, 30, &d);
	AVLinsert(&x, 21, &d);
    
    print("AVL Tree: ", x);
    delete_nodes(x);

    return EXIT_SUCCESS;
}

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

char get_bracket_for_depth(int depth, bool left) {
	switch (depth) {
		case 0:
			return left ? '(' : ')';
		case 1:
			return left ? '[' : ']';
		case 2:
			return left ? '{' : '}';
		default:
			return left ? '(' : ')';
	}
}

void inorder_print(Node* t, int n) {
	if (t != NULL) {
		printf("%c", get_bracket_for_depth(n, true));

		if (t->left != NULL)
			inorder_print(t->left, n + 1);

		// printf(" [%d] %d ", n, t->key);
		printf(" %d ", t->key);

		if (t->right != NULL)
			inorder_print(t->right, n + 1);

		printf("%c", get_bracket_for_depth(n, false));
	}
}

void print(const char* msg, Node* t) {
	printf("%s\n  ", msg);
	inorder_print(t, 0);
	printf("\n");
}

void delete_nodes(Node* t) {
	if (t == NULL) {
		return;
	}

	delete_nodes(t->left);
	delete_nodes(t->right);
	free(t);
}
