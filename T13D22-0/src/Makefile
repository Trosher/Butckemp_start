all: cipher loggin_cipher

cipher: 
	gcc -Wall -Werror -Wextra cipher.c -o ../build/cipher

loggin_cipher: logger.o cipher.o
	gcc -Wall -Werror -Wextra logger.o cipher.o -o ../build/logging_cipher

logger.o: logger.c logger.h log_levels.h
	gcc -c logger.c -o ../build/logger.o

cipher.o: cipher.c
	gcc -c -Dloggin_cipher cipher.c -o ../build/cipher.o

clean:
	rm -rf ../build/*.o
	rm -rf ../build/cipher

rebuild: clean all