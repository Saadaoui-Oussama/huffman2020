#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "visualtree.h"
#include "prioqueue.h"

const int LENGTH = 256;

int main(int argc, char **argv)
{
    /*--------------------4.1----------------------------------*/

    if (argc < 2) 
    {
        fprintf(stderr, "Nombre d'arguments attendu : 1 (fichier à encoder/décoder)\n");
        exit(EXIT_FAILURE);
    }

    FILE *entree = open_file(argv[1], "r");

    FILE *encod = open_file("encodage.txt", "w+");

    int tab_occurences[256] = {0}; /* on ne peut pas mettre LENGTH: a regler */
    occurences(entree, tab_occurences, LENGTH);

    node *huff = huffman(tab_occurences, LENGTH);
    write_huffman(huff, encod);

    rewind(encod);
    node *tree = scan_tree(encod);
    fputs("\n", encod);

    write_tree(tree);



    char **code_table = create_code_tab(LENGTH);
    char *str = malloc(LENGTH*sizeof(char)); /* On stockera les chemins dans cette chaine */ /*ATTENTION SUR L ALLOCATION*/
    strcpy(str, "");
    fill_code_tab(tree, str, 0, code_table);


    encodage(entree, encod, code_table);

    write_tree(huff);



    /*--------------------4.2----------------------------------*/

    /*--------------------FIN----------------------------------*/
    fclose(encod);
    fclose(entree);

    free(tree);
    free(huff);
    free_code_table(code_table, LENGTH);
    free(str);

    return 0;
}

