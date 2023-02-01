all: graph.o structs.o Input_and_transform.o calc.o
	gcc -Wall -Werror -Wextra  ../build/graph.o ../build/input_and_transform.o \
	../build/calc.o ../build/structs.o -o ../build/graph

graph.o: graph.c defines.h
	gcc -Wall -Wextra -Werror -c graph.c -o ../build/graph.o


Input_and_transform.o: Input_and_transform.c Input_and_transform.h
	gcc -Wall -Wextra -Werror -c Input_and_transform.c -o ../build/Input_and_transform.o

calc.o: calc.c calc.h
	gcc -Wall -Wextra -Werror -c calc.c -o ../build/calc.o

structs.o: structs.c structs.h
	gcc -Wall -Wextra -Werror -c structs.c -o ../build/structs.o


clean:
	rm -rf ../build/*.o
	rm -rf ../build/graph

rebuild: clean all