CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=-lm

%.o: %.c visualtree.h tree.h
	$(CC) -c -o $@ $< $(CFLAGS)

huffman: huffman.o visualtree.o tree.o
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f huffman huffman.o visualtree.o tree.o current-tree.dot current-tree.pdf