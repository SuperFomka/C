CC = gcc
CFLAGS = -Wall -Werror -Wextra
TARGET = ../build/graph

all: graph

graph:
	$(CC) $(CFLAGS) graph.c parcer.c maths.c draw.c stack.c -o $(TARGET)

clean: 
	rm -rf ../build/graph

rebuild: clean all