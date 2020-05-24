#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "visualtree.h"

int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        fprintf(stderr, "Nombre d'arguments incorrect\n");
        exit(EXIT_FAILURE);
    }

    FILE *fptr = fopen(argv[1], "r");

    if ( fptr == NULL )
    {
        fprintf(stderr,"Erreur d'ouverture du fichier: %s introuvable\n", argv[1]);
        exit(EXIT_FAILURE);
    }

    node *t = scan_tree(fptr);
    write_tree(t);

    /* ---------------------------------- */
   
    char *code_table[256]; 
    char* test = ""; /* On stockera les chemins dans cette chaine */

    fill_code_tab(t, test, code_table);

    /*
    char str[] = "abracadabra";
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
    	printf("%s ", code_table[(unsigned char)str[i]]);
    }
    printf("\n");
    */

    /* ---------------------------------- */

    FILE *entree = fopen(argv[2], "r");
    if ( entree == NULL )
    {
        fprintf(stderr,"Erreur d'ouverture du fichier: %s introuvable\n", argv[2]);
        exit(EXIT_FAILURE);
    }

    FILE *sortie = fopen("kurohige.txt", "w"); /* nom de fichier changeable */
    if ( sortie == NULL )
    {
    	fprintf(stderr,"Erreur de création du fichier d'encodage");
        exit(EXIT_FAILURE);
    }

    encodage(entree, sortie, code_table);

    fclose(sortie);
    fclose(entree);
    fclose(fptr);

    return 0;
}

