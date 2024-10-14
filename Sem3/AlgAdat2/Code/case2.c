#include <stdbool.h>
#include "avl.h"

int main() {
    Node* t = new_node(32);
    bool d = false;

    AVLinsert(&t, 25, &d);
    AVLinsert(&t, 23, &d);
    AVLinsert(&t, 40, &d);
    AVLinsert(&t, 36, &d);
    AVLinsert(&t, 34, &d);
    AVLinsert(&t, 14, &d);
    print("AVL Tree after insertions:", t);
    
    AVLdel(&t, 32, &d);
    print("AVL Tree after deletion of 32:", t);

    delete_nodes(t);

    return 0;
}
