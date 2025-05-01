
CC = gcc
CFLAGS = -Wall -Werror -g -fsanitize=address
LDFLAGS = -lm
OBJS = image.o tp8ex2.o

all: tp8ex2
tp8ex2: $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^ $(LDFLAGS)
image.o: image.c image.h
	$(CC) $(CFLAGS) -c image.c
tp8ex2.o: tp8ex2.c image.h
	$(CC) $(CFLAGS) -c tp8ex2.c
clean:
	rm -f $(OBJS) tp8ex2