all: main.c test_data.o insert.o search.o
		gcc main.c test_data.o insert.o search.o -o main -lm

test_data.o: test_data.c test_data.h
		gcc -c test_data.c -o test_data.o

insert.o: insert.c insert.h
		gcc -c insert.c -o insert.o

search.o: search.c search.h
		gcc -c search.c -o search.o

clean:
		rm -f test_data.o search.o insert.o main
