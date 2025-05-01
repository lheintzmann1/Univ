CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -g
LDFLAGS = -lm

# Règle pour tp8ex1
tp8ex1: tp8ex1.o matrice.o
	$(CC) -o $@ $^ $(LDFLAGS)

# Règle pour tp8ex2
tp8ex2: tp8ex2.o image.o matrice.o
	$(CC) -o $@ $^ $(LDFLAGS)

# Règles de dépendances
tp8ex1.o: tp8ex1.c matrice.h
	$(CC) $(CFLAGS) -c -o $@ $<

tp8ex2.o: tp8ex2.c image.h
	$(CC) $(CFLAGS) -c -o $@ $<

image.o: image.c image.h matrice.h
	$(CC) $(CFLAGS) -c -o $@ $<

matrice.o: matrice.c matrice.h
	$(CC) $(CFLAGS) -c -o $@ $<

# Nettoyage
clean:
	rm -f *.o tp8ex1 tp8ex2

# Règle par défaut
all: tp8ex1 tp8ex2