CC=gcc
CFLAGS=-Wall
LDFLAGS=
EXEC=2048
TEXEC=2048test
SRC= $(wildcard src/*.c) main.c
TEST= $(wildcard src/*.c test/*.c)
OBJ= $(SRC:.c=.o)

run: mrproper all
	@./$(EXEC)

run-test: mrproper $(TEXEC)
	@./$(TEXEC)

all: $(EXEC)

$(TEXEC): $(TEST)
	@$(CC) -o $@ $^ $(LDFLAGS)

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
	@rm -rf $(TEXEC)