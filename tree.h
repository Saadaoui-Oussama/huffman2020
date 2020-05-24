#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    char data;                /* data stored : an integer    */
    struct _node *left;      /* pointer to the left child   */
    struct _node *right;     /* pointer to the right child  */
} node;

/*
 * Allocate memory for a new node.
 */
node *create_node(char data);

node *scan_tree(FILE *fptr);

void fill_code_tab(node *t, char* str, char** code_table);

void free_tree(node *t);


#endif /* TREE_H */
