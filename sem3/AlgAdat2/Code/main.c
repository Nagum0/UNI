#include <stdbool.h>
#include "avl.h"

int main() {
    Node* t = new_node(12);
    bool d = true;

    AVLinsert(&t, 20, &d);
    AVLinsert(&t, 22, &d);
    AVLinsert(&t, 8, &d);
    AVLinsert(&t, 5, &d);
    AVLinsert(&t, 10, &d);
    AVLinsert(&t, 25, &d);
    print("AVL Tree after insertions:", t);

    AVLdel(&t, 12, &d);
    print("AVL Tree after deleting 12:", t);

    delete_nodes(t);

	return 0;
}
