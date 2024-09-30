#include <stdio.h>

#include "avl.h"

int main() {
	Node* x = new_node(15);
	print(x);
	
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
	print(x);

	delete_nodes(x);
	return 0;
}