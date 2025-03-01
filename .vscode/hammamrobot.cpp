#include <windows.h>
#include <GL/glut.h>

// Fungsi untuk menggambar persegi panjang
void drawRectangle(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + width, y);
    glVertex2f(x + width, y + height);
    glVertex2f(x, y + height);
    glEnd();
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Latar belakang biru muda
    glClearColor(0.678, 0.847, 0.902, 1.0); // Warna biru muda
    glClear(GL_COLOR_BUFFER_BIT);

    // Kepala (Cream)
    drawRectangle(-0.15f, 0.6f, 0.3f, 0.3f, 1.0f, 0.992f, 0.816f);

    // Telinga kiri (Abu-abu)
    drawRectangle(-0.2f, 0.7f, 0.05f, 0.1f, 0.5f, 0.5f, 0.5f);

    // Telinga kanan (Abu-abu)
    drawRectangle(0.15f, 0.7f, 0.05f, 0.1f, 0.5f, 0.5f, 0.5f);

    // Mata (Hitam)
    drawRectangle(-0.1f, 0.75f, 0.05f, 0.05f, 0.0f, 0.0f, 0.0f); // Mata kiri
    drawRectangle(0.05f, 0.75f, 0.05f, 0.05f, 0.0f, 0.0f, 0.0f);  // Mata kanan

    // Alis (Hitam)
    drawRectangle(-0.105f, 0.82f, 0.06f, 0.02f, 0.0f, 0.0f, 0.0f);  // Alis kiri
    drawRectangle(0.055f, 0.82f, 0.06f, 0.02f, 0.0f, 0.0f, 0.0f);   // Alis kanan

    // Mulut (Pink)
    drawRectangle(-0.05f, 0.65f, 0.1f, 0.05f, 1.0f, 0.75f, 0.8f);

    // Tubuh (Biru tua)
    drawRectangle(-0.2f, 0.1f, 0.4f, 0.5f, 0.0f, 0.0f, 0.5f);

    // Lengan kiri (Abu-abu dan merah)
    drawRectangle(-0.35f, 0.5f, 0.15f, 0.1f, 0.5f, 0.5f, 0.5f); // Abu-abu
    drawRectangle(-0.35f, 0.6f, 0.1f, 0.2f, 0.8f, 0.0f, 0.0f);  // Merah
    drawRectangle(-0.35f, 0.8f, 0.1f, 0.05f, 0.0f, 1.0f, 1.0f); // Ujung lengan hijau muda

    // Lengan kanan (Abu-abu dan merah)
    drawRectangle(0.2f, 0.5f, 0.15f, 0.1f, 0.5f, 0.5f, 0.5f); // Abu-abu
    drawRectangle(0.25f, 0.3f, 0.1f, 0.2f, 0.8f, 0.0f, 0.0f); // Merah
    drawRectangle(0.25f, 0.25f, 0.1f, 0.05f, 0.0f, 1.0f, 1.0f); // Ujung lengan hijau muda

    // Ikat pinggang (Abu-abu tua)
    drawRectangle(-0.25f, 0.1f, 0.5f, 0.1f, 0.2f, 0.2f, 0.2f);

    // Kaki kiri (Abu-abu tua)
    drawRectangle(-0.18f, -0.3f, 0.1f, 0.4f, 0.2f, 0.2f, 0.2f);

    // Kaki kanan (Abu-abu tua)
    drawRectangle(0.08f, -0.3f, 0.1f, 0.4f, 0.2f, 0.2f, 0.2f);

    // Sepatu kiri (Merah)
    drawRectangle(-0.18f, -0.4f, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f);

    // Sepatu kanan (Merah)
    drawRectangle(0.08f, -0.4f, 0.1f, 0.1f, 0.7f, 0.0f, 0.0f);

    // Celana (Biru) KIRI
    drawRectangle(-0.2f, -0.1f, 0.15f, 0.2f, 0.0f, 0.0f, 0.5f);

    // Celana (Biru) kanan
    drawRectangle(0.05f, -0.1f, 0.15f, 0.2f, 0.0f, 0.0f, 0.5f);

    glFlush();
}

void init() {
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f); // Background putih
    glMatrixMode(GL_PROJECTION);
    gluOrtho2D(-1.0, 1.0, -1.0, 1.0);
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutCreateWindow("Robot OpenGL dengan Celana Biru dan Alis");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}