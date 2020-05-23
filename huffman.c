#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "visualtree.h"



int main(int argc, char **argv)
{
    if (argc < 2) 
    {
        printf("Nombre d'arguments incorrect\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) 
    {
        printf("Fichier %s introuvable\n", argv[1]);
        return -1;
    }
    
    

    return 0;
}

