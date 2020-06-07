#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "visualtree.h"
#include "prioqueue.h"

/* Contient les anciens exercices */

int main(int argc, char const *argv[])
{
    if (argc < 3) 
    {
        fprintf(stderr, "Nombre d'arguments attendu : 2 (fichier de création du dictionnaire et fichier de données de l'arbre)\n"); /* ascii/2.1.txt ascii/2.3.txt */
        exit(EXIT_FAILURE);
    }

    /*--------------------2.1----------------------------------*/

    FILE *fptr = open_file(argv[1], "r"); /*fopen(argv[1], "r");*/ 

    node *tree = scan_tree(fptr);
    /*write_tree(tree);*/

    fclose(fptr);
    printf("Fermeture du fichier %s\n",argv[1]);
    
   /*--------------------2.2----------------------------------*/
    int length = 256;
    char **code_table = create_code_tab(length);
    char *str = malloc(length*sizeof(char)); /* On stockera les chemins dans cette chaine */ /*ATTENTION SUR L ALLOCATION*/
    strcpy(str, "");
  
    fill_code_tab(tree, str, 0, code_table);

    /*--------------------2.3----------------------------------*/

    FILE *entree = open_file(argv[2], "r"); /*fopen(argv[2], "r");*/
    FILE *sortie = open_file("fichier_de_sortie.txt", "w");  /*fopen("fichier_de_sortie.txt", "w");*/   

    encodage(entree, sortie, code_table);

    /*--------------------3.1----------------------------------*/


    int tab_occurences[256] = {0};
    occurences(entree, tab_occurences, length);
    
    /*--------------------3.2----------------------------------*/
    
    node *t = huffman(entree, tab_occurences, length);

    write_tree(t);


    return 0;
}