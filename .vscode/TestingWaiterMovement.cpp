#include <windows.h>
#include <GL/glut.h>
#include <cmath>
#include <string>

// Hexagon position
float hexagonX = 0.4f, hexagonY = 0.55f;
float targetX, targetY;  // Target position (clicked location)
bool isMoving = false;   // Is the hexagon currently moving?

// Square position and size
float squareX = -0.5f, squareY = 0.0f;  // Green square
float squareSize = 0.2f;
bool isDragging = false;  // To track if the square is being dragged

// Store original position for snapping back
float originalSquareX = squareX;
float originalSquareY = squareY;

// Brown square position and size
float brownSquareX = 0.5f, brownSquareY = -0.5f;  // Brown square
float brownSquareSize = 0.2f;

// Speed of movement
const float speed = 0.02f;

// Score text
int score = 0;  // Score increases when the hexagon collides with the square

// Function to draw a hexagon
void drawHexagon(float x, float y, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x + size, y);  // Right point
    glVertex2f(x + size / 2, y - size);  // Bottom right
    glVertex2f(x - size / 2, y - size);  // Bottom left
    glVertex2f(x - size, y);  // Left point
    glVertex2f(x - size / 2, y + size);  // Top left
    glVertex2f(x + size / 2, y + size);  // Top right
    glEnd();
}

// Function to draw a square
void drawSquare(float x, float y, float size, float r, float g, float b) {
    glColor3f(r, g, b);
    glBegin(GL_POLYGON);
    glVertex2f(x, y);
    glVertex2f(x + size, y);
    glVertex2f(x + size, y + size);
    glVertex2f(x, y + size);
    glEnd();
}

// Function to render text at a specified position
void renderText(float x, float y, std::string text) {
    glColor3f(1.0f, 1.0f, 1.0f);  // Text color (white)
    glRasterPos2f(x, y);  // Set the position to start drawing text
    for (char& c : text) {
        glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18, c);  // Use Helvetica font
    }
}

// Check collision between two squares
bool checkCollision(float x1, float y1, float size1, float x2, float y2, float size2) {
    return (x1 < x2 + size2 && x1 + size1 > x2 && y1 < y2 + size2 && y1 + size1 > y2);
}

// Function to update the hexagon's position as it moves
void updatePosition(int value) {
    if (isMoving) {
        // Calculate direction vector (dx, dy)
        float dx = targetX - hexagonX;
        float dy = targetY - hexagonY;

        // Calculate distance to target
        float distance = sqrt(dx * dx + dy * dy);

        // Check if we are close enough to the target
        if (distance < 0.01f) {
            isMoving = false;  // Stop moving
        } else {
            // Normalize direction and update position
            hexagonX += (dx / distance) * speed;
            hexagonY += (dy / distance) * speed;
        }

        // Check for collision between hexagon and green square
        if (checkCollision(hexagonX - 0.05f, hexagonY - 0.05f, 0.1f, squareX, squareY, squareSize)) {
            score++;  // Increase score when collision occurs
            isMoving = false;  // Stop hexagon after collision
        }

        // Check for collision between green square and brown square
        if (checkCollision(squareX, squareY, squareSize, brownSquareX, brownSquareY, brownSquareSize)) {
            // Snap the green square to the designated position (brown square's position)
            squareX = brownSquareX;  
            squareY = brownSquareY;  
        }

        glutPostRedisplay();  // Redraw the scene with updated hexagon position
    }

    // Call the updatePosition function again after 16 milliseconds (~60 FPS)
    glutTimerFunc(16, updatePosition, 0);
}

// Function to update the position of the square when dragged
void updateSquarePosition(int x, int y) {
    squareX = (float)x / 250 - 1;  // Convert mouse x to OpenGL x-coordinate
    squareY = 1 - (float)y / 250;  // Convert mouse y to OpenGL y-coordinate
    glutPostRedisplay();  // Redraw the scene with updated square position
}

void display() {
    glClear(GL_COLOR_BUFFER_BIT);

    // Draw the hexagon with updated position
    drawHexagon(hexagonX, hexagonY, 0.1f, 1.0f, 1.0f, 0.0f);  // Yellow hexagon

    // Draw the green square
    drawSquare(squareX, squareY, squareSize, 0.0f, 1.0f, 0.0f);  // Green square

    // Draw the brown square
    drawSquare(brownSquareX, brownSquareY, brownSquareSize, 0.5f, 0.25f, 0.0f);  // Brown square

    // Draw the score text
    renderText(-0.95f, 0.9f, "Score: " + std::to_string(score));  // Display score

    glFlush();
}

// Mouse click and drag handler
void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
        // Convert window coordinates to OpenGL coordinates for the hexagon
        targetX = (float)x / 250 - 1;
        targetY = 1 - (float)y / 250;

        // Set the hexagon to move towards the clicked position
        isMoving = true;
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN) {
        // Check if the click is inside the green square to start dragging
        float mouseX = (float)x / 250 - 1;
        float mouseY = 1 - (float)y / 250;
        if (mouseX > squareX && mouseX < squareX + squareSize &&
            mouseY > squareY && mouseY < squareY + squareSize) {
            isDragging = true;
        }
    }

    if (button == GLUT_RIGHT_BUTTON && state == GLUT_UP) {
        isDragging = false;  // Stop dragging when the button is released

        // Snap the square back to its original position
        squareX = originalSquareX;
        squareY = originalSquareY;

        glutPostRedisplay();  // Redraw the scene after snapping back
    }
}

// Mouse motion handler (for dragging)
void motion(int x, int y) {
    if (isDragging) {
        updateSquarePosition(x, y);  // Update square's position when dragging
    }
}

void init() {
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);  // Background color
    glOrtho(-1, 1, -1, 1, -1, 1);  // Orthographic projection
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(50, 50);
    glutCreateWindow("Hexagon Moving and Square Dragging with Collision and Snap-back");
    init();
    glutDisplayFunc(display);
    glutMouseFunc(mouse);         // Register mouse click event
    glutMotionFunc(motion);       // Register motion event for dragging
    glutTimerFunc(16, updatePosition, 0);  // Call update function every 16 milliseconds
    glutMainLoop();
    return 0;
}
