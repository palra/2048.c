CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=2048

run: all
	./$(EXEC)

all: $(EXEC)

2048: main.o jeu.o
	$(CC) -o $@ $^ $(LDFLAGS)

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)