#ifndef EDGES_H__
#define EDGES_H__

#include <stdio.h>
#include "errs.h"

typedef struct edges edges_t;
typedef struct edge edge_t;


struct edges
{
    size_t size;
    edge_t *arr;
};

struct edge {
    size_t p1, p2;
};


error_t edges_init(edges_t *edges, size_t size);
void clear_edges(edges_t *edges);
error_t copy_edges(const edges_t *src, edges_t *dst);

error_t read_edges(FILE *f, edges_t *edges);
error_t write_edges(FILE *f, edges_t *edges);

error_t read_edge(FILE *f, edge_t *edge);
error_t write_edge(FILE *f, edge_t *edge);

#endif // EDGES_H__
