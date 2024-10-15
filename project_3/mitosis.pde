class Mitosis {
    float x;
    float y;
    float r;

    Mitosis() {
        x = random(0, width);
        y = random(0, height);
        r = 20;
    }

    void move() {

    }

    void show () {
        fill(255);
        noStroke();
        ellipse(x, y, r, r);
    }
}