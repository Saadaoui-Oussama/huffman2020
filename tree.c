#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
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

  printf("%c ",caractere);

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
