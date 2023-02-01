#include "stack.h"

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);

    struct stack_str* root = init(doors);
    for (int i = DOORS_COUNT; i > 0; i--) {
        root = push(root, doors + i);
    }
    root = push(root, doors);
    if (root == NULL) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }
    root = pop(root);
    if (root == NULL) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }
    return 0;
}
