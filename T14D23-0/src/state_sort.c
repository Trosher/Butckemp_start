#include <stdio.h>
#include <stdlib.h>

void print_bf(char *name);
void sort_fb(char *name);
void add_fb(char *name);

int main() {
    char *name = malloc(sizeof(char));
    int key;
    scanf("%s", name);
    scanf("%d", &key);
    switch (key) {
        case 0:
            print_bf(name);
            break;
        case 1:
            sort_fb(name);
            break;
        case 2:
            add_fb(name);
            break;
        default:
            printf("n/a\n");
            break;
    }
    free(name);
    return 0;
}

void print_bf(char *name) {
    FILE *fp = fopen(name, "rb");
    if (fp != NULL) {
        int z = 0;
        int s[8];
        while (fread(s, sizeof(int), 8, fp) == 8) {
            z++;
            for (int i = 0; i < 8; i++) {
                printf("%d", s[i]);
                if (i < 7)
                    printf(" ");
            }
            printf("\n");
        }
        fclose(fp);
        if (z == 0)
            printf("n/a\n");
    } else {
        printf("n/a\n");
    }
}
void sort_fb(char *name) {
    FILE *fp = fopen(name, "rb+");
    if (fp == NULL) {
        printf("n/a\n");
    } else {
        int s1[8];
        while (fread(s1, sizeof(int), 8, fp) == 8) {
            int s2[8], flag = 0;
            if (fread(s2, sizeof(int), 8, fp) == 8) {
                for (int j = 0; j < 6; j++) {
                    if (s1[j] > s2[j]) {
                        int buffer[8];
                        fseek(fp, -64, SEEK_CUR);
                        fread(buffer, sizeof(int), 8, fp);
                        fseek(fp, -32, SEEK_CUR);
                        fwrite(s2, sizeof(int), 8, fp);
                        fwrite(buffer, sizeof(int), 8, fp);
                        rewind(fp);
                        flag = 1;
                        break;
                    } else if (s1[j] < s2[j]) {
                        break;
                    }
                }
                if (flag == 0)
                    fseek(fp, -32, SEEK_CUR);
            } else {
                break;
            }
        }
        fclose(fp);
        print_bf(name);
    }
}
void add_fb(char *name) {
    FILE *fp = fopen(name, "ab");
    if (fp == NULL) {
        printf("n/a\n");
    } else {
        int s[8];
        for (int i = 0; i < 8; i++)
            scanf("%d", &s[i]);
        fwrite(s, sizeof(int), 8, fp);
        fclose(fp);
        sort_fb(name);
    }
}
