#ifndef SRC_MAIN_EXECUTABLE_MODULE_DATA_PROCESS_H_
#define SRC_MAIN_EXECUTABLE_MODULE_DATA_PROCESS_H_
#include "../data_libs/data_stat.h"
#include "../data_libs/data_io.h"

#define GOLDEN_RATIO 0.666
#define EPS 1E-6

int make_decision(double *data, int x);
int normalization(void *data, int x);
void sort(void *data, int len);

#endif  // SRC_MAIN_EXECUTABLE_MODULE_DATA_PROCESS_H_
