default:main

CC=gcc
SRC="src"
OUTFILE="main"

main:
	$(CC) $(SRC)/*.c -g -o $(OUTFILE).exe
	./$(OUTFILE).exe

clean:
	rm *.exe
