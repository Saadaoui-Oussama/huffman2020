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
   
    char **code_table = (char **)malloc(256*sizeof(char*)); 
    char* test = ""; /* On stockera les chemins dans cette chaine */

    fill_code_tab(t, test, code_table);
    printf("BABORD ET TRIBORD\n");

    char str[] = "abracadabra"; /* On peut utiliser n'importe tel mot tant qu'il est composé uniquement de lettres dans l'arbre */
    int i, len = strlen(str);
    for (i = 0; i < len; i++) {
    	printf("%s ", code_table[(unsigned char)str[i]]);
    }
    printf("\n");

    write_tree(t);
        
    fclose(fptr);

    return 0;
}

