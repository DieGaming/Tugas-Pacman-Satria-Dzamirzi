#include "Map.h"
#include <GL/glut.h>

const int rows = 21;
const int cols = 21;
const float cellSize = 20.0f;

char map[rows][cols + 1] = {
    " ################### ",
    " #........#........# ",
    " #o##.###.#.###.##o# ",
    " #.................# ",
    " #.##.#.#####.#.##.# ",
    " #....#...#...#....# ",
    " ####.### # ###.#### ",
    "    #.#   0   #.#    ",
    "#####.# ##=## #.#####",
    "#   #.  #123#  .#   #",
    "#####.# ##### #.#####",
    "    #.#       #.#    ",
    " ####.# ##### #.#### ",
    " #........#........# ",
    " #.##.###.#.###.##.# ",
    " #o.#.....P.....#.o# ",
    " ##.#.#.#####.#.#.## ",
    " #....#...#...#....# ",
    " #.######.#.######.# ",
    " #.................# ",
    " ################### "
};

void drawCell(float x, float y, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_QUADS);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

void drawMap() {
    for (int row = 0; row < rows; row++) {
        for (int col = 0; col < cols; col++) {
            float x = col * cellSize;
            float y = (rows - row - 1) * cellSize;

            switch (map[row][col]) {
                case '#': drawCell(x, y, cellSize, 0.0f, 0.0f, 1.0f); break;
                case '.': drawCell(x, y, cellSize, 1.0f, 1.0f, 1.0f); break;
                case 'o': drawCell(x, y, cellSize, 1.0f, 1.0f, 0.0f); break;
                case '=': drawCell(x, y, cellSize, 0.0f, 1.0f, 0.0f); break;
                default: break;
            }
        }
    }
}

int getRows() { return rows; }
int getCols() { return cols; }
float getCellSize() { return cellSize; }
