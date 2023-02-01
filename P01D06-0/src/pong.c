
#include <stdio.h>
#include <stdlib.h>
#include <termios.h>
#include <unistd.h>
#include <sys/time.h>
#include <sys/types.h>
#define STDIN 0

void jostik(char step);
void print_filed(int y, int x, int roket_p1, int roket_p2);
void new_set_tem();
void defolt_set_tem();
void boll_move_p2();
void boll_move_p1();
void boll_move_wall();

struct termios info;
int roket_p1 = 12;
int roket_p2 = 12;
int x_boll = 39;
int y_boll = 12;
int move_x_boll = -1;
int move_y_boll = 0;
int skore_p1 = 0;
int skore_p2 = 0;
int spide = 150000;

int main(void) {
  char step = ' ';
  new_set_tem();
  do {
    system("clear");
    printf("Skore_p1: %d  Skore_p2: %d\n", skore_p1, skore_p2);
    for (int y = 0; y < 25; ++y) {
      for (int x = 0; x < 80; ++x) {
        print_filed(y, x, roket_p1, roket_p2);
    }
       printf("\n");
    }
    jostik(step);
      boll_move_wall();
      boll_move_p1();
      boll_move_p2();
      x_boll += move_x_boll;
      y_boll += move_y_boll;
  } while (skore_p1 < 22 && skore_p2 < 22);

  defolt_set_tem();
  system("clear");
  if (skore_p1 > skore_p2) {
      printf("GLaDOS: Ого 21 очко, ты можешь взять свой торт p1!!!");
  } else {
      printf("GLaDOS: Ого 21 очко, ты можешь взять свой торт p2!!!");
  }
  printf("\nGLaDOS: Это была шутка, никакого торта нет.\n");
  return 0;
}

void boll_move_wall() {
    if (x_boll == 1) {
        x_boll = 39;
        y_boll = 12;
        roket_p1 = 12;
        roket_p2 = 12;
        skore_p2 += 1;
        move_x_boll = -1;
        move_y_boll = 0;
        spide = 150000;
    } else if (x_boll == 78) {
        x_boll = 39;
        y_boll = 12;
        roket_p1 = 12;
        roket_p2 = 12;
        skore_p1 += 1;
        move_x_boll = -1;
        move_y_boll = 0;
        spide = 150000;
    } else if (y_boll == 23) {
        move_y_boll = -1;
    } else if (y_boll == 1) {
        move_y_boll = 1;
    }
}

void boll_move_p1() {
    if ((y_boll + move_y_boll) == roket_p1 && (x_boll + move_x_boll) == 2) {
        move_x_boll = 1;
        move_y_boll = 0;
    } else if ((y_boll + move_y_boll) == roket_p1 - 1 && (x_boll + move_x_boll) == 2 &&\
               (move_y_boll == 0 || move_y_boll == -1)) {
        move_x_boll = 1;
        move_y_boll = -1;
    } else if ((y_boll + move_y_boll) == roket_p1 - 1 && (x_boll + move_x_boll) == 2 &&\
               (move_y_boll == 1)) {
        move_x_boll = 1;
        move_y_boll = 0;
    } else if ((y_boll + move_y_boll) == roket_p1 + 1 && (x_boll + move_x_boll) == 2 &&\
               (move_y_boll == 0 || move_y_boll == 1)) {
        move_x_boll = 1;
        move_y_boll = 1;
    } else if ((y_boll + move_y_boll) == roket_p1 + 1 && (x_boll + move_x_boll) == 2 &&\
               (move_y_boll == -1)) {
        move_x_boll = 1;
        move_y_boll = 0;
    }
}

void boll_move_p2() {
    if ((y_boll + move_y_boll) == roket_p2 && (x_boll + move_x_boll) == 77) {
        move_x_boll = -1;
        move_y_boll = 0;
    } else if ((y_boll + move_y_boll) == roket_p2 - 1 && (x_boll + move_x_boll) == 77 &&\
               (move_y_boll == 0 || move_y_boll == -1)) {
        move_x_boll = -1;
        move_y_boll = -1;
    } else if ((y_boll + move_y_boll) == roket_p1 - 1 && (x_boll + move_x_boll) == 77 &&\
           (move_y_boll == 1)) {
        move_x_boll = -1;
        move_y_boll = 0;
    } else if ((y_boll + move_y_boll) == roket_p2 + 1 && (x_boll + move_x_boll) == 77 &&\
               (move_y_boll == 0 || move_y_boll == 1)) {
        move_x_boll = -1;
        move_y_boll = 1;
    } else if ((y_boll + move_y_boll) == roket_p2 + 1 && (x_boll + move_x_boll) == 77 &&\
               (move_y_boll == -1)) {
        move_x_boll = -1;
        move_y_boll = 0;
    }
}

void jostik(char step) {
  struct timeval tv;
  fd_set readfds;
  tv.tv_sec = 0;
  tv.tv_usec = spide;
  FD_ZERO(&readfds);
  FD_SET(STDIN, &readfds);
  select(STDIN+1, &readfds, NULL, NULL, &tv);
  if (FD_ISSET(STDIN, &readfds))
    step = getchar();
  switch (step) {
    case 'a': if (roket_p1 > 2) {roket_p1--;} break;
    case 'A': if (roket_p1 > 2) {roket_p1--;} break;
    case 'z': if (roket_p1 < 22) {roket_p1++;} break;
    case 'Z': if (roket_p1 < 22) {roket_p1++;} break;
    case 'k': if (roket_p2 > 2) {roket_p2--;} break;
    case 'K': if (roket_p2 > 2) {roket_p2--;} break;
    case 'm': if (roket_p2 < 22) {roket_p2++;} break;
    case 'M': if (roket_p2 < 22) {roket_p2++;} break;
    }
    spide -= 250;
}

void print_filed(int y, int x, int roket_p1, int roket_p2) {
  if (y == 0 || y == 24) {
    printf("#");
  } else if (x == 0 || x == 79) {
    printf("#");
  } else if (x == 2 && (y == roket_p1 || y == roket_p1 + 1 || y == roket_p1 - 1)) {
    printf("|");
  } else if (x == 77 && (y == roket_p2 || y == roket_p2 + 1 || y == roket_p2 - 1)) {
    printf("|");
  } else if (x == x_boll && y == y_boll) {
      printf("*");
  } else {
      printf(" ");
  }
}

void new_set_tem() {
  tcgetattr(0, &info);
  info.c_lflag &= ~ICANON;
  info.c_lflag &= ~ECHO;
  info.c_cc[VMIN] = 1;
  info.c_cc[VTIME] = 0;
  tcsetattr(0, TCSANOW, &info);
}

void defolt_set_tem() {
  tcgetattr(0, &info);
  info.c_lflag |= ICANON;
  tcsetattr(0, TCSANOW, &info);
}
