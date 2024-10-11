CC = gcc
CFLAGS = -std=c11 -Wall -Wextra -Werror -g

TARGET = program

SRCS = main.c

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CC) $(CFLAGS) -o $@ $^

clean:
	rm -f $(TARGET)

.PHONY: all clean 