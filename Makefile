CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
DEPS=visualtree.h tree.h
OBJ=visualtree.o tree.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

huffman: huffman.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)

.PHONY: clean
clean:
	rm -f $(OBJ) huffman huffman.o current-tree.dot current-tree.pdf