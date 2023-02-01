all: main.o

main.o: data_io.o data_stat.o data_process.o data_bilder

data_io.o: ../data_libs/data_io.h ../data_libs/data_io.c
	gcc -c ../data_libs/data_io.c

data_stat.o: ../data_libs/data_stat.h ../data_libs/data_stat.c
	gcc -c ../data_libs/data_stat.c

data_process.o: data_process.c data_process.h 
	gcc -c data_process.c
	
data_bilder: 
	gcc -Wall -Werror -Wextra data_io.o data_stat.o \
	data_process.o main_executable_module.c \
	-o ../../build/Quest_3

data_stat.a: data_stat.o
	ar -rc libdata_stat.a data_stat.o
	ranlib libdata_stat.a	

build_with_static: data_stat.a data_io.o data_process.o
	gcc -Wall -Werror -Wextra main_executable_module.c \
	data_io.o -L. -ldata_stat \
	data_process.o -o ../../build/Quest_5

data_process.so: data_process.c data_process.h
	gcc -fPIC -c data_process.c
	gcc -shared -o libdata_process.so data_process.o data_stat.o

build_with_dynamic: data_io.o data_stat.o data_process.so
	gcc -Wall -Werror -Wextra main_executable_module.c \
	data_io.o data_stat.o -L. -ldata_process -o ../../build/Quest_6
	cp libdata_process.so ../../build/

clean:
	rm *.o
	rm *.a
	rm *.so