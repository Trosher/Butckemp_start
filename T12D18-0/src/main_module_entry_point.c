#include <stdio.h>
#include <time.h>
#include "print_module.h"
#include "documentation_module.h"

int main() {
#ifdef print_module
    struct tm *u;
    char s[11];
    const time_t timer = time(NULL);
    u = localtime(&timer);
    strftime(s, 10, " %H:%M:%S ", u);

    print_log(print_char, Log_prefix);
    print_log(print_char, s);
    print_log(print_char, Module_load_success_message);
#endif

#ifdef documentation_module
    check_available_documentation_module(validate, Documents_count, Documents);
#endif
    return 0;
}
