all: compile run


compile:
	g++ -g -std=c++11 main.cpp

LRUcache:
	g++ -std=c++11 main.cpp

client: client.c
	g++ -g -std=c++11 client.c -o client

server: server.c
	g++ -g -std=c++11 server.c -o server 

run: 
	./a.out

serve:
	./server 55117

call:
	./client localhost 55117

debug: 
	lldb ./a.out

