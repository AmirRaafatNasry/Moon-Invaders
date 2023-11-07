#include <GL/glut.h>
#include <math.h>

float squareX = 0;
float squareY = 0;
float triangleX = 0;
float triangleY = 0;

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslated(squareX, squareY, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(200.0f, 200.0f);
    glVertex2f(200.0f, 400.0f);
    glVertex2f(400.0f, 400.0f);
    glVertex2f(400.0f, 200.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(triangleX, triangleY, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(225.0f, 300.0f);
    glVertex2f(350.0f, 250.0f);
    glVertex2f(350.0f, 350.0f);
    glEnd();
    glPopMatrix();

    glFlush();
}

// Arrows
void specialFunc(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        squareY += 50.0f;
        break;
    case GLUT_KEY_DOWN:
        squareY -= 50.0f;
        break;
    case GLUT_KEY_RIGHT:
        squareX += 50.0f;
        break;
    case GLUT_KEY_LEFT:
        squareX -= 50.0f;
        break;
    }
    glutPostRedisplay();
}
void special_keyboard_up(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        squareY = 0;
    }
    glutPostRedisplay();
}

// WASD
void keyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'a':
        triangleX -= 50.0f;
        break;
    case 'd':
        triangleX += 50.0f;
        break;
    case 'w':
        triangleY += 50.0f;
        break;
    case 's':
        triangleY -= 50.0f;
        break;
    }
    glutPostRedisplay();
}
void my_keyboard_up(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 'w':
        triangleY = 0; //Return back after jump
    }
    glutPostRedisplay();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(1400, 295);

    glutCreateWindow("Task 3");
    glutDisplayFunc(Display);
    glutSpecialFunc(specialFunc);
    glutSpecialUpFunc(special_keyboard_up);
    glutKeyboardFunc(keyboardFunc);
    glutKeyboardUpFunc(my_keyboard_up);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0, 600, 0, 600);
    glutMainLoop();
}