all: main.o stack.o
	gcc $^ -o main

%.o: %.c
	gcc -c $^

clean:
	rm -rf *.o main