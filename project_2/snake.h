#ifndef _SNAKE_H 
#define _SNAKE_H

#define WIDTH 25
#define HEIGHT 20
#define MAX_SCORE 256

typedef struct vec2 {
    int x;
    int y;
} vec2;

typedef struct Snake {
    vec2 head;
    vec2 dir;
    vec2 segments[MAX_SCORE + 1];
} Snake;

bool collide(vec2 a, vec2 b);

bool collide_snake_body(vec2 point);

vec2 spawn_food();

void draw_border(int y, int x, int width, int height);

void quit_game();

void restart_game();

void init();

void process_input();

void game_over();

void update();

void draw();

#endif