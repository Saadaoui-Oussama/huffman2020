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
    node *tree_encod = scan_tree(encod);
    fputs("\n", encod);

    char **code_table_encod = create_code_tab(LENGTH);
    char *str_encod = malloc(LENGTH*sizeof(char)); /* On stockera les chemins dans cette chaine */ /*ATTENTION SUR L ALLOCATION*/
    strcpy(str_encod, "");
    fill_code_tab(tree_encod, str_encod, 0, code_table_encod);

    encodage(entree, encod, code_table_encod);

    write_tree(huff);

    /*--------------------4.2----------------------------------*/

    FILE *decod = open_file("decodage.txt", "w+");
    rewind(encod);

    /* Chaque char* correspond a une ligne du fichier*/
    char second[100]; /* Longueur du fichier */

    node *tree_decod = scan_tree_decod(encod);

    /*write_tree(tree_decod);*/

    char **code_table_decod = create_code_tab(LENGTH);
    char *str_decod = malloc(LENGTH*sizeof(char)); /* On stockera les chemins dans cette chaine */ /*ATTENTION SUR L ALLOCATION*/
    strcpy(str_decod, "");
  
    fill_code_tab(tree_decod, str_decod, 0, code_table_decod);

    fscanf(encod, "%s ", second);
    decodage(tree_decod, encod, decod, atoi(second));


    /*--------------------FIN----------------------------------*/
    fclose(decod);
    fclose(encod);
    fclose(entree);

    free_tree(tree_decod);
    free_code_table(code_table_decod, LENGTH);
    free(str_decod);

    free_tree(tree_encod);
    free_tree(huff);
    free_code_table(code_table_encod, LENGTH);
    free(str_encod);

    return 0;
}

