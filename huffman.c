#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tree.h"
#include "visualtree.h"

list *occurence(FILE *file){
  if(file == NULL){
    fprintf(stderr, "Error opening file for reading.\n");
    return NULL;
  }
  char *word = (char *)malloc((21)*sizeof(char));
  list *lst = create_list();
  int i = 0;
  char str[2];
  while(!feof(file)){
    fgets(word, 20, file);
    for(i = 0;i<strlen(word);i++){
      str[0] = word[i];
      str[1] = '\0';
      lst = insert_list(lst, str);      
    }
  }
  free(word);
  return lst;
}

int main(int argc, char **argv){
    if (argc < 2) {
        printf("Nombre d'arguments incorrect\n");
        return -1;
    }

    FILE *file = fopen(argv[1], "r");
    if (file == NULL) {
        printf("Fichier %s introuvable\n", argv[1]);
        return -1;
    }
    
    /* Array of value of each charactere from the ascii table */
    char **code_table = (char **)malloc(256*sizeof(char*));  

    return 0;
}

