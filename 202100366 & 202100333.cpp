/*
* Moon Invaders v1.0.0
*
* Ahmed Tarek - 2021 0 0366
* Amir Raafat - 2021 0 0333
*
*/

#include <cmath>
#include <iostream>
#include <windows.h>
#include <GL/glut.h>
using namespace std;

// Rocket
float rocketX = 325.0f;
float rocketY = 0.0f;

// Obstacles
float object1Random = 0.0f;
float object1X = -200.0f;

float object2Random = 0.0f;
float object2X = -100.0f;

float object3Random = 0.0f;
float object3X = 200.0f;

// Speed
float fall = 0.0f;
float speed = 1.0f;
float rotate = 0.0f;

void display();
void moon();
void stars();
void rocket();
void obstacle();

void animation();
void special_keyboard(int key, int x, int y);

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Moon Invaders v1.0.0");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowPosition(1000, 500);
    glutInitWindowSize(1000, 500);

    // Set the callback functions
    glutIdleFunc(animation);
    glutDisplayFunc(display);
    glutSpecialFunc(special_keyboard);

    // Initialize OpenGL
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0.0, 1000, 0.0, 1000);

    // Start the main loop
    glutMainLoop();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    moon();
    stars();
    rocket();
    obstacle();

    glFinish();
}

void moon()
{
    glPushMatrix();
    glTranslated(900, 870, 0);
    glRotated(rotate, 0, 0, 1);
    glTranslated(-900, -870, 0);

    glPushMatrix();
    glTranslated(900, 870, 0);
    glColor3f(0.9f, 0.9f, 0.9f);
    GLUquadric* circle = gluNewQuadric();
    gluDisk(circle, 0.0, 200, 64, 1);
    glPopMatrix();

    glBegin(GL_POLYGON);
    glColor3f(0.7f, 0.7f, 0.7f);
    glVertex3f(750.0f, 950.0f, 0.0f);
    glVertex3f(800.0f, 950.0f, 0.0f);
    glVertex3f(800.0f, 920.0f, 0.0f);
    glVertex3f(750.0f, 920.0f, 0.0f);
    glEnd();

    glBegin(GL_POLYGON);
    glVertex3f(850.0f, 800.0f, 0.0f);
    glVertex3f(800.0f, 700.0f, 0.0f);
    glVertex3f(750.0f, 750.0f, 0.0f);
    glVertex3f(770.0f, 900.0f, 0.0f);
    glEnd();
    glPopMatrix();
}

void stars()
{
    glPushMatrix();
    {
        glPointSize(1.5);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        for (int i = 1; i < 35; i++)
        {
            int x = (rand() % 1000);
            int y = (rand() % 1000);
            glVertex3i(x, y, 0);
        }
        glEnd();
    }
    glPopMatrix();
}

void rocket()
{
    glPushMatrix();
    glTranslated(rocketX, rocketY, 0);

    // Rectangle
    glPushMatrix();
    glBegin(GL_POLYGON);
    glColor3f(255.0f, 0.0f, 0.0f);
    glVertex3f(130.0f, 0.0f, 0.0f);
    glVertex3f(170.0f, 0.0f, 0.0f);
    glVertex3f(170.0f, 80.0f, 0.0f);
    glVertex3f(130.0f, 80.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // Middle Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 165.0f, 0.0f);
    glVertex3f(130.0f, 80.0f, 0.0f);
    glVertex3f(170.0f, 80.0f, 0.0f);
    glVertex3f(150.0f, 160.0f, 0.0f);
    glEnd();

    // Left Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 165.0f, 0.0f);
    glVertex3f(130.0f, 0.0f, 0.0f);
    glVertex3f(130.0f, 20.0f, 0.0f);
    glVertex3f(100.0f, 0.0f, 0.0f);
    glEnd();

    // Right Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 165.0f, 0.0f);
    glVertex3f(170.0f, 0.0f, 0.0f);
    glVertex3f(200.0f, 0.0f, 0.0f);
    glVertex3f(170.0f, 20.0f, 0.0f);
    glEnd();

    // Window
    glTranslated(150, 40, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    GLUquadric* circle = gluNewQuadric();
    gluDisk(circle, 0.0, 10, 100, 1);

    glPopMatrix();
}

void obstacle_design(float x,float y)
{
    glPushMatrix();
    glTranslated(x, y, 0);
    glTranslated(0, fall * speed, 0);

    // Right Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 0.0f, 0.0f);
    glVertex3f(260.0f, 300.0f, 0.0f);
    glVertex3f(340.0f, 300.0f, 0.0f);
    glVertex3f(340.0f, 350.0f, 0.0f);
    glEnd();

    // Left Triangle
    glBegin(GL_TRIANGLES);
    glVertex3f(260.0f, 300.0f, 0.0f);
    glVertex3f(340.0f, 300.0f, 0.0f);
    glVertex3f(260.0f, 350.0f, 0.0f);
    glEnd();

    // Middle Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 255.0f, 0.0f);
    glVertex3f(260.0f, 300.0f, 0.0f);
    glVertex3f(340.0f, 300.0f, 0.0f);
    glVertex3f(300.0f, 380.0f, 0.0f);
    glEnd();

    // Orange Circle
    glTranslated(300, 300, 0);
    glColor3f(255.0f, 255.0f, 0.0f);
    GLUquadric* circle = gluNewQuadric();
    gluDisk(circle, 0.0, 40, 100, 1);

    // Red Circle
    glColor3f(255.0f, 0.0f, 0.0f);
    gluDisk(circle, 0.0, 25, 100, 1);

    glPopMatrix();
}

void random_number()
{
    object1Random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
    object2Random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
    object3Random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 500.0));
}

void obstacle()
{
    random_number();
    obstacle_design(object1X, 1000);
    obstacle_design(object2X, 1100);
    obstacle_design(object3X, 1200);
}

void animation()
{
    rotate += 0.02;
    fall -= 0.1;
    // Go back to top
    if ((fall * speed) < -1050)
    {
        fall = 0;
        object1X = object1Random;
        object2X = object2Random;
        object3X = object3Random;
    }
    glutPostRedisplay();
}

void special_keyboard(int key, int x, int y)
{
    switch (key)
    {
        // Movement
    case GLUT_KEY_UP: rocketY += 30; break;
    case GLUT_KEY_DOWN: rocketY -= 30; break;
    case GLUT_KEY_RIGHT: rocketX += 30; break;
    case GLUT_KEY_LEFT: rocketX -= 30; break;

        // Speed
    case GLUT_KEY_F1: speed += 0.1; break;
    case GLUT_KEY_F2: speed -= 0.1; break;
    }
    glutPostRedisplay();
}

// </> with <3 by Ahmed & Amir