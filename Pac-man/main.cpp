#include <GL/glut.h>
#include "Map.h"
#include "Pacman.h"

void display() {
    glClear(GL_COLOR_BUFFER_BIT);
    drawMap();
    drawPacman();
    glutSwapBuffers();
}

void keyboard(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_UP:    movePacman(0, -1); break;
    case GLUT_KEY_DOWN:  movePacman(0, 1); break;
    case GLUT_KEY_LEFT:  movePacman(-1, 0); break;
    case GLUT_KEY_RIGHT: movePacman(1, 0); break;
    }
    glutPostRedisplay(); // Refresh the screen after movement
}

void init() {
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, getCols() * getCellSize(), 0, getRows() * getCellSize());
    glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(getCols() * getCellSize(), getRows() * getCellSize());
    glutCreateWindow("Pac-Man Game");

    initMap();
    initPacman();
    init();

    glutDisplayFunc(display);
    glutSpecialFunc(keyboard);
    glutMainLoop();
    return 0;
}
