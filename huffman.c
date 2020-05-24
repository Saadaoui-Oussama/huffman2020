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

    FILE *fptr = fopen(argv[1], "r");

    if ( fptr == NULL )
    {
        fprintf(stderr,"File openning failed");
        exit(EXIT_FAILURE);
    }
     
    write_tree( scan_tree(fptr) );


    
        
    fclose(fptr);

    return 0;
}

