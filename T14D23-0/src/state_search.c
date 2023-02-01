#include <stdio.h>
#include <stdlib.h>

void print_bf(int *name_data, char *name);

int main() {
char *name = malloc(sizeof(char));
scanf("%s", name);
int name_data[3];
if (scanf("%d.%d.%d", &name_data[2], &name_data[1], &name_data[0]) == 3) {
    print_bf(name_data, name);
} else {
    printf("n/a");
}
free(name);
}

void print_bf(int *name_data, char *name) {
    FILE *fp = fopen(name, "rb");
    if (fp != NULL) {
        int z = 0;
        int s[8];
        while (fread(s, sizeof(int), 8, fp) == 8) {
            if (s[0] == name_data[0] && s[1] == name_data[1] && s[2] == name_data[2]) {
                printf("%d", s[7]);
                z = 1;
                break;
            }
        }
        fclose(fp);
        if (z == 0)
            printf("n/a");
    } else {
        printf("n/a");
    }
}
