#include "bst.h"

node *bstree_create_node(node *root, int key) {
    node *tmp = malloc(sizeof(node));
    tmp -> key = key;
    tmp -> parent = NULL;
    tmp -> left = tmp -> right = NULL;
    root = tmp;
    return root;
}

node *bstree_insert(node *root, int key) {
    node *root2 = root, *root3 = NULL;
    node *tmp = malloc(sizeof(node));
    tmp -> key = key;
    while (root2 != NULL) {
        root3 = root2;
        if (key < root2 -> key) {
            root2 = root2 -> left;
        } else { root2 = root2 -> right; }
    }
    tmp -> parent = root3;
    tmp -> left = NULL;
    tmp -> right = NULL;
    if (key < root3 -> key) { root3 -> left = tmp;
    } else { root3 -> right = tmp; }
    return root;
}

node *search(node * root, int key) {
    if ((root == NULL) || (root -> key == key))
        return root;
    if (key < root -> key) { return search(root -> left, key);
    }  else { return search(root -> right, key); }
}
