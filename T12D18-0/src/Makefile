all: print_module documentation_module bst_create_test

print_module: print_module.o main_module_entry_point1.o
	gcc -Wall -Werror -Wextra print_module.o main_module_entry_point.o \
	-o ../build/Quest_1

print_module.o: print_module.c print_module.h
	gcc -c print_module.c -o print_module.o

main_module_entry_point1.o: main_module_entry_point.c
	gcc -c -Dprint_module main_module_entry_point.c -o main_module_entry_point.o




documentation_module: main_module_entry_point2.o documentation_module.o
	gcc -Wall -Werror -Wextra documentation_module.o main_module_entry_point2.o \
	-o ../build/Quest_2

documentation_module.o: documentation_module.c documentation_module.h
	gcc -c documentation_module.c -o documentation_module.o


main_module_entry_point2.o: main_module_entry_point.c
	gcc -c -Ddocumentation_module main_module_entry_point.c -o main_module_entry_point2.o


bst_create_test: bst.o
	gcc -Wall -Wextra -Werror bst.o bst_create_test.c \
	-o ../build/Quest_3


bst.o: bst.c bst.h
	gcc -c bst.c -o bst.o

rebuild:
	rm -rf ../build/Quest*

clean:
	rm -rf *.o