#include <stdio.h>
#include <time.h>
#include "print_module.h"
#include "documentation_module.h"

char print_char(char ch)  {
    return putchar(ch);
}

void print_log(char (*print)(char), char *message) {
    while (*message) {
        print(*message);
        message++;
    }
}
