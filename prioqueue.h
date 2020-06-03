#ifndef PRIOQUEUE_H
#define PRIOQUEUE_H
#include "tree.h"
#include "visualtree.h"

typedef struct _prioqueue prioqueue;

/**
 * Create and return a pointer to a new priority queue.
 */
prioqueue *create_pq();

/**
 * Free the memory associated with a priority queue.
 *
 * This function should be called on an empty queue.
 * It does not free the memory associated with items 
 * that remain in the queue.
 */
void free_pq(prioqueue *q);

/**
 * Return the current size of the priority queue.
 */
int size_pq(prioqueue *q);

/**
 * Insert an node in the priority queue.
 */
void insert_pq(prioqueue *q, node *e);

/**
 * Remove and a return a pointer to the node with the 
 * lowest even time.
 */
node *remove_min_pq(prioqueue *q);

#endif /* PRIOQUEUE_H */