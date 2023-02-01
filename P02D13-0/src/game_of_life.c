#include <unistd.h>
#include <ncurses.h>
#include <termios.h>
#include <fcntl.h>

void print(void *u, int poz_x, int poz_y);
void life(void *u, int poz_x, int poz_y);
void game(int poz_x, int poz_y);
void input_matrix(void *data, int poz_x, int poz_y);
char speed();
int main() {
    game(80, 25);
    return 0;
}

void input_matrix(void *data, int poz_x, int poz_y) {
    int (*field)[poz_x] = data;
    char c;
    for (int j = 0; j < poz_y; j++) {
        for (int i = 0; i < poz_x; i++) {
            scanf("%d%c", &field[j][i], &c);
            if (c == '\n' || c == EOF) { break; }
        }
    }
}

void print(void *u, int poz_x, int poz_y) {
    clear();
    int (*univ)[poz_x] = u;
    for (int j = 0; j < poz_x  + 2; j++) {
        printf("#");
    }
    for (int i = 0; i < poz_y; i++) {
       printf("#");
        for (int j = 0; j < poz_x; j++)
            if (univ[i][j] == 1)
                printf("o");
            else
                printf(" ");
        printf("#");
    }
    for (int j = 0; j < poz_x  + 2; j++) {
        printf("#");
    }
    refresh();
}

void life(void *u, int poz_x, int poz_y) {
    unsigned (*univ)[poz_x] = u;
    unsigned new[poz_y][poz_x];
    for (int i = 0; i < poz_y; i++)
        for (int j = 0; j < poz_x; j++) {
        int n = 0;
        for (int y1 = i - 1; y1 <= i + 1; y1++)
            for (int x1 = j - 1; x1 <= j + 1; x1++)
                if (univ[(y1 + poz_y) % poz_y][(x1 + poz_x) % poz_x])
                    n++;
         if (univ[i][j])
             n--;
        new[i][j] = (n == 3 || (n == 2 && univ[i][j]));
    }
    for (int i = 0; i < poz_y; i++)
        for (int j = 0; j < poz_x; j++)
            univ[i][j] = new[i][j];
}

void game(int poz_x, int poz_y) {
    unsigned univ[poz_y][poz_x];
    int time = 500000;
    input_matrix(univ, poz_x, poz_y);
    while (1) {
        print(univ, poz_x, poz_y);
        life(univ, poz_x, poz_y);
        char speed1 = speed();
        if (speed1 == '2')
            time /= 1.5;
        else if (speed1 == '1')
            time *= 1.5;
        usleep(time);
    }
}

char speed() {
    char z = EOF;
    struct termios oldt, newt;
    FILE* term = fopen("/dev/tty", "r"); {
        int oldf;
        int des = term ->_file;
        tcgetattr(des, &oldt);
        newt = oldt;
        newt.c_lflag &= ~(ICANON | ECHO);
        tcsetattr(des, TCSANOW, &newt);
        oldf = fcntl(des, F_SETFL, 0);
        fcntl(des, F_SETFL, oldf | O_NONBLOCK);
        initscr();
        noecho();
        fscanf(term, "%c", &z);
        endwin();
        tcsetattr(des, TCSANOW, &oldt);
        fcntl(des, F_SETFL, oldf);
    }   fclose(term);
    return z;
}
