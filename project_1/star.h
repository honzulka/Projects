#include <stdio.h>

#ifndef _ERROR_H
#define _ERROR_H

#define OK 0
#define ERROR 1

typedef struct Star {
    int x;
    int y;
    int z;
} Star;

void create_random_star (int width, int height, Star *star);

#endif