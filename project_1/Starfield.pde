Star[] stars = new Star[800];
float speed = 10;

void setup() {
    size(800, 800);
    for (int i = 0; i < stars.length; ++i) {
        stars[i] = new Star();
    }
}

void keyPressed() {
    if (key == CODED) {
        if (keyCode == UP || keyCode == RIGHT) {
        speed += 1;
        } else if (keyCode == DOWN || keyCode == LEFT) {
        speed -= 1;
        }
    }
}

void draw() {
    background(0);
    translate(width / 2, height / 2);
    for (int i = 0; i < stars.length; ++i) {
        stars[i].update();
        stars[i].show();
    }
}