#ifndef SRC_DOOR_STRUCT_H_
#define SRC_DOOR_STRUCT_H_
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DOORS_COUNT 15
#define MAX_ID_SEED 10000

struct door {
    int id;
    int status;
};

void output(struct door* doors);
void initialize_doors(struct door* doors);
void sort(struct door* doors);

#endif  // SRC_DOOR_STRUCT_H_
