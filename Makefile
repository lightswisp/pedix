.PHONY: clean test build_test build_main run main
default:main

CC=gcc
SRC  = $(wildcard src/*.c)
TEST = $(wildcard test/*.c)
EXTENSION=exe
CFLAGS=-g -Wall 
OUTFILE=main

main: build_main run

test: build_test run clean

build_main:
	$(CC) $(SRC) $(CFLAGS) -o $(OUTFILE).$(EXTENSION)

build_test:
	$(CC) $(filter-out src/main.c src/dump.c, $(SRC)) $(TEST) $(CFLAGS) -o $(OUTFILE).$(EXTENSION)

run: 
	./$(OUTFILE).$(EXTENSION)

clean:
	rm *.exe 

