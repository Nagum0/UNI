#include "../node.h"

#ifndef SLS_H
#define SLS_H

typedef node_t sls_t;

void sls_free(sls_t **sls);
void sls_display(sls_t *sls);

int sls_insert(sls_t **sls, int data);
sls_t *sls_search(sls_t *sls, int data);
int sls_remove(sls_t **sls, int data);

void sls_reverse(sls_t **sls);

#endif