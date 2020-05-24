#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/*----------------------------------------------------------------------------*/

node *create_node(char data)
{
  node *n = (node *)malloc(sizeof(node));
  assert(n != NULL);
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/*----------------------------------------------------------------------------*/

node *scan_tree(FILE *fptr)
{
  char caractere = fgetc(fptr);

  if (caractere == EOF)
  {
    return NULL;
  }
  
  node *t = NULL;
  
  /*Si on tombe sur un 0, on a forcément un caractère à lire après*/
  if (caractere == '0')
  {
    t = create_node(fgetc(fptr));    
  }
  /*Si on ne tombe pas sur un 0, on est forcément un 1 */
  else
  {
    t = create_node(' ');
    t->left = scan_tree(fptr);
    t->right = scan_tree(fptr);
  }
  
  return t;
}

/*----------------------------------------------------------------------------*/
void fill_code_tab(node *t, char* str, char** code_table) {

  if (t->left == NULL && t->right == NULL) { /* On est sur la feuille */
    code_table[(unsigned char)t->data] = (char *)malloc((strlen(str)+1)*sizeof(char)); /* On alloue de la place pour stocker la chaine */
    strcpy(code_table[(unsigned char)t->data], str);
  }

  if (t->left != NULL) {
    char *gauche = (char *)malloc((strlen(str)+1)*sizeof(char));
    strcpy(gauche, str);
    strcat(gauche, "0"); /* Si on va a gauche dans l'arbre, on met un 0 sur le chemin */
    fill_code_tab(t->left, gauche, code_table);
    free(gauche);
  }
  
  if (t->right != NULL) {
    char *droite = (char *)malloc((strlen(str)+1)*sizeof(char));
    strcpy(droite, str);
    strcat(droite, "1"); /* Si on va a droite, c'est un 1 */
    fill_code_tab(t->right, droite, code_table);
    free(droite);
  }
  
}

/*----------------------------------------------------------------------------*/
void encodage(FILE *entree, FILE* sortie, char** code_table) {
  /*
  int i = 0;
  while (fgetc(entree) != EOF)
    i++;
  */
  char c;
  while ((c = fgetc(entree)) != EOF)
  {
    fputs(code_table[(unsigned char) c], sortie);
    fputs(" ", sortie);
  }
}

/*----------------------------------------------------------------------------*/

void free_tree(node *t)
{
  if(t == NULL)
  {
    return;
  }

	free_tree(t->left);
  free_tree(t->right);
	free(t);
}
