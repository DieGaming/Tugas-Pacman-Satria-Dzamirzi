#include "Pacman.h"
#include "Map.h"
#include <GL/glut.h>

int pacX, pacY;

void initPacman() {
    for (int row = 0; row < getRows(); row++) {
        for (int col = 0; col < getCols(); col++) {
            if (map[row][col] == 'P') {
                pacX = col;
                pacY = row;
                return;
            }
        }
    }
}

void drawPacman() {
    float pacXPos = pacX * getCellSize();
    float pacYPos = (getRows() - pacY - 1) * getCellSize();
    drawCell(pacXPos, pacYPos, getCellSize(), 1.0f, 1.0f, 0.0f);
}

void movePacman(int dx, int dy) {
    int newX = pacX + dx;
    int newY = pacY + dy;

    if (map[newY][newX] != '#') {
        map[pacY][pacX] = ' ';
        pacX = newX;
        pacY = newY;
        map[pacY][pacX] = 'P';
    }
}
