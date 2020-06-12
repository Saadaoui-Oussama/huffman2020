#ifndef TREE_H
#define TREE_H

#include <stdio.h>
#include <stdlib.h>

typedef struct _node
{
    char data;               /* data stored : a letter      */
    struct _node *left;      /* pointer to the left child   */
    struct _node *right;     /* pointer to the right child  */
    int priority;            /* priority in the prioqueue   */
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

node *huffman(int tab_occurences[], int length);

void write_huffman(node *t, FILE *sortie);

void free_tree(node *t);

void free_code_table(char** code_table, int length);

node *scan_tree_decod(FILE *fptr);

char get_translation(node *t, FILE* f);

void decodage(node *t, FILE* entree, FILE* sortie, int wordlength);

#endif /* TREE_H */
