#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "visualtree.h"
#include "prioqueue.h"

int main(int argc, char **argv)
{
    if (argc < 3) 
    {
        fprintf(stderr, "Nombre d'arguments attendu : 2 (fichier de création du dictionnaire et fichier de données de l'arbre)\n"); /* ascii/2.1.txt ascii/2.3.txt */
        exit(EXIT_FAILURE);
    }

    /*--------------------2.1----------------------------------*/

    FILE *fptr = open_file(argv[1], "r"); /*fopen(argv[1], "r");*/ 

    node *tree = scan_tree(fptr);
    write_tree(tree);

    fclose(fptr);
    printf("Fermeture du fichier %s\n",argv[1]);
    
   /*--------------------2.2----------------------------------*/
    int length = 256;
    char **code_table = create_code_tab(length);
    char *str = malloc(length*sizeof(char)); /* On stockera les chemins dans cette chaine */ /*ATTENTION SUR L ALLOCATION*/
    strcpy(str, "");
  
    fill_code_tab(tree, str, 0, code_table);
    /*free(str);*/

    /*--------------------2.3----------------------------------*/

    FILE *entree = open_file(argv[2], "r"); /*fopen(argv[2], "r");*/
    FILE *sortie = open_file("fichier_de_sortie.txt", "w");  /*fopen("fichier_de_sortie.txt", "w");*/   

    encodage(entree, sortie, code_table);

    /*--------------------3.1----------------------------------*/

    /*
    int tab_occurences[256] = {0};
    occurences(entree,  tab_occurences, length);
    */
    /*--------------------3.2----------------------------------*/
    /*
    prioqueue *pq = create_pq();
    
    rewind(entree);

    int i = 0;
    node *t = NULL;

    for (i = 0; i < length-1; i++)
    {            
        if (tab_occurences[i] != 0)
        {
            t = create_node( (char) i );
            t->priority = tab_occurences[i];

             insert_pq(pq, t);
        }
    }
    
    node *t2 = NULL;
    node *t3 = NULL;

    while( size_pq(pq) >= 2 )
    {
        t2 = remove_min_pq(pq);
        t3 = remove_min_pq(pq);

        t = create_node( tab_occurences[ (unsigned char) t2->data] + tab_occurences[ (unsigned char) t3->data] );
        t->left = t2;
        t->right = t3;

        insert_pq(pq, t);
    }

    t = remove_min_pq(pq);

    */
    /*free_pq(pq);*/
    

    /*--------------------FIN----------------------------------*/

    fclose(sortie);
    printf("\nfermeture du fichier de sortie\n");

    fclose(entree);
    printf("\nfermeture de %s\n",argv[2]);

    free(str);
    
    free_code_table(code_table, length);

    free_tree(tree);

    return 0;
}

