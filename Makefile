# Makefile for PARCO-Computing-2027
# Plasser denne fila i rotmappa til repoet (ved siden av README.md og src/)

CC      := gcc
CFLAGS  := -O2 -Wall -Wextra -std=gnu11
LDLIBS  := -lm

SRC_DIR := src
BIN_DIR := bin
OBJ_DIR := build

# Felles kode som deles av alle program
COMMON_SRC := $(SRC_DIR)/integrand.c
COMMON_OBJ := $(OBJ_DIR)/integrand.o

# Program som skal bygges
TARGETS := $(BIN_DIR)/serial

.PHONY: all clean run debug

all: $(TARGETS)

# Serielt program
$(BIN_DIR)/serial: $(OBJ_DIR)/serial.o $(COMMON_OBJ) | $(BIN_DIR)
	$(CC) $(CFLAGS) $^ -o $@ $(LDLIBS)

# Generell regel: .c -> .o (avhenger også av headeren)
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c $(SRC_DIR)/integrand.h | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

run: $(BIN_DIR)/serial
	./$(BIN_DIR)/serial

debug: CFLAGS := -O0 -g -Wall -Wextra -std=gnu11
debug: clean all

clean:
	rm -rf $(BIN_DIR) $(OBJ_DIR)