CC = gcc
CFLAGS = -Wall -Wextra -g -Iinclude
LDFLAGS = -pthread

SRC = src/main.c \
      src/input.c \
      src/parser.c \
      src/process.c \
      src/builtin.c \
      src/pipes.c \
      src/redirect.c \
      src/thread.c

TARGET = bin/process_explorer

all: $(TARGET)

$(TARGET): $(SRC)
	mkdir -p bin
	$(CC) $(CFLAGS) $(SRC) $(LDFLAGS) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -rf bin/*

asan:
	$(CC) $(CFLAGS) -fsanitize=address $(SRC) $(LDFLAGS) -o $(TARGET)
