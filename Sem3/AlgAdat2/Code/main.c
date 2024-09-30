
#include <stdio.h>

#include "avl.h"

int main() {
	// remMin example:
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
	print("Before AVLremMin(...): ", x);

	Node* minp = NULL;
	AVLremMin(&x, &minp, &d);
	print("After AVLremMin(...): ", x);

	delete_nodes(x);
	return 0;
}