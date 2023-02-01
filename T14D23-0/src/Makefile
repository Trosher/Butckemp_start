all: state_sort state_search clear_state

state_sort:
	gcc -Wall -Wextra -Werror state_sort.c -o ../build/Quest_1

state_search:
	gcc -Wall -Wextra -Werror state_search.c -o ../build/Quest_2

clear_state:
	gcc -Wall -Wextra -Werror clear_state.c -o ../build/Quest_3

clean:
	rm -rf ../build/Quest*

rebuild:
	clean all