#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

/*----------------------------------------------------------------------------*/

node *create_node(int data)
{
  node *n = (node *)malloc(sizeof(node));
  assert(n != NULL);
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

/*----------------------------------------------------------------------------*/

void display_prefix(node *t)
{
  if(t == NULL)
  {
    return;
  }
  printf("%d ",t->data);
  display_prefix(t->left);
  display_prefix(t->right);
}

/*----------------------------------------------------------------------------*/

void display_infix(node *t)
{
  if(t == NULL)
  {
    return;
  }

  display_infix(t->left);
  printf("%d ",t->data);
  display_infix(t->right);
}

/*----------------------------------------------------------------------------*/

void display_suffix(node *t)
{
  if(t == NULL)
  {
    return;
  }

  display_suffix(t->left);
  display_suffix(t->right);
  printf("%d ",t->data);
}

/*----------------------------------------------------------------------------*/

node *scan_tree(void)
{
  node *t = NULL;
  int nbr;

  scanf("%d",&nbr);

  if(nbr == 0)
  {
    return NULL;
  }

  else
  {
    t = create_node(nbr);
    t->left = scan_tree();
    t->right = scan_tree();
  }

  return t;
}

/*----------------------------------------------------------------------------*/

int count_nodes(node *t)
{
	int count = 0;

	if(t == NULL)
  {
		return 0;
	}

	count++;
	count += count_nodes(t->left);
	count += count_nodes(t->right);

	return count;
}

/*----------------------------------------------------------------------------*/

int count_leaves(node *t)
{
	int count = 0;

  if(t == NULL)
  {
		return 0;
	}
	else if(t->left == NULL && t->right == NULL)
  {
		count++;
	}

	count += count_leaves(t->left);
	count += count_leaves(t->right);

	return count;
}

/*----------------------------------------------------------------------------*/

int count_only_children(node *t)
{
	int count = 0;
	if(t == NULL)
  {
		return 0;
	}
	else if( (t->left != NULL && t->right == NULL) || (t->right != NULL && t->left == NULL) )
  {
		count++;
	}

	count += count_only_children(t->left);
	count += count_only_children(t->right);

	return count;
}

/*----------------------------------------------------------------------------*/

int height(node *t)
{
	int h1 = 0;
	int h2 = 0;

	if(t == NULL)
  {
		return 0;
	}

  if(t->left != NULL)
  {
    h1++;
  }

	if(t->right != NULL)
  {
		h2++;
	}

  h1 += height(t->left);
	h2 += height(t->right);

	if(h1 > h2)
  {
		return h1;
	}
	else
  {
		return h2;
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
