#include <windows.h>
#include <GL/glut.h>
#include <cmath>  

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    glColor3f(1.0, 0.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, 0.6);
    glVertex2f(-0.4, 0.6);
    glVertex2f(-0.4, 0.2);
    glVertex2f(-0.8, 0.2);
    glEnd();


    glColor3f(0.0, 1.0, 0.0);
    glBegin(GL_QUADS);
    glVertex2f(-0.8, -0.2);
    glVertex2f(-0.4, -0.2);
    glVertex2f(-0.4, -0.6);
    glVertex2f(-0.8, -0.6);
    glEnd();


    glColor3f(1.0, 1.0, 0.0);
    glBegin(GL_POLYGON);
    for (int i = 0; i < 6; i++) {
        glVertex2f(0.2 * cos(i * 2.0 * 3.1415926 / 6) + 0.6, 0.2 * sin(i * 2.0 * 3.1415926 / 6) + 0.6);
    }
    glEnd();


    glColor3f(0.0, 0.0, 1.0);
    glBegin(GL_TRIANGLES);
    glVertex2f(0.0, 0.0);
    glVertex2f(-0.2, 0.4);
    glVertex2f(0.2, 0.4);
    glEnd();


    glBegin(GL_TRIANGLES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex2f(0.1, 0.3);
    glColor3f(0.0, 1.0, 0.0);
    glVertex2f(-0.1, -0.1);
    glColor3f(0.0, 0.0, 1.0);
    glVertex2f(0.3, -0.1);
    glEnd();


    glBegin(GL_QUADS);
    glColor3f(0.0, 0.0, 0.0);
    glVertex2f(-0.7, -0.3);
    glColor3f(1.0, 1.0, 1.0);
    glVertex2f(-0.5, -0.3);
    glColor3f(0.7, 0.7, 0.7);
    glVertex2f(-0.5, -0.1);
    glColor3f(0.3, 0.3, 0.3);
    glVertex2f(-0.7, -0.1);
    glEnd();

    glFlush();
}

void init() {
    glClearColor(0.0, 0.0, 0.0, 1.0);
    glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("Overlapping Triangles and Gradient Square");
    init();
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}