#include <stdio.h>
#include <stdlib.h>

#include "hsls.h" 
#include "../node.h"


hsls_t *hsls_cons() {
    hsls_t *l = (hsls_t *) malloc(sizeof(hsls_t));
    if (l == NULL)
        return NULL;
    
    node_t *q = (node_t *) malloc(sizeof(node_t));
    if (q == NULL)
        return NULL;

    l->head = q;
    q->next = NULL;

    return l;
}

void hsls_free(hsls_t *l) {
    node_t *p = l->head;

    while (p != NULL) {
        node_t *q = p->next;
        free(p);
        p = q;
    }

    free(l);
}

void hsls_display(hsls_t *l) {
    node_t *p = l->head->next;
    printf("HEAD -> ");

    while (p != NULL) {
        printf("%d -> ", p->key);
        p = p->next;
    }

    printf("NULL\n");
}

int hsls_insert(hsls_t *l, int data) {
    node_t *p = l->head->next;
    node_t *pe = NULL;

    while (p != NULL && p->key < data) {
        pe = p;
        p = p->next;
    }

    node_t *q = (node_t *) malloc(sizeof(node_t));
    if (q == NULL)
        return EXIT_FAILURE;

    q->key = data;
    q->next = p;

    if (pe == NULL) {
        l->head->next = q;
    }
    else {
        pe->next = q;
    }

    return EXIT_SUCCESS;
}

int hsls_insert_unsorted(hsls_t *l, int data) {
    node_t *q = (node_t *) malloc(sizeof(node_t));
    if (q == NULL)
        return EXIT_FAILURE;

    q->key = data;
    q->next = l->head->next;
    l->head->next = q;

    return EXIT_SUCCESS;
}

int hsls_remove(hsls_t *l, int data) {
    node_t *p = l->head->next;
    node_t *pe = NULL;

    while (p != NULL && p->key < data) {
        pe = p;
        p = p->next;
    }

    if (p != NULL && p->key == data) {
        pe->next = p->next;
        free(p);
        return EXIT_SUCCESS;
    }
    else {
        return EXIT_SUCCESS;
    }
}

int hsls_max_sort(hsls_t *l) {
    node_t *f = l->head->next;
    node_t *i, *j;

    for (i = f; i != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (j->key < i->key) {
                node_swap(f, j);
            }
        }
        f = f->next;
    }
}

void hsls_rem_even(hsls_t *l) {
    node_t *p = l->head->next;
    node_t *pe = l->head;

    while (p != NULL) {
        if (p->key % 2 == 0) {
            pe->next = p->next;
            free(p);
            p = pe->next;
        }
        else {
            pe = p;
            p = p->next;
        }
    }
}

hsls_t *hsls_remove_odd(hsls_t *l) {
    hsls_t *l2 = hsls_cons();
    l2->head->next = NULL;
    node_t *p2 = l2->head;
    hsls_t *r = l2;

    node_t *p = l->head->next;
    node_t *pe = l->head;

    while (p != NULL) {
        if (p->key % 2 != 0) {
            node_t *q = (node_t *) malloc(sizeof(node_t));
            q->key = p->key;
            q->next = NULL;

            p2->next = q;
            p2 = p2->next;

            pe = p;
            p = p->next;
        }
        else {
            pe = p;
            p = p->next;
        }
    }

    return l2;
}

void hsls_reverse(hsls_t *l) {
    node_t *p = l->head;
    node_t *pe = NULL;
    node_t *next = NULL;

    while (p != NULL) {
        next = p->next;
        p->next = pe;
        pe = p;
        p = next;
    }
    l->head = pe;
}