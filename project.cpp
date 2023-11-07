#include <iostream>
#include <cmath>
#include <windows.h>
#include <GL/glut.h>

using namespace std;

float hor = 0.0f;
float ver = 0.0f;
float rotates = 0.0f;

float object1_random = 0.0f;
float object1_x = 900.0f;

float object2_random = 0.0f;
float object2_x = 500.0f;

float object3_random = 0.0f;
float object3_x = 500.0f;

// Speed
float fall = 0.0f;
float speed = 1.0f;

void random_number()
{
    object1_random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
    object2_random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
    object3_random = static_cast <float> (rand()) / (static_cast <float> (RAND_MAX / 1000.0));
}

void obstacle()
{
    random_number(); // Random

    glPushMatrix();
    glTranslated(500, 1000, 0);
    glTranslated(-500, -1000, 0);
    glTranslated(object1_x, 1050, 0);
    glTranslated(0, speed * fall, 0);
    glColor3f(255.0f, 255.0f, 255.0f);
    GLUquadric* quadradic = gluNewQuadric();
    gluDisk(quadradic, 0.0, 50, 64, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(500, 1000, 0);
    glTranslated(-500, -1000, 0);
    glTranslated(object2_x, 1000, 0);
    glTranslated(0, speed * fall, 0);
    glColor3f(255.0f, 255.0f, 255.0f);
    gluDisk(quadradic, 0.0, 50, 64, 1);
    glPopMatrix();

    glPushMatrix();
    glTranslated(500, 1000, 0);
    glTranslated(-500, -1000, 0);
    glTranslated(object3_x, 1000, 0);
    glTranslated(0, speed * fall, 0);
    glColor3f(255.0f, 255.0f, 255.0f);
    gluDisk(quadradic, 0.0, 50, 64, 1);
    glPopMatrix();
}

void stars()
{
    glPushMatrix();
    {
        glPointSize(2);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_POINTS);
        for (int i = 1; i < 50; i++)
        {
            int x = rand() % 1000;
            int y = rand() % 1000;
            glVertex3i(x, y, 0);
        }
        glEnd();
    }
    glPopMatrix();
}

void moon()
{
    glPushMatrix(); // Moon Push
    glTranslated(900, 870, 0);
    glRotated(rotates, 0, 0, 1);
    glTranslated(-900, -870, 0);

    glPushMatrix();
    glTranslated(900, 870, 0);
    glColor3f(0.9f, 0.9f, 0.9f);
    GLUquadric* quadradic = gluNewQuadric();
    gluDisk(quadradic, 0.0, 200, 64, 1);
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
    glPopMatrix(); // Moon Pop
}

void rocket()
{
    // Rocket
    glPushMatrix();
    glTranslated(hor, ver, 0);

    //main body rectangle
    glPushMatrix();
    glTranslated(130, 110, 0);
    glTranslated(-130, -110, 0);
    glBegin(GL_POLYGON);

    glColor3f(0.0f, 0.0f, 1.0f);
    glVertex3f(130.0f, 110.0f, 0.0f);
    glVertex3f(170.0f, 110.0f, 0.0f);
    glVertex3f(170.0f, 190.0f, 0.0f);
    glVertex3f(130.0f, 190.0f, 0.0f);

    glEnd();
    glPopMatrix();
    //nose: triangle
    glBegin(GL_TRIANGLES);
    glColor3f(1.0f, 1.0f, 0.0f);
    glVertex3f(130.0f, 190.0f, 0.0f);
    glVertex3f(170.0f, 190.0f, 0.0f);
    glVertex3f(150.0f, 250.0f, 0.0f);
    glEnd();

    //fin: triangles
    glBegin(GL_TRIANGLES);
    glVertex3f(130.0f, 110.0f, 0.0f);
    glVertex3f(130.0f, 130.0f, 0.0f);
    glVertex3f(100.0f, 110.0f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    glVertex3f(170.0f, 110.0f, 0.0f);
    glVertex3f(200.0f, 110.0f, 0.0f);
    glVertex3f(170.0f, 130.0f, 0.0f);
    glEnd();

    //WINDOW: circle
    glTranslated(150, 150, 0);
    glColor3f(1.0f, 1.0f, 1.0f);
    GLUquadric* quadradic = gluNewQuadric();
    gluDisk(quadradic, 0.0, 10, 64, 1);

    glPopMatrix();
}

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    rocket();
    stars();
    moon();
    obstacle();

    glFinish();
}

// TODO: Done
// Keyboard
void special_keyboard(int key, int x, int y)
{
    switch (key)
    {
    // Movement
    case GLUT_KEY_UP: ver += 30; break;
    case GLUT_KEY_DOWN: ver -= 30; break;
    case GLUT_KEY_RIGHT: hor += 30; break;
    case GLUT_KEY_LEFT: hor -= 30; break;

    // Speed
    case GLUT_KEY_F1: speed += 5; break;
    case GLUT_KEY_F2: speed = 1; break; // Sets speed to normal.
    }
        glutPostRedisplay();
}

void anim()
{
    rotates += 0.01;
    fall -= 0.1;
    // Go back to top
    if (fall < -1050)
    {
        fall = 0;
        object1_x = object1_random;
        object2_x = object2_random;
        object3_x = object3_random;
    }
    glutPostRedisplay();
}

// TODO: Done
int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutCreateWindow("Space Invaders Game");
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(GLUT_SCREEN_WIDTH, GLUT_SCREEN_HEIGHT);
    glutInitWindowPosition((GLUT_SCREEN_WIDTH / 2), (GLUT_SCREEN_HEIGHT / 2));

    // Set the callback functions
    glutIdleFunc(anim);
    glutDisplayFunc(display);
    glutSpecialFunc(special_keyboard);

    // Initialize OpenGL
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0.0, 1000, 0.0, 1000);

    // Start the main loop
    glutMainLoop();
}