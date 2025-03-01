#include <GL/glut.h>

// Sudut rotasi, skala awal, dan posisi translasi
float angle = 0.0f;
float scale = 1.0f;
float maxScale = 2.0f;  // Batas maksimum skala
float minScale = 0.1f;  // Batas minimum skala

// Variabel translasi
float translateX = 0.0f;
float translateY = 0.0f;

// Batas translasi
float maxTranslateX = 0.9f;
float maxTranslateY = 0.9f;

// Fungsi untuk menggambar persegi
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Atur warna persegi
    glColor3f(0.0f, 0.0f, 1.0f);

    // Terapkan rotasi, translasi, dan skala
    glPushMatrix();
    glTranslatef(translateX, translateY, 0.0f); // Translasi
    glRotatef(angle, 0.0f, 0.0f, 1.0f);        // Rotasi
    glScalef(scale, scale, 1.0f);               // Skala

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

// Fungsi untuk menangani input keyboard panah (rotasi dan skala)
void handleSpecialKeypress(int key, int x, int y) {
    switch (key) {
    case GLUT_KEY_LEFT:
        angle += 5.0f;
        break;
    case GLUT_KEY_RIGHT:
        angle -= 5.0f;
        break;
    case GLUT_KEY_UP:
        if (scale < maxScale) scale += 0.1f; // Batas maksimum skala
        break;
    case GLUT_KEY_DOWN:
        if (scale > minScale) scale -= 0.1f; // Batas minimum skala
        break;
    }
    glutPostRedisplay();
}

// Fungsi untuk menangani input keyboard biasa (translasi menggunakan W, A, S, D)
void handleKeypress(unsigned char key, int x, int y) {
    switch (key) {
    case 'w':  // Pindah ke atas
        if (translateY + 0.1f * scale < maxTranslateY) {
            translateY += 0.1f;
        }
        break;
    case 's':  // Pindah ke bawah
        if (translateY - 0.1f * scale > -maxTranslateY) {
            translateY -= 0.1f;
        }
        break;
    case 'a':  // Pindah ke kiri
        if (translateX - 0.1f * scale > -maxTranslateX) {
            translateX -= 0.1f;
        }
        break;
    case 'd':  // Pindah ke kanan
        if (translateX + 0.1f * scale < maxTranslateX) {
            translateX += 0.1f;
        }
        break;
    }
    glutPostRedisplay();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutCreateWindow("Rotasi, Skala, dan Translasi dengan Batas");

    glutDisplayFunc(display);
    glutSpecialFunc(handleSpecialKeypress);  // Input rotasi dan skala (panah)
    glutKeyboardFunc(handleKeypress);        // Input translasi (W, A, S, D)

    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);  // Latar belakang putih
    glutMainLoop();
    return 0;
}
