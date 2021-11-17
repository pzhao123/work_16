all: main.o
	gcc -o forkin main.c
main.o: 
	gcc -c main.c
run: 
	./forkin