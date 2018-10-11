.PHONY:clean

main:main.o chess.o
	gcc -o $@ $^

%.o:%.c
	gcc -c $^ -o $@

clean:
	rm -rf main *.o
