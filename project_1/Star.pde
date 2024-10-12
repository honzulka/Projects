class Star {
    float x;
    float y;
    float z;

    float pz;

    Star() {
        x = random(-width, width);
        y = random(-height, height);
        z = random(0, width);
        pz = z;
    }

    void update() {
        z -= speed;
        if(z < 1) {
            x = random(-width, width);
            y = random(-height, height);
            z = width;
            pz = z;
        }
        if (speed < 1) {
            speed = 1;
        } else if (speed > 50) {
            speed = 50;
        }
    }

    void show() {
        fill(255);
        noStroke();

        float sx = map(x / z, 0, 1, 0, width);
        float sy = map(y / z, 0, 1, 0, height);

        //float r = map(z, 0, width, 8, 0);
        //ellipse(sx, sy, r, r);

        
        float px = map(x / pz, 0, 1, 0, width);
        float py = map(y / pz, 0, 1, 0, height);

        pz = z;
        stroke(255);
        line(px, py, sx, sy);
    }
}
