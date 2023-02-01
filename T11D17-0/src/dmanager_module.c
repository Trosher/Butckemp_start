#include "door_struct.h"

#ifdef door_struct
int main() {
    struct door doors[DOORS_COUNT];

    initialize_doors(doors);
    sort(doors);
    output(doors);

    return 0;
}
#endif

void initialize_doors(struct door* doors) {
    srand(time(0));

    int seed = rand() % MAX_ID_SEED;
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].id = (i + seed) % DOORS_COUNT;
        doors[i].status = rand() % 2;
    }
}

void sort(struct door* doors) {
    int bufer;
    int target = 0;
    for (int i = 1; i < DOORS_COUNT; i++) {
        if (doors[i].id < doors[i - 1].id) {
            bufer = doors[i].id;
            doors[i].id = doors[i - 1].id;
            doors[i - 1].id = bufer;
            target = 1;
        }
        if (i < DOORS_COUNT - 1) {
            if (doors[i].id > doors[i + 1].id) {
                bufer = doors[i].id;
                doors[i].id = doors[i + 1].id;
                doors[i + 1].id = bufer;
                target = 1;
            }
        }
        if (target == 1) {
            i = 0;
            target = 0;
        }
    }
}

void output(struct door* doors) {
    for (int i = 0; i < DOORS_COUNT; i++) {
        doors[i].status = 0;
        printf("%d ", doors[i].id);
        if (i < DOORS_COUNT - 1) {
            printf("%d\n", doors[i].status);
        } else {
            printf("%d", doors[i].status);
        }
    }
}
