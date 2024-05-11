default:main

CC=clang
SRC="src"
OUTFILE="main"

main:
	$(CC) $(SRC)/*.c -Wall -Wextra -o $(OUTFILE).exe
	./$(OUTFILE).exe

clean:
	rm *.exe