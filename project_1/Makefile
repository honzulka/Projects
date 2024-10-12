CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
GTK = `pkg-config --cflags gtk4` `pkg-config --libs gtk4`

TARGET = program

SRCS = stars.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(GTK) $(CFLAGS) -o $@ $^

test:
	$(CC) $(CFLAGS) -o main main.c
	./main

clean:
	rm -f $(TARGET)

.PHONY: all clean 