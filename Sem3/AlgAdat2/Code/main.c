
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

	// del example:
	Node* y = new_node(15);	

	AVLinsert(&y, 10, &d);
	AVLinsert(&y, 20, &d);
	AVLinsert(&y, 3, &d);
	AVLinsert(&y, 18, &d);
	AVLinsert(&y, 25, &d);
	AVLinsert(&y, 17, &d);
	AVLinsert(&y, 22, &d);
	AVLinsert(&y, 30, &d);
	AVLinsert(&y, 21, &d);
	print("Before AVLdel(...): ", y);

	AVLdel(&y, 20, &d);
	print("After AVLdel(...)", y);

	delete_nodes(x);
	delete_nodes(y);
	return 0;
}