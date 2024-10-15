class Mitosis {
    float x;
    float y;
    float r;

    Mitosis() {
        r = 80;
        x = random(r, width - r);
        y = random(r, height - r);
    }

    void move() {
        x += random(-1, 1);
        y += random(-1, 1);
    }

    void show () {
        fill(100, 50, 0);
        noStroke();
        ellipse(x, y, r, r);
    }

    boolean clicked(float mouse_x, float mouse_y) {
        float d = dist(x, y, mouse_x, mouse_y);
        return (d < r / 2);
    }

    void mitosis(float pos_x, float pos_y) {
        float offset = random(-r/2, r/2);
        x = pos_x + offset;
        y = pos_y + offset;
        r = r / sqrt(2);
    }
}