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
float rocket_x = 325.0f;
float rocket_y = 0.0f;

// Obstacles
float object1_random = 0.0f;
float object1_x = -200.0f;

float object2_random = 0.0f;
float object2_x = -100.0f;

float object3_random = 0.0f;
float object3_x = 200.0f;

// Speed
float fall = 0.0f;
float speed = 1.0f;
float rotate = 0.0f;

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
    glTranslated(rocket_x, rocket_y, 0);

    // Rectangle
    glPushMatrix();
    glTranslated(130, 110, 0);
    glTranslated(-130, -110, 0);
    glBegin(GL_POLYGON);
    glColor3f(255.0f, 0.0f, 0.0f);
    glVertex3f(130.0f, 110.0f, 0.0f);
    glVertex3f(170.0f, 110.0f, 0.0f);
    glVertex3f(170.0f, 190.0f, 0.0f);
    glVertex3f(130.0f, 190.0f, 0.0f);
    glEnd();
    glPopMatrix();

    // Middle Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 165.0f, 0.0f);
    glVertex3f(130.0f, 190.0f, 0.0f);
    glVertex3f(170.0f, 190.0f, 0.0f);
    glVertex3f(150.0f, 250.0f, 0.0f);
    glEnd();

    // Left Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 165.0f, 0.0f);
    glVertex3f(130.0f, 110.0f, 0.0f);
    glVertex3f(130.0f, 130.0f, 0.0f);
    glVertex3f(100.0f, 110.0f, 0.0f);
    glEnd();

    // Right Triangle
    glBegin(GL_TRIANGLES);
    glColor3f(255.0f, 165.0f, 0.0f);
    glVertex3f(170.0f, 110.0f, 0.0f);
    glVertex3f(200.0f, 110.0f, 0.0f);
    glVertex3f(170.0f, 130.0f, 0.0f);
    glEnd();

    // Window
    glTranslated(150, 150, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    GLUquadric* circle = gluNewQuadric();
    gluDisk(circle, 0.0, 10, 64, 1);

    glPopMatrix();
}

void obstacle_design()
{
    glPushMatrix();

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
    object1_random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
    object2_random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
    object3_random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 500.0));
}

void obstacle()
{
    random_number();

    glPushMatrix();
    glTranslated(500, 1000, 0);
    glTranslated(-500, -1000, 0);
    glTranslated(object1_x, 1050, 0);
    glTranslated(0, fall * speed, 0);
    obstacle_design();
    glPopMatrix();

    glPushMatrix();
    glTranslated(500, 1000, 0);
    glTranslated(-500, -1000, 0);
    glTranslated(object2_x, 1000, 0);
    glTranslated(0, fall * speed, 0);
    obstacle_design();
    glPopMatrix();

    glPushMatrix();
    glTranslated(500, 1000, 0);
    glTranslated(-500, -1000, 0);
    glTranslated(object3_x, 1000, 0);
    glTranslated(0, fall * speed, 0);
    obstacle_design();
    glPopMatrix();
}
void animation()
{
    rotate += 0.02;
    fall -= 0.1;
    // Go back to top
    if ((fall * speed) < -1050)
    {
        fall = 0;
        object1_x = object1_random;
        object2_x = object2_random;
        object3_x = object3_random;
    }
    glutPostRedisplay();
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

void special_keyboard(int key, int x, int y)
{
    switch (key)
    {
        // Movement
    case GLUT_KEY_UP: y += 30; break;
    case GLUT_KEY_DOWN: y -= 30; break;
    case GLUT_KEY_RIGHT: x += 30; break;
    case GLUT_KEY_LEFT: x -= 30; break;

        // Speed
    case GLUT_KEY_F1: speed += 0.1; break;
    case GLUT_KEY_F2: speed -= 0.1; break;
    }
    glutPostRedisplay();
}

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