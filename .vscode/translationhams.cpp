#include <GL/glut.h>

// Posisi awal objek
float posX = 0.0f, posY = 0.0f;

// Fungsi untuk menggambar persegi
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Atur warna persegi
    glColor3f(0.0f, 0.0f, 1.0f);

    // Terapkan translasi
    glPushMatrix();
    glTranslatef(posX, posY, 0.0f);

    // Gambar persegi
    glBegin(GL_QUADS);
    glVertex2f(-0.1f, -0.1f);
    glVertex2f(0.1f, -0.1f);
    glVertex2f(0.1f, 0.1f);
    glVertex2f(-0.1f, 0.1f);
    glEnd();

    glPopMatrix();
    glFlush();
}

// Fungsi untuk menangani input keyboard
void handleKeypress(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        posX -= 0.1f;
        break;
    case GLUT_KEY_RIGHT:
        posX += 0.1f;
        break;
    case GLUT_KEY_UP:
        posY += 0.1f;
        break;
    case GLUT_KEY_DOWN:
        posY -= 0.1f;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Translation");

    glutDisplayFunc(display);
    glutSpecialFunc(handleKeypress);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Latar belakang putih
    glutMainLoop();
    return 0;
}