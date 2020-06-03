#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    char data;                /* data stored : an integer    */
    struct _node *left;      /* pointer to the left child   */
    struct _node *right;     /* pointer to the right child  */
    int priority; /* priority in the prioqueue  */
} node;

/*
 * Allocate memory for a new node.
 */
node *create_node(char data);

node *scan_tree(FILE *fptr);

char **create_code_tab(int length);

void fill_code_tab(node *t, char* str, int str_pos, char** code_table);

void encodage(FILE *entree, FILE* sortie, char** code_table);

FILE* open_file(char *path, char* mode);

void occurences(FILE *entree, int tab_occurences[], int length);

void free_tree(node *t);

void free_code_table(char** code_table, int length);



#endif /* TREE_H */
