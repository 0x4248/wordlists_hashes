CC = gcc

CFLAGS = -lssl -lcrypto

SRC = src
MAIN = hash.c

all: compile

compile:
	$(CC) $(SRC)/$(MAIN) -o hash $(CFLAGS)