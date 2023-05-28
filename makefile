CFLAGS=-g -Wall -DNDEBUG
PAINTER=./painter
BIN=./bin
LIB=./lib
BUILD=./build
TESTS=./tests

SOURCES=$(wildcard $(TESTS)/test_*.c)
TEST_FILE=$(patsubst $(TESTS)/%.c,$(BIN)/%,$(SOURCES))

all: $(LIB)/libpainter.so $(TEST_FILE)
	@echo $(TEST_FILE)

# lib

$(BUILD)/painter.o: $(PAINTER)/painter.c
	$(CC) -I ./painter $< -c $(CFLAGS) -o $@

$(LIB)/libpainter.so: $(BUILD)/painter.o
	$(CC) $< $(CFLAGS) -fPIC -shared -o $@ 

# test
test:
	sh ./runtest.sh

$(BUILD)/%.o: $(TESTS)/%.c
	$(CC) $< -c -I ./painter $(CFLAGS) -o $@

$(BIN)/%: $(BUILD)/%.o 
	$(CC) $< -L $(LIB) -lpainter -o $@

.PHONY:clean
clean:
	rm ./build/*
	rm ./bin/*
	rm ./lib/*
