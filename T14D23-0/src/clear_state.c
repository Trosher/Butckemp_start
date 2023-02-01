#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void print_bf(int *name_data1, int *name_data2, char *name);

int main() {
char *name = malloc(sizeof(char));
scanf("%s", name);
int name_data1[3];
int name_data2[3];
if ((scanf("%d.%d.%d", &name_data1[2], &name_data1[1], &name_data1[0]) == 3) && \
    scanf("%d.%d.%d", &name_data2[2], &name_data2[1], &name_data2[0]) == 3) {
    print_bf(name_data1, name_data2, name);
} else {
    printf("n/a");
}
free(name);
}

void print_bf(int *name_data1, int *name_data2, char *name) {
    FILE *fp = fopen(name, "rb");
    char *name_copy = malloc(sizeof(char));
    strcat(name_copy, "_copy");
    if (fp != NULL) {
        FILE *fp_copy = fopen(name_copy, "ab");
        int flag = 1, s[8];
        while (fread(s, sizeof(int), 8, fp) == 8) {
            if (flag == 1 || flag == -1) {
                fwrite(s, sizeof(int), 8, fp_copy);
            }
            if (s[0] >= name_data1[0] && s[1] >= name_data1[1] && s[2] >= name_data1[2] && flag == 1) {
                flag -= 1;
            } else if (s[0] >= name_data2[0] && s[1] >= name_data2[1] && s[2] >= name_data2[2] && flag == 0) {
                flag -= 1;
            }
        }
        if (flag != -1) { printf("n/a");
            fclose(fp_copy);
            remove(name_copy);
            fclose(fp);
        } else {
            fclose(fp_copy);
            fclose(fp);
            rename(name_copy, name);
        }
    } else {
        printf("n/a");
    }
}
