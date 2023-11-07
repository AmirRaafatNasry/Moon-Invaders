#include <GL/glut.h>
#include <math.h>

float characterX = 0.0;
float characterY = 0.0;

float rectangleX = 0.0;
float rectangleY = 0.0;

float direction = 1.0;

// Initialize variables
float bulletX = 0.0;
float bulletY = 0.0;
bool isBulletFired;

void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix(); // Crosswalks
    glTranslated(rectangleX, rectangleY, 0);
    glBegin(GL_POLYGON);
    glColor3f(160.0f, 150.0f, 150.0f);
    glVertex3f(120.0f, 120.0f, 0.0f);
    glVertex3f(120.0f, 250.0f, 0.0f);
    glVertex3f(180.0f, 250.0f, 0.0f);
    glVertex3f(180.0f, 120.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // Crosswalks
    glTranslated(rectangleX, rectangleY, 0);
    glBegin(GL_POLYGON);
    glColor3f(160.0f, 150.0f, 150.0f);
    glVertex3f(320.0f, 120.0f, 0.0f);
    glVertex3f(320.0f, 250.0f, 0.0f);
    glVertex3f(380.0f, 250.0f, 0.0f);
    glVertex3f(380.0f, 120.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // Character
    glTranslated(characterX, characterY, 0);
    glBegin(GL_POLYGON);
    glColor3f(160.0f, 150.0f, 150.0f);
    glVertex3f(200.0f, 75.0f, 0.0f);
    glVertex3f(200.0f, 0.0f, 0.0f);
    glVertex3f(300.0f, 0.0f, 0.0f);
    glVertex3f(300.0f, 75.0f, 0.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix(); // Character
    glTranslated(characterX, characterY, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex3f(250.0f, 0.0f, 0.0f);
    glVertex3f(200.0f, 75.0f, 0.0f);
    glVertex3f(300.0f, 75.0f, 0.0f);
    glEnd();
    glPopMatrix();

    if (isBulletFired) // Bullet
    {
        glPushMatrix();
        glTranslated(bulletX, bulletY, 0);
        glColor3f(160.0f, 150.0f, 150.0f);
        GLUquadric* quadric = gluNewQuadric();
        gluDisk(quadric, 0, 10, 100, 1);
        glEnd();
        glPopMatrix();
    }

    glFlush();
}

// Arrows
void special_keyboard(int key, int x, int y)
{
    switch (key)
    {
    case GLUT_KEY_UP:
        characterY += 50;
        break;
    case GLUT_KEY_DOWN:
        characterY -= 50;
        break;
    case GLUT_KEY_RIGHT:
        characterX += 50;
        break;
    case GLUT_KEY_LEFT:
        characterX -= 50;
        break;
    }
    glutPostRedisplay();
}

void timer_function(int value)
{
    rectangleY += value * direction;
    if (rectangleY > 250)
        rectangleY = -250;

    //bullet
    if (isBulletFired)
    {
        bulletY += 35;
        if (bulletY >= 1000)
            isBulletFired = false;
    }
    glutPostRedisplay();
    glutTimerFunc(30, timer_function, 10);
}

void mouse_function(int button, int state, int x, int y)
{
    if (state == GLUT_DOWN)
    {
        switch (button)
        {
        case GLUT_LEFT_BUTTON:
            if (isBulletFired == false)
            {
                bulletX = characterX + 250;
                bulletY = characterY;
                isBulletFired = true;
            }
        }
    }
    glutPostRedisplay();
}

int main(int argc, char** argr)
{
    glutInit(&argc, argr);

    glutInitWindowSize(1000, 800);
    glutInitWindowPosition(550, 100);

    glutCreateWindow("Task 4");
    glutDisplayFunc(Display);

    glutSpecialFunc(special_keyboard);
    glutMouseFunc(mouse_function);
    glutTimerFunc(0, timer_function, 0);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0, 500, 0, 400);

    glutMainLoop();
}