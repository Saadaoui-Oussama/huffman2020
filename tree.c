#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "prioqueue.h"

/*----------------------------------------------------------------------------*/

node *create_node(char data)
{
  node *n = (node *)malloc(sizeof(node));
  assert(n != NULL);
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  n->priority = 0;
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

char **create_code_tab(int length)
{
  char **code_tab = malloc(length*sizeof(char*));
  int i;
  for (i = 0; i < length; i++) {
    code_tab[i] = (char*) malloc(length*sizeof(char));
  }

  return code_tab;
}

/*----------------------------------------------------------------------------*/
void fill_code_tab(node *t, char* str, int str_pos, char** code_table) 
{
  if (t->left == NULL && t->right == NULL)  /* On est sur la feuille */
  {
    strcpy(code_table[(unsigned char)t->data], str);
  }

  if (t->left != NULL) 
  {
    str[str_pos] = '0';
    str[str_pos+1] = '\0';
    fill_code_tab(t->left, str, str_pos+1, code_table);
  }
  
  if (t->right != NULL) 
  {
    str[str_pos] = '1';
    str[str_pos+1] = '\0';
    fill_code_tab(t->right, str, str_pos+1, code_table);
  }
  
}

/*----------------------------------------------------------------------------*/

void encodage(FILE *entree, FILE* sortie, char** code_table) 
{
  /*Remet le curseur de lecture à l'état 0 pour relire le fichier (on s'assure que l'on va bien lire le début du fichier)*/
  rewind(entree);

  int i = 0;

  /*Compte le nombre de caractere*/
  while (fgetc(entree) != EOF)
  {
    i++;
  }

  /*Création d'un tableau de 100 caractere, pour stocker la conversion : (int) nombre -> (char*) nombre */
  char str[100];
  sprintf(str, "%d", i);
  
  /*Insere le nombre de caractere*/
  fputs(str, sortie);
  fputs("\n", sortie);
  
  /*Remet le curseur de lecture à l'état 0 pour relire le fichier*/
  rewind(entree);

  /*Lis chaque caractere puis place son code ASCII dans code_table qui renvoie la valeur binaire contenu à cette position*/
  char c;
  while ((c = fgetc(entree)) != EOF)
  {
    fputs(code_table[(unsigned char) c], sortie);
    fputs(" ", sortie);
  }

}

/*----------------------------------------------------------------------------*/


void occurences(FILE *entree, int tab_occurences[], int length)
{
  /*Remet le curseur de lecture à l'état 0 pour relire le fichier (on s'assure que l'on va bien lire le début du fichier)*/
  rewind(entree);

  char caractere;

  while ((caractere = fgetc(entree)) != EOF)
  {
    tab_occurences[ (unsigned char) caractere ]++;  

  }

  /*Remet le curseur de lecture à l'état 0 pour relire le fichier (si on le réeutilise)*/
  rewind(entree);

  /*Permet de vérifier le nombre d'occurences*/
  /*
  int i = 0;
  for (i = 0; i < length-1; i++)
  {
    if(tab_occurences[i] != 0)
    {
      printf("occurences | %c : %d\n",(char) i,tab_occurences[ i ]);  
      caractere = fgetc(entree);
    }
  }
  */

}

/*----------------------------------------------------------------------------*/

node *huffman(int tab_occurences[], int length) {
  prioqueue *pq = create_pq();

  int i = 0;
  node *t = NULL;

  for (i = 0; i < length-1; i++)
  {            
      if (tab_occurences[i] > 0)
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
      t->left = t3;
      t->right = t2;

      insert_pq(pq, t);
  }

  t = remove_min_pq(pq);
  free_pq(pq);
  return t;
}

/*----------------------------------------------------------------------------*/

void write_huffman(node *t, FILE *sortie){
  if (t != NULL) {
    if (t->left != NULL){
      fputs("1", sortie);
      write_huffman(t->left, sortie);
      write_huffman(t->right, sortie);
    }
    else {
      fputs("0", sortie);
      fputc(t->data, sortie);
    }
  }
}

/*----------------------------------------------------------------------------*/

FILE* open_file(char *path, char* mode)
{
  FILE *f = fopen(path, mode);

    if ( f == NULL )
    {
        fprintf(stderr,"Erreur d'ouverture du fichier: %s introuvable\n", path);
        exit(EXIT_FAILURE);
    }

    printf("Vous avez ouvert %s en mode %s\n",path,mode);

    return f;
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

/*----------------------------------------------------------------------------*/

void free_code_table(char** code_table, int length)
{
  int i;
  for(i = 0; i < length; i++)  /* taille code_table */
  {
    free(code_table[i]);
  }

  free(code_table);
}

