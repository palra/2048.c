CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=2048
SRC= $(wildcard *.c)
OBJ= $(SRC:.c=.o)

run: mrproper all
	@./$(EXEC)

all: $(EXEC)

2048: $(SRC)
	@$(CC) -o $@ $^ $(LDFLAGS)
	
main.o: jeu.h

%.o: %.c
	@$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	@rm -rf *.o

mrproper: clean
	@rm -rf $(EXEC)