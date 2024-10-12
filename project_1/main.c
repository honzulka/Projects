#include <stdio.h>
#include <stdlib.h> 
#include <time.h>

typedef struct Star {
    int x;
    int y;
} Star;

void create_random_star(int width, int height, Star *star) {
    star->x = rand() % (width + 1); 
    star->y = rand() % (height + 1);
}

int main() {
    printf("\n");
    srand ( time(NULL));
    struct Star *stars = (struct Star*)malloc(10 * sizeof(struct Star));
    if (stars == NULL) return -1;

    for (int i = 0; i < 10; i++)
    {
        create_random_star(500, 500, &stars[i]);
    }
    
    for (int i = 0; i < 10; i++)
    {
        printf("star: [%d, %d]\n", stars[i].x, stars[i].y);
    }
    
    free(stars);
    
    return 0;
}