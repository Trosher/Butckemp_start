#include "list.h"
#include "door_struct.h"

void destroy(struct node* root) {
    while (root != NULL) {
        struct node *p = root;
        root = root -> next;
        free(p);
    }
}

struct node *init(struct door* door) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp != NULL) {
        tmp -> value = door;
        tmp -> next = NULL;
    }
    return tmp;
}

struct node *add_door(struct node* elem, struct door* door) {
    struct node *tmp = (struct node*)malloc(sizeof(struct node));
    if (tmp != NULL) {
        tmp -> value = door;
        tmp -> next = elem -> next;
        elem -> next = tmp;
    }
    return elem;
}

struct node *find_door(int door_id, struct node* root) {
    if (root != NULL) {
        while (root -> value -> id != door_id && root -> next != NULL) {
            root = root -> next;
        }
        if (root -> value -> id == door_id) {
            return root;
        }
    }
    destroy(root);
    return NULL;
}

struct node *remove_door(struct node* elem, struct node* root) {
    struct node *tmp = root;
    if (root != NULL) {
        if (root == elem) {
            free(root);
            return tmp -> next;
        }
        while (root -> next != elem) {
           root = root -> next;
        }
        root -> next = elem -> next;
        free(elem);
    } else {
        destroy(root);
        return NULL;
    }
    return root;
}
