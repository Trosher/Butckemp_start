#include "bst.h"

int main() {
    int key = 30;
    node* root = NULL;
    root = bstree_create_node(root, key);
    if (root != NULL) {
        printf("SUCCESS\n");
    } else {
        printf("FAIL\n");
    }
    return 0;
}
