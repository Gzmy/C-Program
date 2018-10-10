.PHOMY:clean

all:cal_server cal_client

cal_server:cal_server.c
	gcc $^ -o $@

cal_client:cal_client.c
	gcc -o $@ $^

clean:
	rm cal_client cal_server
