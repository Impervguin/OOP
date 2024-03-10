#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "edges.h"
#include "errs.h"

void edges_init(edges_t *edges)
{
    if (!edges)
        return;
    
    edges->arr = NULL;
    edges->size = 0;
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

static myerror_t create_edges_array(edge_t **arr, size_t size)
{
    edge_t *new = malloc(sizeof(edge_t) * size);
    if (!new)
        return ERR_MEMORY;
    *arr = new;
    return OK;
}

static void free_edges_array(edge_t *arr)
{
    free(arr);
}

myerror_t alloc_edges(edges_t *edges, size_t size)
{
    if (!edges)
        return ERR_NULL_POINTER;
    if (!size)
        return ERR_RANGE;
    
    if (!edges->arr)
        free_edges_array(edges->arr);
    
    myerror_t err = create_edges_array(&edges->arr, size);
    
    if (!err)
        edges->size = size;
    
    return err;
}

static myerror_t copy_edges_arr(edge_t *arr, const edge_t *src, size_t size)
{
    if (!src || !arr)
        return ERR_NULL_POINTER;
    if (!size)
        return ERR_EMPTY;

    memcpy(arr, src, sizeof(edge_t) * size);

    return OK;
}

myerror_t copy_edges(edges_t *dst, const edges_t *src)
{
    if (!src || !dst)
        return ERR_NULL_POINTER;
    if (!dst->arr || !src->arr)
        return ERR_NULL_POINTER;
    if (dst->size < src->size)
        return ERR_RANGE;
    
    myerror_t err = copy_edges_arr(dst->arr, src->arr, src->size);
    if (!err)
        dst->size = src->size;


    return OK;
}

static myerror_t read_edges_count(size_t *count, FILE *f) {
    if (!f)
        return ERR_NO_FILE;
    
    size_t num;
    if (fscanf(f, "%zu", &num) != 1)
        return ERR_FILE_FORMAT;
    
    *count = num;
    return OK;
}

static myerror_t read_edges_array(edge_t *arr, size_t size, FILE *f)
{
    if (!f)
        return ERR_NO_FILE;
    if (!arr)
        return ERR_NULL_POINTER;

    myerror_t err = OK;

    for (size_t i = 0; !err && i < size; i++)
        err = read_edge(arr + i, f);
    
    return err;
}

myerror_t read_edges(edges_t *edges, FILE *f)
{
    if (!f)
        return ERR_NO_FILE;
    if (!edges)
        return ERR_NULL_POINTER;
    
    myerror_t err = read_edges_count(&edges->size, f);
    
    if (!err)
        err = create_edges_array(&edges->arr ,edges->size);
    
    if (!err)
    {
        err = read_edges_array(edges->arr, edges->size, f);
        if (err)
            free_edges_array(edges->arr);
    }

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

    myerror_t err = OK;
    for (size_t i = 0; !err && i < edges->size; i++)
        err = write_edge(f, edges->arr + i);
    return err;
}

myerror_t read_edge(edge_t *edge, FILE *f)
{
    if (!f)
        return ERR_NO_FILE;
    if (!edge)
        return ERR_NULL_POINTER;
    
    size_t e1, e2;
    if (fscanf(f, "%zu%zu", &e1, &e2) != 2)
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

static myerror_t edge_verify(const edge_t *edge, size_t size)
{
    if (!edge)
        return ERR_NULL_POINTER;
    if (edge->p1 >= size || edge->p2 >= size)
        return ERR_RANGE;
    return OK;
}

myerror_t edges_verify(const edges_t *edges, size_t size)
{
    if (!edges)
        return ERR_NULL_POINTER;
    if (!edges->arr || !edges->size)
        return ERR_EMPTY;
    myerror_t err = OK;
    for (size_t i = 0; !err && i < edges->size; i++)
        err = edge_verify(edges->arr + i, size);
    return err;
}