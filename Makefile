INCLUDE_DIR=include
SRC_DIR=src
OBJ_DIR=build
TEST_DIR=test
TEST_OBJ_DIR=build_$(TEST_DIR)

OUT=main.exe
DEBUG_FLAGS=-ggdb 
WARNING_FLAGS=-Wall -Werror -pedantic
CFLAGS=-I$(INCLUDE_DIR) $(DEBUG_FLAGS) $(WARNING_FLAGS) 
CC=gcc

SRCS := $(shell find $(SRC_DIR) -name "*.c")
OBJS := $(SRCS:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

TEST_SRCS := $(shell find $(SRC_DIR) $(TEST_DIR) -name "*.c" ! -name "main.c") 
TEST_OBJS := $(patsubst %.c, $(TEST_OBJ_DIR)/%.o, $(notdir $(TEST_SRCS)))

all: pedix 

pedix: $(OBJS)
	$(CC) $^ -o $(OUT)

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

$(TEST_OBJ_DIR)/test.o: $(TEST_DIR)/test.c
	@mkdir -p $(@D)
	$(CC) $(CFLAGS) -c $< -o $@

.PHONY: run all clean test

clean:
	rm $(OBJ_DIR)/*.o
	rmdir $(OBJ_DIR)

test: $(TEST_OBJS)
	$(CC) $^ -o test_$(OUT) && ./test_$(OUT)
	@rm $(TEST_OBJ_DIR)/*.o
	@rmdir $(TEST_OBJ_DIR)
	@rm test_$(OUT)

run: 
	./$(OUT)
