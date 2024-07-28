default:main

CC=gcc
SRC=src
CFLAGS=-g 
OUTFILE=main

main:
	$(CC) $(SRC)/*.c $(CFLAGS) -o $(OUTFILE).exe
	./$(OUTFILE).exe

clean:
	rm *.exe
