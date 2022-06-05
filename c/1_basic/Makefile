test: test.o file2.o
	cc -o test test.o file2.o

test.o: main.c
	cc -c main.c -o test.o

file2.o: file2.c
	cc -c file2.c -o file2.o

clean:
	rm -vf *.o
	rm -vf test
