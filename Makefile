default:main

CC=gcc
SRC="src"
OUTFILE="main"

main:
	$(CC) $(SRC)/*.c -std=c99 -o $(OUTFILE).exe
	./$(OUTFILE).exe

clean:
	rm *.exe
