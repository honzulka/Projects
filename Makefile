PROCESSING_PATH = /opt/processing-4.3
PROJ1_SKETCH = project_1
PROJ3_SKETCH = project_3

CC = gcc
CFLAGS = -std=c11 -D_POSIX_C_SOURCE=199309L -lcurses -Wall -Wextra -Werror -g
PROJ2_SRC = snake.c

proj1:
	$(PROCESSING_PATH)/processing-java --sketch=$(PROJ1_SKETCH) --run

proj2:
	(cd project_2/ && $(CC) $(CFLAGS) -o snake $(PROJ2_SRC) && ./snake)

proj3:
	$(PROCESSING_PATH)/processing-java --sketch=$(PROJ3_SKETCH) --run

.PHONY: proj1 proj2