#include "visualtree.h"
#include <stdio.h>
#include <stdlib.h>



/*
 * Open a file and start writing the DOT code for a tree.
 * Returns a pointer to the file.
 */
FILE* write_begin(char *name)
{
  FILE *f = fopen(name, "w");
  fprintf(f, "digraph tree {\n");
  fprintf(f, "  splines=false\n");
  fprintf(f, "  node [shape=record,height=.1]\n");
  fprintf(f, "  edge [tailclip=false, arrowtail=dot, dir=both];\n\n");
  return f;
}

/*
 * Write the terminating brace and close the file.
 */
void write_end(FILE *f)
{
  fprintf(f, "\n}\n");
  fclose(f);
}

/*
 * Write the DOT code for a single node n to an open file f.
 */
void write_node(FILE *f, node *n)
{
  fprintf(f, "  n%p [label=\"<left> | <value> %c | <right>\"];\n", n, n->data);
}

/*
 * Write the DOT code declaring a left child of node n to an open file f.
 */
void write_left_link(FILE *f, node *n)
{
  fprintf(f, "  n%p:left:c -> n%p:value;\n", n, n->left);
}

/*
 * Write the DOT code declaring a right child of node n to an open file f.
 */
void write_right_link(FILE *f, node *n)
{
  fprintf(f, "  n%p:right:c -> n%p:value;\n", n, n->right);
}

/*********************************************************/
/*********************************************************/
/*********************************************************/
/*
 * This function currently ignores the tree t and outputs a
 * hard-coded tree instead. REPLACE THE ENTIRE FUNCTION!
*/
void write_tree_aux(FILE *f, node *t)
{
  /*
  node *n0 = create_node(5);
  node *n1 = create_node(7);
  node *n2 = create_node(3);
  node *n3 = create_node(1);

  n0->left = n1;
  n0->right = n2;
  n2->right = n3;

  write_node(f,n0);
  write_left_link(f,n0);
  write_node(f,n1);
  write_right_link(f,n0);
  write_node(f,n2);
  write_right_link(f,n2);
  write_node(f,n3);

  free(n0);
  free(n1);
  free(n2);
  free(n3);
  */
  if(t == NULL)
  {
    return;
  }

  write_node(f,t);

  write_tree_aux(f,t->left);

  if(t->left != NULL)
  {
     write_left_link(f,t);
  }

  write_tree_aux(f,t->right);
  
  if(t->right != NULL)
  {
     write_right_link(f,t);
  }





  /* **** */

}
/*********************************************************/
/*********************************************************/
/*********************************************************/

/*
 * Open a file current-tree.dot, write the DOT code for a tree t,
 * and convert the .dot-file to a pdf.
 */
void write_tree(node *t)
{
  FILE *f;
  f = write_begin("current-tree.dot");
  write_tree_aux(f, t);
  write_end(f);
  system("dot -Tpdf current-tree.dot > current-tree.pdf");
}
