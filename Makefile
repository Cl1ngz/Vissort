CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = 

SRC = src/main.c $(wildcard src/algorithms/*.c) src/utils/array_utils.c
OBJ = $(SRC:.c=.o)
TARGET = build/visualizer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

