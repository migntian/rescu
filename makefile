.PHONY:clean
all:server.c client.c
	
server:server.c -lpthread
	gcc -o $@ @^
client:client.c
	gcc -o $@ $^
clean:
	rm server client
