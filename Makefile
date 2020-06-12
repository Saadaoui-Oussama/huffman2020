CC=gcc
CFLAGS=-Wall -ansi
LDFLAGS=
DEPS=visualtree.h tree.h prioqueue.h
OBJ=visualtree.o tree.o prioqueue.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

huffman: huffman.o $(OBJ)
	gcc -o $@ $^ $(LDFLAGS)
	rm -f encodage.txt decodage.txt

.PHONY: clean
clean:
	rm -f $(OBJ) huffman huffman.o current-tree.dot current-tree.pdf encodage.txt decodage.txt