#include "list.h"
#include "door_struct.h"

int main() {
    struct door doors[DOORS_COUNT];
    initialize_doors(doors);
    sort(doors);

    struct node* root = init(doors);
    for (int i = DOORS_COUNT; i > 0; i--) {
        root = add_door(root, doors + i);
    }
    if (root == NULL) {
        printf("FAIL\n");
    } else {
        printf("SUCCESS\n");
    }
    struct node* elem = find_door(5, root);
    if (elem == NULL) {
        printf("FAIL\n");
    } else {
        root = remove_door(elem, root);
        if (root == NULL) {
            printf("FAIL\n");
        } else {
            printf("SUCCESS\n");
        }
    }
    return 0;
}
