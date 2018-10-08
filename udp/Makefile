.PHONY:clean

all : udp_server udp_client

udp_server:udp_server.c
	gcc -o $@ $^

udp_client:udp_client.c
	gcc -o $@ $^

clean:
	rm udp_client udp_server
