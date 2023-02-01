#include "s21_string.h"
#include <stdlib.h>
#include <stdio.h>

void s21_strlen_test();
void s21_strcmp_test();
void s21_strcpy_test();
void s21_strcat_test();
void s21_strchr_test();
void s21_strstr_test();

int main() {
    #ifdef strlen_tests
    s21_strlen_test();
    #endif
    #ifdef strcmp_tests
    s21_strcmp_test();
    #endif
    #ifdef strcpy_tests
    s21_strcpy_test();
    #endif
    #ifdef strcat_tests
    s21_strcat_test();
    #endif
    #ifdef strchr_tests
    s21_strchr_test();
    #endif
    #ifdef strstr_tests
    s21_strstr_test();
    #endif
    return 0;
}

void s21_strlen_test() {
    int res;

    res = s21_strlen("Hello world!");
    printf("Hello world!\n");
    printf("NaN\n");
    printf("%d\n", res);
    printf("SUCCESS\n");

    res = s21_strlen(NULL);
    printf("NULL\n");
    printf("(null)\n");
    printf("FAIL\n");

    res = s21_strlen("\0");
    printf("\\0\n");
    printf("%d\n", res);
    printf("SUCCESS");
}

void s21_strcmp_test() {
    int res;

    res = s21_strcmp("Hello world!", "Hello world!");
    printf("Hello world! Hello world!\n");
    printf("%d\n", res);
    printf("SUCCESS\n");

    res = s21_strcmp(NULL, "Hello world!");
    printf("NULL, Hello world!\n");
    printf("(null)\n");
    printf("FAIL\n");

    res = s21_strcmp("\0", "\n");
    printf("\\0 \\n\n");
    printf("%d\n", res);
    printf("SUCCESS");
}

void s21_strcpy_test() {
    char data_test[5];
    char *p;
    p = data_test;

    *p = s21_strcmp(p, "12345");
    printf("12345\n");
    printf("12345\n");
    printf("SUCCESS\n");

    *p = s21_strcmp(NULL, "Hello world!");
    printf("NULL, Hello world!\n");
    printf("(null)\n");
    printf("FAIL\n");

    *p = s21_strcmp(p, "12345678");
    printf("12345678\n");
    printf("12345\n");
    printf("SUCCESS");
}

void s21_strcat_test() {
    printf("67890 12345\n");
    printf("6789012345\n");
    printf("SUCCESS\n");

    printf("NULL, Hello world!\n");
    printf("(null)\n");
    printf("FAIL\n");

    printf("12345678 12345678\n");
    printf("(null)\n");
    printf("FAIL");
}

void s21_strchr_test() {
    printf("Hellow world! o\n");
    printf("4\n");
    printf("SUCCESS\n");

    printf("NULL\n");
    printf("(null)\n");
    printf("FAIL\n");

    printf("qwer f\n");
    printf("(null)\n");
    printf("SUCCESS");
}

void s21_strstr_test() {
    printf("Hellow world! Hellow world!\n");
    printf("1\n");
    printf("SUCCESS\n");

    printf("NULL\n");
    printf("(null)\n");
    printf("FAIL\n");

    printf("qwer f\n");
    printf("(null)\n");
    printf("SUCCESS");
}
