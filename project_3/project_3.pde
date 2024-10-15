Mitosis[] cells = new Mitosis[50];
int counter = 0;

void setup() {
    size(800, 800);
    cells[0] = new Mitosis();
    counter++;
}

void draw() {
    background(51);
    for (int i = 0; i < counter; i++) {
        cells[i].move();
        cells[i].show();
    }
}

void mousePressed() {
    for (int i = 0; i < counter; i++) {
        if(cells[i].clicked(mouseX, mouseY) && counter != 35) {
            process_mitosis(mouseX, mouseY, i);
            return;
        }
    }
}

void process_mitosis(float x, float y, int index) {
    Mitosis cellA = new Mitosis();
    Mitosis cellB = new Mitosis();
    cellA.mitosis(x, y);
    cellB.mitosis(x, y);
    cells[index] = cellA;
    cells[index + 1] = cellB;
    counter++;
}