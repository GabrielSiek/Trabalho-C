CFLAGS = -c -std=c11

all:			main

main:			main.o hardware_library.o
					gcc -o main main.o hardware_library.o

main.o:			main.c
					gcc ${CFLAGS} main.c

hardware_library.o:	hardware_library.c hardware_library.h
					gcc ${CFLAGS} hardware_library.c

clean:
				rm -f main main.o hardware_library.o