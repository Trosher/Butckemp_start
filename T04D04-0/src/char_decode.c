#include <stdio.h>

void decoder();
void coder();

int main(int argc, char **argv) {
  if(argc == 2)
  {
  	  if (*argv[1] == '0') {	
	  coder();
	} else if (*argv[1] == '1') {
      decoder();
	} else {
	  printf("n/a");
	}
  } else {
    printf("n/a");
  }
  return 0;
}

void coder(){
  char c, space;
  unsigned int test;
  for (int i = 1; ; i++) {
	test = scanf("%c%c", &c, &space);
	if (test != 2 || (i == 1 && space == '\n')) {
	  printf("n/a"); 
	  break;
	} else if (space != '\n') {
	  printf("%X ", c);
	} else {
	  printf("%X", c); 
	  break;
	}
  }
}

void decoder(){
  unsigned int test, d16;
  char space;
  for (int i = 1; ; i++) {
	 test = scanf("%x%c", &d16, &space);
 	 if (test != 2 || (i == 1 && space == '\n')) {
	  printf("n/a"); 
	  break;
	} else if (space != '\n') {
	  printf("%c ", d16);
	} else {
	  printf("%c", d16); 
	  break;
	}
  }
}
