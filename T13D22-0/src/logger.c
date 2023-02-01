#include "logger.h"

FILE *log_init(char *filename) {
    FILE *log_file;
    log_file = fopen(filename, "a+");
    return log_file;
}

int logcat(FILE* log_file, char *message, char *level) {
    char aga[100];
    struct tm *u;
    char s[11];
    const time_t timer = time(NULL);
    u = localtime(&timer);
    strftime(s, 10, " %H:%M:%S ", u);
    strcat(aga, level);
    strcat(aga, s);
    strcat(aga, message);
    strcat(aga, "\n");
    fprintf(log_file, "%s", aga);
}

int log_close(FILE* log_file) {
    return fclose(log_file);
}
