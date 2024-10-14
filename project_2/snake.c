#include <stdlib.h>
#include <unistd.h>
#include <curses.h>
#include <time.h>
#include <string.h>

#include "snake.h"


int score;
char score_message[16];

bool skip, is_running;
vec2 food;
Snake snake;

int screen_width = WIDTH;
int screen_height = HEIGHT;

// initialize screen
WINDOW *win;

struct timespec ts;

bool collide(vec2 a, vec2 b) {
    if (a.x == b.x && a.y == b.y) {
        return true;
    }
    else return false;
}

bool collide_snake_body(vec2 point) {
    for (int i = 0; i < score; i++) {
        if (collide(point, snake.segments[i])) {
            return true;
        }
    }
    return false;
}

vec2 spawn_food() {
    // spawn a new food with 1 pixel padding from edges and not inside of the snake
    vec2 food = { 1 + rand() % (screen_width - 2), 1 + rand() % (screen_height - 2) };
    while (collide(snake.head, food) || collide_snake_body(food)) {
        food.x = 1 + rand() % (screen_width - 2);
        food.y = 1 + rand() % (screen_height - 2);
    }
    return food;
}

void draw_border(int y, int x, int width, int height) {
    // top row
    mvaddch(y, x, ACS_ULCORNER);
    mvaddch(y, x + width * 2, ACS_URCORNER);
    for (int i = 1; i < width * 2; i++) {
        mvaddch(y, x + i, ACS_HLINE);
    }
    // vertical lines
    for (int i = 1; i < height + 1; i++) {
        mvaddch(y + i, x, ACS_VLINE);
        mvaddch(y + i, x + width * 2, ACS_VLINE);
    }
    // bottom row
    mvaddch(y + height + 1, x, ACS_LLCORNER);
    mvaddch(y + height + 1, x + width * 2, ACS_LRCORNER);
    for (int i = 1; i < width * 2; i++) {
        mvaddch(y + height + 1, x + i, ACS_HLINE);
    }
}

void quit_game() {
    // exit cleanly from application
    endwin();
    // clear screen, place cursor on top, and un-hide cursor
    system("clear");
    exit(0);
}

void restart_game() {
    snake.head.x = 0;
    snake.head.y = 0;
    snake.dir.x = 1;
    snake.dir.y = 0;
    score = 0;
    sprintf(score_message, "[ Score: %d ]", score);
    is_running = true;
}

void init() {
    srand(time(NULL));

    ts.tv_sec = 0;           
    ts.tv_nsec = 110000000; //nanosleep 0,11 second delay
    skip = false;
    is_running = true;
    snake.head.x = 0;
    snake.head.y = 0;
    snake.dir.x = 1;
    snake.dir.y = 0;
    score = 0;

    // initialize window
    win = initscr();
    // take player input and hide cursor
    keypad(win, true);
    noecho();
    nodelay(win, true);
    curs_set(0);

    // initialize color
    if (has_colors() == FALSE) {
        endwin();
        fprintf(stderr, "Your terminal does not support color\n");
        exit(1);
    }
    start_color();
    use_default_colors();
    init_pair(1, COLOR_RED, -1);
    init_pair(2, COLOR_GREEN, -1);
    init_pair(3, COLOR_YELLOW, -1);


    food.x = rand() % screen_width;
    food.y = rand() % screen_height;

    // update score message
    sprintf(score_message, "[ Score: %d ]", score);
}

void process_input() {
    int pressed = wgetch(win);
    if (pressed == KEY_LEFT || pressed == 97) {
        if (snake.dir.x == 1) {
            return;
            skip = true;
        }
        snake.dir.x = -1;
        snake.dir.y = 0;
    }
    if (pressed == KEY_RIGHT || pressed == 100) {
        if (snake.dir.x == -1) {
            return;
            skip = true;
        }
        snake.dir.x = 1;
        snake.dir.y = 0;
    }
    if (pressed == KEY_UP || pressed == 119) {
        if (snake.dir.y == 1) {
            return;
            skip = true;
        }
        snake.dir.x = 0;
        snake.dir.y = -1;
    }
    if (pressed == KEY_DOWN || pressed == 115) {
        if (snake.dir.y == -1) {
            return;
            skip = true;
        }
        snake.dir.x = 0;
        snake.dir.y = 1;
    }
    if (pressed == ' ') {
        if (!is_running)
            restart_game();
    }
    if (pressed == '\e') {
        is_running = false;
        quit_game();
    }
}

void game_over() {
    while (is_running == false) {
        process_input();

        mvaddstr(screen_height / 2, screen_width - 16, "            Game Over            ");
        mvaddstr(screen_height / 2 + 1, screen_width - 16, "[SPACE] to restart, [ESC] to quit ");
        attron(COLOR_PAIR(3));
        draw_border(screen_height / 2 - 1, screen_width - 17, 17, 2);
        attroff(COLOR_PAIR(3));

        nanosleep(&ts, NULL);
    }
}

void update() {
    // update snake segments
    for (int i = score; i > 0; i--) {
        snake.segments[i] = snake.segments[i - 1];
    }
    snake.segments[0] = snake.head;

    // move snake
    snake.head.x += snake.dir.x;
    snake.head.y += snake.dir.y;

    // collide with body or walls
    if (collide_snake_body(snake.head) || snake.head.x < 0 || snake.head.y < 0 \
            || snake.head.x >= screen_width || snake.head.y >= screen_height) {
        is_running = false;
        game_over();
    }

    // eating a food
    if (collide(snake.head, food)) {
        if (score < MAX_SCORE) {
            score += 1;
            sprintf(score_message, "[ Score: %d ]", score);
        }
        else {
            // WIN!
            printf("You Win!");
        }
        food = spawn_food();
    }

    nanosleep(&ts, NULL);
}

void draw() {
    erase();

    attron(COLOR_PAIR(1));
    mvaddch(food.y + 1, food.x * 2 + 1, '@');
    attroff(COLOR_PAIR(1));

    // draw snake
    attron(COLOR_PAIR(2));
    for (int i = 0; i < score; i++) {
        mvaddch(snake.segments[i].y+1, snake.segments[i].x * 2 + 1, ACS_DIAMOND);
    }
    mvaddch(snake.head.y + 1, snake.head.x * 2 + 1, 'O');
    attroff(COLOR_PAIR(2));

    attron(COLOR_PAIR(3));
    draw_border(0, 0, screen_width, screen_height);
    attroff(COLOR_PAIR(3));
    mvaddstr(0, screen_width - 5, score_message);
}

int main() {

    init();
    while(is_running) {
        process_input();
        if (skip == true) {
            skip = false;
            continue;
        }
        update();
        draw();
    }
    quit_game();
    return 0;
}