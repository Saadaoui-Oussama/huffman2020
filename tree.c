#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

node *create_node(int data) {
  node *n = (node *)malloc(sizeof(node));
  assert(n != NULL);
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void display_prefix(node *t) {
  if (t != NULL) {
    printf("%d ", t->data);
    display_prefix(t->left);
    display_prefix(t->right);
  }
}

void display_infix(node *t) {
  if (t != NULL) {
    display_infix(t->left);
    printf("%d ", t->data);
    display_infix(t->right);
  }
}

void display_suffix(node *t) {
  if (t != NULL) {
    display_suffix(t->left);
    display_suffix(t->right);
    printf("%d ", t->data);
  }
}

node *scan_tree(void) {
  node *t = NULL;
  int input;

  scanf("%d", &input);

  if (input == 0)
    return NULL;
  else {
    t = create_node(input);
    t->left = scan_tree();
    t->right = scan_tree();
  }

  return t;
}

int count_nodes(node *t) {
  int count = 0;

  if (t != NULL) {
    count++;
    count += count_nodes(t->left);
    count += count_nodes(t->right);
  }

  return count;
}

int count_leaves(node *t) {
  int count = 0;

  if (t == NULL)
    return 0;

  if (t->left == NULL && t->right == NULL)
    count++;

  count += count_leaves(t->left);
  count += count_leaves(t->right);

  return count;
}

int count_only_children(node *t) {
  int count = 0;
  if (t == NULL) 
    return 0;

  else if( (t->left != NULL && t->right == NULL) || (t->right != NULL && t->left == NULL) )
    count++;

  count += count_only_children(t->left);
  count += count_only_children(t->right);

  return count;
}

int height(node *t) {
  int h1 = 0;
  int h2 = 0;

  if (t == NULL)
    return 0;

  if (t->left != NULL)
    h1++;

  if (t->right != NULL)
    h2++;

  h1 += height(t->left);
  h2 += height(t->right);

  if (h1 >= h2)
    return h1;
  else
    return h2;

}

node *find_bst(node *t, int elt) {
  if (t == NULL || t->data == elt)
    return t;
  else if (t->data > elt)
    return find_bst(t->left, elt);
  else
    return find_bst(t->right, elt);
}

node *insert_bst(node *t, int elt) {
  if (t == NULL)
    t = create_node(elt);

  else if (t->data > elt)
    t->left = insert_bst(t->left, elt);

  else if (t->data < elt)
    t->right = insert_bst(t->right, elt);
  
  return t;
}

node *random_tree(int n) {
  node *t = create_node(rand()%(n*2));
  printf("%d\n", t->data);
  while (count_nodes(t) != n)
    insert_bst(t, rand()%(n*2));
  return t;
}

node *extract_min_bst(node *t, node **min) {
  /* utiliser min ? */
  while (t != NULL && t->left != NULL)
    t = t->left;
  *min = t;

  if (t != NULL)
    t = t->right;
  else
    t = NULL;

  return *min;
}

node *remove_bst(node *t, int elt) {
  /* TODO */
  return t;
}

void free_tree(node *t) {
  if (t != NULL) {
    free_tree(t->left);
    free_tree(t->right);
    free(t);
  }
}
#include "tree.h"
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

node *create_node(int data) {
  node *n = (node *)malloc(sizeof(node));
  assert(n != NULL);
  n->data = data;
  n->left = NULL;
  n->right = NULL;
  return n;
}

void display_prefix(node *t) {
  if (t != NULL) {
    printf("%d ", t->data);
    display_prefix(t->left);
    display_prefix(t->right);
  }
}

void display_infix(node *t) {
  if (t != NULL) {
    display_infix(t->left);
    printf("%d ", t->data);
    display_infix(t->right);
  }
}

void display_suffix(node *t) {
  if (t != NULL) {
    display_suffix(t->left);
    display_suffix(t->right);
    printf("%d ", t->data);
  }
}

node *scan_tree(void) {
  node *t = NULL;
  int input;

  scanf("%d", &input);

  if (input == 0)
    return NULL;
  else {
    t = create_node(input);
    t->left = scan_tree();
    t->right = scan_tree();
  }

  return t;
}

int count_nodes(node *t) {
  int count = 0;

  if (t != NULL) {
    count++;
    count += count_nodes(t->left);
    count += count_nodes(t->right);
  }

  return count;
}

int count_leaves(node *t) {
  int count = 0;

  if (t == NULL)
    return 0;

  if (t->left == NULL && t->right == NULL)
    count++;

  count += count_leaves(t->left);
  count += count_leaves(t->right);

  return count;
}

int count_only_children(node *t) {
  int count = 0;
  if (t == NULL) 
    return 0;

  else if( (t->left != NULL && t->right == NULL) || (t->right != NULL && t->left == NULL) )
    count++;

  count += count_only_children(t->left);
  count += count_only_children(t->right);

  return count;
}

int height(node *t) {
  int h1 = 0;
  int h2 = 0;

  if (t == NULL)
    return 0;

  if (t->left != NULL)
    h1++;

  if (t->right != NULL)
    h2++;

  h1 += height(t->left);
  h2 += height(t->right);

  if (h1 >= h2)
    return h1;
  else
    return h2;

}

node *find_bst(node *t, int elt) {
  if (t == NULL || t->data == elt)
    return t;
  else if (t->data > elt)
    return find_bst(t->left, elt);
  else
    return find_bst(t->right, elt);
}

node *insert_bst(node *t, int elt) {
  if (t == NULL)
    t = create_node(elt);

  else if (t->data > elt)
    t->left = insert_bst(t->left, elt);

  else if (t->data < elt)
    t->right = insert_bst(t->right, elt);
  
  return t;
}

node *random_tree(int n) {
  node *t = create_node(rand()%(n*2));
  printf("%d\n", t->data);
  while (count_nodes(t) != n)
    insert_bst(t, rand()%(n*2));
  return t;
}

node *extract_min_bst(node *t, node **min) {
  /* utiliser min ? */
  while (t != NULL && t->left != NULL)
    t = t->left;
  *min = t;

  if (t != NULL)
    t = t->right;
  else
    t = NULL;

  return *min;
}

node *remove_bst(node *t, int elt) {
  /* TODO */
  return t;
}

void free_tree(node *t) {
  if (t != NULL) {
    free_tree(t->left);
    free_tree(t->right);
    free(t);
  }
}
