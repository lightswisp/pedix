INCLUDE_DIR=include
SRC_DIR=src
OBJ_DIR=build

OUT=main.exe
CFLAGS=-I$(INCLUDE_DIR) -ggdb -Wall -Werror -pedantic 
CC=gcc

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

all: pedix 

pedix: $(OBJS)
	$(CC) $^ -o $(OUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run all clean

clean:
	rm $(OBJ_DIR)/*.o

run: 
	./$(OUT)
