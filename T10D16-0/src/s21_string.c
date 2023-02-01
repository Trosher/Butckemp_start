#include "s21_string.h"

int s21_strlen(char *data) {
    int len = 0;
    if (!(data == 0)) {
        while (data[len] != '\0') {
            len++;
        }
    } else { len = -1; }
    return len;
}

int s21_strcmp(char *data1, char *data2) {
    int target = 0;
    int i = 0;
    if (data1 == 0 || data2 == 0) {
        target = 2;
    } else if (s21_strlen(data1) != s21_strlen(data2)) {
        target = 1;
    } else {
        while (target == 0 && data1[i] != '\0' && data2[i] != '\0') {
            if (data1[i] != data2[i] != '\0') {
                target  = 1;
            }
            i++;
        }
    }
    return target;
}

char *s21_strcpy(char *dest, char *str) {
    int i;
    i = 0;
    if (dest != 0 || str != 0) {
        while (str[i] && s21_strlen(dest) >= s21_strlen(str)) {
            dest[i] = str[i];
            ++i;
        }
    }
    dest[i] = '\0';
    return dest;
}

char *s21_strcat(char *dest, char *src) {
    int i;
    int j;
    i = 0;
    j = 0;
    while (dest[i] != '\0')
        ++i;
    while (src[j] != '\0') {
        dest[i + j] = src[j];
        ++j;
    }
    dest[i + j] = '\0';
    return (dest);
}

int s21_strchr(char *dest, char c) {
    if (dest != 0) {
        return 1;
    }
    int i = 0;
    while (dest[i]) {
        if (dest[i] == c)
            return i;
        else
            i++;
    }
    return 1;
}

int s21_strstr(char *haystack, char *needle) {
    if ((haystack == 0 || needle == 0) || \
        s21_strlen(haystack) != s21_strlen(needle))
        return 0;
    int i = 0;
    while (haystack[i]) {
        if (haystack[i] == needle[i]) {
        i++;
        } else { return 0; }
    }
    return 1;
}
