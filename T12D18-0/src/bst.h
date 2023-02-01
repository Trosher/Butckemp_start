#ifndef SRC_BST_H_
#define SRC_BST_H_

#include <stdlib.h>
#include <stdio.h>

typedef struct tree {
    int key;
    struct tree *left;
    struct tree *right;
    struct tree *parent;
} node;

node *bstree_create_node(node *root, int key);
node *bstree_insert(node *root, int key);

#endif  // SRC_BST_H_
