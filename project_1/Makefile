CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g
GTK = `pkg-config --cflags gtk4`

TARGET = program

SRCS = main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(GTK) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean 