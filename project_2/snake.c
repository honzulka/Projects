
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <ncurses.h>
#include <time.h>

int height = 20;
int width = 20;

int score, game_over;

int X, Y, food_x, food_y, flag;


// Function to make the boundaries
void boundary(WINDOW *win) {

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            if (y == 0 || y == height - 1 || x == 0 || x == width - 1) {
                mvwprintw(win, y, x, "*");
            } else if (y == food_y && x == food_x) {
                mvwprintw(win, y, x, "#");
            } else if (x == X && y == Y) {
                mvwprintw(win, y, x, "0");
            } else {
                mvwprintw(win, y, x, " ");
            }
        }
    }

    mvwprintw(win, height + 1, 0, "Score: %d\n", score);
    mvwprintw(win, height + 2, 0, "Press 'q' to end the game\n");

    wrefresh(win);
}

void create_food () {
    food_x = rand() % height;
    food_y = rand() % width;
}

// Function for the logic behind each and every movement of the snake
void move_snake() {

    switch (flag) {
        case 1: //a
            X--;
            break;
        case 2: //s
            Y++;
            break;
        case 3: //d
            X++;
            break;
        case 4: //w
            Y--;
            break;
        default:
            break;
    }

    // If the game is over
    if (X < 1 || X > width - 2 || Y < 1 || Y > height - 2) game_over = 1;

    // If snake reaches the food then update the score
    if ((X == food_x) && (Y == food_y)) {
        score += 10;
        create_food();
    }
}

int main() { 
    srand(time(NULL));

    WINDOW *win;
    int c;

    // Setup the game
    X = width / 2;
    Y = height / 2;
    score = 0;
    game_over = 0;

    create_food();

    initscr();
    clear();
    win = newwin(height + 5, width + 20, 0, 0);
	keypad(win, TRUE);
    refresh();

    X = height / 2;
    Y = width / 2;

    boundary(win);

    while(1) {
        c = wgetch(win);
		switch(c) {
            case 97: //a
                flag = 1;
                break;
            case 115: //s
                flag = 2;
                break;
            case 100: //d
                flag = 3;
                break;
            case 119: //w
                flag = 4;
                break;
			case 113: //q
                game_over = 1;
				break;
            default:
                break;
		}
        move_snake();
		boundary(win);
		if(game_over == 1) break;
        sleep(0.01);
	}	
    clrtoeol();
	refresh();
    endwin();
    return 0;
}