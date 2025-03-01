#include <GL/glut.h>

// Skala awal
float scale = 1.0f;

// Fungsi untuk menggambar persegi
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Atur warna persegi
    glColor3f(0.0f, 0.0f, 1.0f);

    // Terapkan skala
    glPushMatrix();
    glScalef(scale, scale, 1.0f);

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
    case GLUT_KEY_UP:
        scale += 0.1f;
        break;
    case GLUT_KEY_DOWN:
        if (scale > 0.1f) scale -= 0.1f;
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Scaling");

    glutDisplayFunc(display);
    glutSpecialFunc(handleKeypress);

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Latar belakang putih
    glutMainLoop();
    return 0;
}