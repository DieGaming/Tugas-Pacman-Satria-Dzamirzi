#include <windows.h>
#include <GL/glut.h>
#include <cmath>

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

// Fungsi untuk menggambar segitiga siku-siku
void drawTriangle(float x1, float y1, float x2, float y2, float x3, float y3, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_TRIANGLES);
    glVertex2f(x1, y1);
    glVertex2f(x2, y2);
    glVertex2f(x3, y3);
    glEnd();
}

// Fungsi untuk menggambar lingkaran
void drawCircle(float x, float y, float radius, int segments, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    for (int i = 0; i < segments; i++) {
        float theta = 2.0f * 3.1415926f * float(i) / float(segments); // Sudut tiap segmen
        float dx = radius * cosf(theta); // X untuk titik lingkaran
        float dy = radius * sinf(theta); // Y untuk titik lingkaran
        glVertex2f(x + dx, y + dy);
    }
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
// Segitiga di atas telinga kiri
drawTriangle(-0.2f, 0.85f, -0.25f, 0.75f, -0.2f, 0.75f, 0.5f, 0.5f, 0.5f); // Atas
// Segitiga di bawah telinga kiri
drawTriangle(-0.2f, 0.7f, -0.25f, 0.8f, -0.2f, 0.8f, 0.5f, 0.5f, 0.5f); // Bawah

// Telinga kanan (Abu-abu)
drawRectangle(0.15f, 0.7f, 0.05f, 0.1f, 0.5f, 0.5f, 0.5f);
// Segitiga di atas telinga kanan
drawTriangle(0.2f, 0.9f, 0.3f, 0.8f, 0.2f, 0.75f, 0.5f, 0.5f, 0.5f); // Atas
// Segitiga di bawah telinga kanan
drawTriangle(0.2f, 0.7f, 0.25f, 0.8f, 0.2f, 0.8f, 0.5f, 0.5f, 0.5f); // Bawah

    // Mata (Hitam)
    drawRectangle(-0.1f, 0.75f, 0.05f, 0.05f, 0.0f, 0.0f, 0.0f); // Mata kiri
    drawRectangle(0.05f, 0.75f, 0.05f, 0.05f, 0.0f, 0.0f, 0.0f);  // Mata kanan

    // Alis (Hitam)
    drawRectangle(-0.105f, 0.82f, 0.06f, 0.02f, 0.0f, 0.0f, 0.0f);  // Alis kiri
    drawRectangle(0.055f, 0.82f, 0.06f, 0.02f, 0.0f, 0.0f, 0.0f);   // Alis kanan

    // Tanda Dahi (Merah)
    drawRectangle(-0.03f, 0.87f, 0.06f, 0.02f, 1.0f, 0.0f, 0.0f); // Tanda dahi

    // Mulut (Pink)
    drawRectangle(-0.05f, 0.65f, 0.1f, 0.05f, 1.0f, 0.75f, 0.8f);

    // Tubuh (Biru tua)
    drawRectangle(-0.2f, 0.1f, 0.4f, 0.5f, 0.0f, 0.0f, 0.5f);

    // Lengan kiri (Abu-abu dan merah)
    drawRectangle(-0.35f, 0.5f, 0.15f, 0.1f, 0.5f, 0.5f, 0.5f); // Abu-abu
    drawRectangle(-0.35f, 0.6f, 0.1f, 0.2f, 0.8f, 0.0f, 0.0f);  // Merah
    drawRectangle(-0.35f, 0.8f, 0.1f, 0.05f, 0.0f, 1.0f, 1.0f); // Ujung lengan hijau muda

    // Lingkaran di siku kiri
    drawCircle(-0.275f, 0.55f, 0.05f, 50, 0.0f, 0.0f, 0.0f); // Lingkaran hitam di siku kiri

    // Lengan kanan (Abu-abu dan merah)
    drawRectangle(0.2f, 0.5f, 0.15f, 0.1f, 0.5f, 0.5f, 0.5f); // Abu-abu
    drawRectangle(0.25f, 0.3f, 0.1f, 0.2f, 0.8f, 0.0f, 0.0f); // Merah
    drawRectangle(0.25f, 0.25f, 0.1f, 0.05f, 0.0f, 1.0f, 1.0f); // Ujung lengan hijau muda

    // Lingkaran di siku kanan
    drawCircle(0.275f, 0.55f, 0.05f, 50, 0.0f, 0.0f, 0.0f); // Lingkaran hitam di siku kanan

    // Ikat pinggang (Abu-abu tua)
    drawRectangle(-0.25f, 0.1f, 0.5f, 0.1f, 0.2f, 0.2f, 0.2f);

    // Motif zebra pada sabuk secara vertikal
    float stripeWidth = 0.02f; // Lebar garis
    for (float x = -0.25f; x < 0.25f; x += stripeWidth) {
        if (static_cast<int>((x + 0.25) / stripeWidth) % 2 == 0) {
            drawRectangle(x, 0.1f, stripeWidth, 0.1f, 1.0f, 1.0f, 1.0f); // Garis putih
        } else {
            drawRectangle(x, 0.1f, stripeWidth, 0.1f, 0.0f, 0.0f, 0.0f); // Garis hitam
        }
    }

    // Kaki kiri (Abu-abu tua)
    drawRectangle(-0.18f, -0.3f, 0.1f, 0.4f, 0.2f, 0.2f, 0.2f);

    // Tambahkan lingkaran di lutut kiri
    drawCircle(-0.13f, -0.15f, 0.05f, 50, 0.0f, 0.0f, 0.0f); // Lingkaran hitam di lutut kiri

    // Kaki kanan (Abu-abu tua)
    drawRectangle(0.08f, -0.3f, 0.1f, 0.4f, 0.2f, 0.2f, 0.2f);

    // Tambahkan lingkaran di lutut kanan
    drawCircle(0.13f, -0.15f, 0.05f, 50, 0.0f, 0.0f, 0.0f); // Lingkaran hitam di lutut kanan

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
    glutCreateWindow("Robot OpenGL dengan Segitiga Siku-siku di Telinga");
    glutInitWindowSize(500, 500);
    glutDisplayFunc(display);
    init();
    glutMainLoop();
    return 0;
}

