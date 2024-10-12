PROCESSING_PATH = /opt/processing-4.3
PROJ1_SKETCH = project_1

CC = gcc
CFLAGS = -std=c11 -lcurses -Wall -Wextra -Werror -g
PROJ2_SRC = snake.c

proj1:
	sudo $(PROCESSING_PATH)/processing-java --sketch=$(PROJ1_SKETCH) --run

proj2:
	(cd project_2/ && $(CC) $(CFLAGS) -o snake $(PROJ2_SRC) && ./snake)

test:
	(cd project_2/ && $(CC) $(CFLAGS) -o test main.c && ./test)

.PHONY: proj1 proj2