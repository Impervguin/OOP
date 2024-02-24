#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edges.h"
#include "errs.h"

myerror_t edges_init(edges_t *edges, size_t size)
{
    if (!edges)
        return ERR_NULL_POINTER;
    if (size == 0)
        return ERR_ARGUMENTS;
    
    edge_t *arr = malloc(sizeof(edge_t) * size);
    if (!arr)
        return ERR_MEMORY;
    edges->arr = arr;
    edges->size = size;
    return OK;
}

void clear_edges(edges_t *edges)
{
    if (!edges)
        return;
    if (edges->arr)
    {
        free(edges->arr);
        edges->arr = NULL;
    }
    edges->size = 0;
}
myerror_t copy_edges(const edges_t *src, edges_t *dst)
{
    if (!src || !dst)
        return ERR_NULL_POINTER;
    if (src->arr)
    {
        edge_t *arr = malloc(sizeof(edge_t) * src->size);
        if (!arr)
            return ERR_MEMORY;
        memcpy(arr, src->arr, sizeof(edge_t) * src->size);
        if (dst->arr)
            clear_edges(dst);
        dst->size = src->size;
        dst->arr = arr;
    }
    else
        if (dst->arr)
            clear_edges(dst);
    return OK;
}

myerror_t read_edges(FILE *f, edges_t *edges)
{
    if (!f)
        return ERR_NO_FILE;
    if (!edges)
        return ERR_NULL_POINTER;
    edges_t tmp; 

    size_t num;
    if (fscanf(f, "%zu", &num) != 1)
        return ERR_FILE_FORMAT;
    
    myerror_t err = edges_init(&tmp, num);
    if (err)
        return err;
    
    for (size_t i = 0; i < num && !err; i++)
        err = read_edge(f, &tmp.arr[i]);
    
    if (!err)
        copy_edges(&tmp, edges);
    clear_edges(&tmp);
    return err;
}

myerror_t write_edges(FILE *f, edges_t *edges)
{
    if (!edges)
        return ERR_NULL_POINTER;
    if (!edges->arr && edges->size)
        return ERR_NULL_POINTER;

    if (fprintf(f, "%zu\n", edges->size) < 0)
        return ERR_NO_FILE;

    for (size_t i = 0; i < edges->size; i++)
    {
        myerror_t err = write_edge(f, &edges->arr[i]);
        if (err)
            return err;
    }
    return OK;
}

myerror_t read_edge(FILE *f, edge_t *edge)
{
    if (!f)
        return ERR_NO_FILE;
    if (!edge)
        return ERR_NULL_POINTER;
    
    size_t e1, e2;
    if (fscanf(f, "%zu%zu", &e1, &e2) != 2)
        return ERR_FILE_FORMAT;
    
    if (e1 == 0 || e2 == 0)
        return ERR_FILE_FORMAT;
    
    edge->p1 = e1 - 1;
    edge->p2 = e2 - 1;

    return OK;
}

myerror_t write_edge(FILE *f, edge_t *edge)
{
    if (!f)
        return ERR_NO_FILE;
    if (!edge)
        return ERR_NULL_POINTER;
    
    if (fprintf(f, "%zu %zu\n", edge->p1 + 1, edge->p2 + 1) < 0)
        return ERR_NO_FILE;
    return OK;
}