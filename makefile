all: write_random_int.c
	gcc -o write_random_int write_random_int.c
run: all
	./write_random_int
