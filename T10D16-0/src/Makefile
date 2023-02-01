all: strlen_tests strcmp_tests strcmp_tests strcat_tests strchr_tests strstr_tests

s21_string.o: s21_string.c s21_string.h
	gcc -c s21_string.c



strlen_tests: s21_string.o s21_string_test1.o
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test1.o \
	-o ../build/Quest_1

s21_string_test1.o: s21_string_test.c
	gcc -Dstrlen_tests -c s21_string_test.c -o s21_string_test1.o




strcmp_tests: s21_string.o s21_string_test2.o 
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test2.o \
	-o ../build/Quest_2

s21_string_test2.o: s21_string_test.c
	gcc -Dstrcmp_tests -c s21_string_test.c -o s21_string_test2.o




strcpy_tests: s21_string.o s21_string_test3.o 
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test3.o \
	-o ../build/Quest_3

s21_string_test3.o: s21_string_test.c
	gcc -Dstrcpy_tests -c s21_string_test.c -o s21_string_test3.o




strcat_tests: s21_string.o s21_string_test4.o 
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test4.o \
	-o ../build/Quest_4

s21_string_test4.o: s21_string_test.c
	gcc -Dstrcat_tests -c s21_string_test.c -o s21_string_test4.o


	

strchr_tests: s21_string.o s21_string_test5.o 
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test5.o \
	-o ../build/Quest_5

s21_string_test5.o: s21_string_test.c
	gcc -Dstrchr_tests -c s21_string_test.c -o s21_string_test5.o


	

strstr_tests: s21_string.o s21_string_test6.o 
	gcc -Wall -Werror -Wextra s21_string.o s21_string_test6.o \
	-o ../build/Quest_6

s21_string_test6.o: s21_string_test.c
	gcc -Dstrstr_tests -c s21_string_test.c -o s21_string_test6.o

	


rebuild:
	rm -rf ./build/Quest*

clean:
	rm -rf *.o
	rm -rf data_bilder*