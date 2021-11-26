#fichier makefile

all: test1.exe test2.exe

test1.exe: main.c
	gcc main.c list.c -o test1.exe

test2.exe: main2.c
	gcc main2.c list2.c -o test2.exe

.PHONY: clean
clean:
	rm -rf test*
 