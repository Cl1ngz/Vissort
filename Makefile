CC = gcc
CFLAGS = -Wall -Wextra -g
LDFLAGS = -lncurses

SRC = src/main.c src/algorithms/bubble_sort.c src/utils/ncurses_utils.c
OBJ = $(SRC:.c=.o)
TARGET = build/visualizer

all: $(TARGET)

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET) $(LDFLAGS)

clean:
	rm -f $(OBJ) $(TARGET)

