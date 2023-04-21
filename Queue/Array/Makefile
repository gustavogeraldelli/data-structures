all: main.o queue.o
	gcc $^ -o main

%.o: %.c
	gcc -c $^

clean:
	rm -rf *.o main