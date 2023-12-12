all: main

main: main.c printHangman.c
	gcc -o main main.c printHangman.c
