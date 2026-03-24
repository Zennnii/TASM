CC = gcc
CFLAGS = -Wall -Wextra -O2

SRC = tasm.c \
      parser/parser.c \
      bingen/bingen.c \
      utils/utils.c \
      bingen/instr_emit/arithmetic.c \
      bingen/instr_emit/data_transfer.c \
      bingen/instr_emit/io.c \
      bingen/instr_emit/program_flow.c

OBJ = $(SRC:.c=.o)

TARGET = tasm

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJ)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJ) $(TARGET)