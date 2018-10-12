.PHONY:clean

main:sweeper.o main.o
	gcc -o $@ $^

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -rf main *.o
