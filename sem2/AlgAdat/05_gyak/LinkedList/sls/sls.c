#include <stdio.h>
#include <stdlib.h>

#include "sls.h"
#include "../node.h"

typedef node_t sls_t;

void sls_free(sls_t **sls) {
    sls_t *p = *sls;

    while (p != NULL) {
        sls_t *q = p->next;
        free(p);
        p = q;
    }

    *sls = NULL;
}

void sls_display(sls_t *sls) {
    sls_t *current_node = sls; 

    while (current_node != NULL) {
        printf("%d -> ", current_node->key);
        current_node = current_node->next;
    }

    printf("NULL\n");
}

int sls_insert(sls_t **sls, int data) {
    sls_t *p = *sls;
    sls_t *pe = NULL;

    while (p != NULL && p->key < data) {
        pe = p;
        p = p->next;
    }

    sls_t *q = (sls_t *) malloc(sizeof(sls_t));
    if (q == NULL)
        return EXIT_FAILURE;

    q->key = data;
    q->next = p;

    if (pe == NULL) {
        *sls = q;
    } else {
        pe->next = q;
    }

    return EXIT_SUCCESS;
}

sls_t *sls_search(sls_t *sls, int data) {
    sls_t *p = sls;
    
    while (p != NULL && p->key < data) {
        p = p->next;
    }

    if (p != NULL && p->key == data) {
        return p;
    }

    return NULL;
}

int sls_remove(sls_t **sls, int data) {
    sls_t *p = *sls;
    sls_t *pe = NULL;

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