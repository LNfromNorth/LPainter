CFLAGS=-g -Wall
PAINTER=./painter
BIN=./bin
LIB=./lib
BUILD=./build
TESTS=./tests

all: $(LIB)/libpainter.so

# lib

$(BUILD)/painter.o: $(PAINTER)/painter.c
	$(CC) $< -c $(CFLAGS) -o $@

$(LIB)/libpainter.so: $(BUILD)/painter.o
	$(CC) $< $(CFLAGS) -fPIC -shared -o $@ 

# test


