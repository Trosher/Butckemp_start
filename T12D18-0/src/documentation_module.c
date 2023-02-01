#include "documentation_module.h"

int validate(char* data) {
    int validation_result = !strcmp(data, Available_document);
    return validation_result;
}

void check_available_documentation_module(int (*validate)(char*), int document_count, ...) {
    va_list args;
    if (document_count > 16) { document_count = 16; }
    va_start(args, document_count);
    int mas;
    for (int i = 0; i < document_count; i++) {
        char *value = va_arg(args, char*);
        mas = validate(value);
        printf("%s : ", value);
        if (mas == 1) { printf("available");
        } else { printf("unavailable"); }
        if (i < document_count - 1) { printf("\n"); }
    }
    va_end(args);
}
