CC = gcc
CFLAGS = -Wall -Wextra -g

DEBUG ?= 1

ifeq ($(DEBUG),1)
CFLAGS += -O0
else
CFLAGS += -O2
endif

SRC = tasm.c \
      lexer/lexer.c \
      parser/parser.c \
      codegen/codegen.c \
      utils/utils.c \
      codegen/instr_emit/arithmetic.c \
      codegen/instr_emit/data_transfer.c \
      codegen/instr_emit/io.c \
      codegen/instr_emit/program_flow.c \
      isa/isa.c \
      labels/labels.c

OBJ = $(SRC:.c=.o)

TARGET = tasm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)