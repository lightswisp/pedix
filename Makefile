default:main

CC=clang
SRC="src"
OUTFILE="main"

main:
	$(CC) $(SRC)/*.c -o $(OUTFILE).exe

clean:
	rm *.exe