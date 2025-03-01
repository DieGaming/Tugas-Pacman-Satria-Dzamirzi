#include <windows.h>
#include <GL/glut.h>

// Variables for square position
float posX = 0.0f;
float posY = 0.0f;

// Variables for target position (mouse click position)
float targetX = 0.0f;
float targetY = 0.0f;
bool moving = false;

// Function to draw colored square with center at (x, y)
void drawColoredSquare(float x, float y, float width, float height, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    // Adjust vertices to center the square at (x, y)
    glVertex2f(x - width / 2.0f, y - height / 2.0f);  // Bottom-left
    glVertex2f(x + width / 2.0f, y - height / 2.0f);  // Bottom-right
    glVertex2f(x + width / 2.0f, y + height / 2.0f);  // Top-right
    glVertex2f(x - width / 2.0f, y + height / 2.0f);  // Top-left
    glEnd();
}

// Function to handle mouse click
void mouseClick(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert mouse coordinates to OpenGL coordinates
        targetX = (float)x / (glutGet(GLUT_WINDOW_WIDTH) / 2.0f) - 1.0f;
        targetY = -((float)y / (glutGet(GLUT_WINDOW_HEIGHT) / 2.0f) - 1.0f);
        moving = true;  // Set moving flag to true
    }
}

// Function to update the position of the square
void update(int value) {
    if (moving) {
        // Move square towards the target position
        float speed = 0.01f; // Adjust the speed as necessary
        if (posX < targetX) posX += speed;
        if (posX > targetX) posX -= speed;
        if (posY < targetY) posY += speed;
        if (posY > targetY) posY -= speed;

        // Stop moving if close to target
        if (abs(posX - targetX) < 0.01f && abs(posY - targetY) < 0.01f) {
            moving = false;
        }
    }
    glutPostRedisplay();  // Re-draw the window
    glutTimerFunc(16, update, 0); // Schedule next update
}

// Function to display the scene
void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw a colored square at the current position, centered at (posX, posY)
    drawColoredSquare(posX, posY, 0.1f, 0.15f, 1.0f, 0.0f, 0.0f);

    glutSwapBuffers();
}

// Initialization function
void init() {
    // Set background color to black
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);
}

// Function to maintain 16:9 aspect ratio when window is resized
void reshape(int width, int height) {
    if (height == 0) height = 1;  // Prevent division by zero
    float aspect = (float)width / (float)height;

    // Set viewport to the entire window
    glViewport(0, 0, width, height);

    // Set projection matrix
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    if (aspect >= 16.0f / 9.0f) {
        // Wider aspect, adjust height
        gluOrtho2D(-aspect, aspect, -1.0f, 1.0f);
    } else {
        // Taller aspect, adjust width
        gluOrtho2D(-1.0f, 1.0f, -1.0f / aspect * 9.0f / 16.0f, 1.0f / aspect * 9.0f / 16.0f);
    }

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

// Main function
int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);

    // Set window size with 16:9 ratio
    glutInitWindowSize(1280, 720);
    glutCreateWindow("Move Square to Mouse Click - Centered Anchor");

    init();

    glutDisplayFunc(display);
    glutMouseFunc(mouseClick);
    glutTimerFunc(16, update, 0); // Call update function every 16ms

    glutMainLoop();
    return 0;
}
