all: door_struct list_test



dmanager_module.o: dmanager_module.c door_struct.h
	gcc -c dmanager_module.c -o dmanager_module.o



door_struct: dmanager_module1.o
	gcc -Wall -Werror -Wextra dmanager_module1.o \
	-o ../build/Quest_1

dmanager_module1.o: dmanager_module.c door_struct.h
	gcc -Ddoor_struct -c dmanager_module.c -o dmanager_module1.o



list_test: dmanager_module.o list.o list_test.c
	gcc -Wall -Werror -Wextra dmanager_module.o list.o list_test.c \
	-o ../build/Quest_2

list.o: list.c list.h
	gcc -c list.c -o list.o


stack_test: stack.o dmanager_module.o stack_test.c
	gcc -Wall -Werror -Wextra dmanager_module.o stack.o stack_test.c \
	-o ../build/Quest_3

stack.o: stack.c stack.h
	gcc -c stack.c -o stack.o


rebuild:
	rm -rf ../build/Quest*

clean:
	rm -rf *.o