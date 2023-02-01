#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <string.h>
#ifdef loggin_cipher
#include "logger.h"
#endif

void menu();
int read(FILE* log_file, char *file_name, FILE *file, int options);
int output_in_file(FILE* log_file, char *file_name, FILE *file, int options);
void coder(FILE* log_file, char *dir, char *file_name, int *options, int push);
int shifr_salat(FILE* log_file, int options);
int shift_left_rith(int push);
int shift_input(FILE* log_file, int *push);


int main() {
    menu();
    return 0;
}

void menu() {
    #ifdef cipher
    FILE *log_file = NULL;
    #endif
    #ifdef loggin_cipher
    char *log_file_name = calloc(1, sizeof(char));
    scanf("%s", log_file_name);
    FILE *log_file = log_init("log_file_name");
    free(log_file_name);
    #endif
    FILE *file = NULL;
    char *file_name = calloc(1, sizeof(char));
    int options = 0;
    char c;
    while (options != -1) {
        if (scanf("%d%c", &options, &c) == 2 && (c != '\n' || c != EOF) \
            && (options == 3 || options == 2 || options == 1 || options == -1)) {
            switch (options) {
                case 1: options = read(log_file, file_name, file, options);
                    break;
                case 2: options = output_in_file(log_file, file_name, file, options);
                    break;
                case 3: options = shifr_salat(log_file, options);
                    break;
                case -1: options = -1;
                    break;
            }
        } else { printf("n/a\n");
            #ifdef loggin_cipher
            logcat(log_file, "Невалидный ввод данных", "WARNING");
            #endif
            if (freopen("/dev/tty", "r", stdin) == NULL) { options = 0; } }
    }
    free(file_name);
    free(file);
}

int read(FILE* log_file, char *file_name, FILE *file, int options) {
    if (log_file) {;}
    char *line = calloc(1, sizeof(char));
    if (scanf("%s", file_name) == 0) {
        #ifdef loggin_cipher
        logcat(log_file, "Запись не удалось произвести", "ERROR");
        #endif
        options = 0;
    }
    file = fopen(file_name, "r");
    if (file == NULL) {
        options = 0;
        #ifdef loggin_cipher
        logcat(log_file, "Фаил ненайден", "INFO");
        #endif
        printf("n/a\n");
    } else if (options != 0) {
        fgets(line, 255, file);
        printf("%s\n", line);
        options = 0;
    }
    free(line);
    fclose(file);
    return options;
}

int output_in_file(FILE* log_file, char *file_name, FILE *file, int options) {
    if (log_file) {;}
    char aga[1000];
    int i = 0;
    file = fopen(file_name, "a");
    if (file == NULL) {
        #ifdef loggin_cipher
        logcat(log_file, "Фаил ненайден", "INFO");
        #endif
        options = 0;
    } else {
        scanf("%c", &aga[i]);
        while (aga[i] != '\n' && aga[i] != EOF) {
            i++;
            scanf("%c", &aga[i]);
        }
        fprintf(file, "%s", aga);
        fclose(file);
        options = 1;
    }
    return options;
}

int shifr_salat(FILE* log_file, int options) {
    if (log_file) {;}
    char dir_name[500];
    char path[500];
    int push;
    if (scanf("%s", dir_name) == 0) {
        #ifdef loggin_cipher
        logcat(log_file, "Запись не удалось произвести", "ERROR");
        #endif
        options = 0;
    }
    DIR *d;
    struct dirent *dir;
    d = opendir(dir_name);
    if (d) {
        options = shift_input(log_file, &push);
        while ((dir = readdir(d)) != NULL && options != 0) {
            if ((strlen(dir->d_name) >= 2) && \
                strcmp(&(dir->d_name[strlen(dir->d_name) - 2]), ".c") == 0) {
                coder(log_file, dir_name, dir->d_name, &options, push);
            } else if ((strlen(dir->d_name) >= 2) && \
                        strcmp(&(dir->d_name[strlen(dir->d_name) - 2]), ".h") == 0) {
                strcat(path, dir_name);
                strcat(path, "/");
                strcat(path, dir->d_name);
                FILE *file = fopen(path, "w");
                fclose(file);
                memset(path, 0, 500);
            }
        }
    } else {
        #ifdef loggin_cipher
        logcat(log_file, "Папка не была найдена", "INFO");
        #endif
        options = 0;
    }
    closedir(d);
    return options;
}

void coder(FILE* log_file, char *dir, char *file_name, int *options, int push) {
    char path1[500], path2[500], c;
    path1[0] = 0;
    path2[0] = 0;
    strcat(path1, dir);
    strcat(path1, "/");
    strcat(path1, file_name);
    strcat(path2, dir);
    strcat(path2, "/salat.c");
    FILE *file1 = fopen(path1, "r");
    FILE *file2 = fopen(path2, "w");
    if (file1 != NULL && file2 != NULL) {
        c = getc(file1);
        while (!feof(file1)) {
            if (shift_left_rith(push) == 2) {
                if (c + push >= 0 && (c != '\n')) {
                    c += push;
                } else if (c != '\n') {
                    c = c + push + 255;
                }
                fprintf(file2, "%c", c);
                c = getc(file1);
            } else if (shift_left_rith(push) == 1) {
                if (c + push <= 255 && (c != '\n')) {
                    c += push;
                } else if (c != '\n') {
                    c = c + push - 255;
                }
                fprintf(file2, "%c", c);
                c = getc(file1);
            } else { break; }
        }
    } else {
        #ifdef loggin_cipher
        logcat(log_file, "Папка не была найдена", "INFO");
        #endif
        options = 0;
    }
    fclose(file1);
    fclose(file2);
    rename(path2, path1);
}

int shift_left_rith(int push) {
    if (push < 0) {
        return 2;
    } else if (push > 0) {
        return 1;
    }
    return 0;
}

int shift_input(FILE* log_file, int *push) {
    char c;
    int target = 1;
    if (!(scanf("%d%c", push, &c) == 2 && (c != '\n' || c != EOF))) {
        #ifdef loggin_cipher
        logcat(log_file, "Запись не удалось произвести", "ERROR");
        #endif
        target = 0;
    }
    return target;
}
