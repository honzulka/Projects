Mitosis cell;

void setup() {
    size(800, 800);
    cell = new Mitosis();
}

void draw() {
    background(51);
    cell.move();
    cell.show();
}