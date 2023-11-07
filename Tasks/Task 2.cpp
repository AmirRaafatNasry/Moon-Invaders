#include <windows.h>
#include <GL/glut.h>

float rocket_x = 0.0;
void Display()
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();
    glTranslated(300, 300, 0);
    glRotated(rocket_x, 0, 0, 1);
    glTranslated(-300, -300, 0);
    glBegin(GL_POLYGON);
    glColor3f(1.0f, 1.0f, 1.0f);
    glVertex2f(200.0f, 200.0f);
    glVertex2f(200.0f, 400.0f);
    glVertex2f(400.0f, 400.0f);
    glVertex2f(400.0f, 200.0f);
    glEnd();
    glPopMatrix();

    glPushMatrix();
    glTranslated(300, 300, 0);
    glRotated(rocket_x, 0, 0, 1);
    glTranslated(-300, -300, 0);
    glBegin(GL_TRIANGLES);
    glColor3f(0.0f, 0.0f, 0.0f);
    glVertex2f(225.0f, 300.0f);
    glVertex2f(350.0f, 250.0f);
    glVertex2f(350.0f, 350.0f);
    glPopMatrix();

    glEnd();
    glFlush();
}

void animation()
{
    rocket_x += 0.01;
    glutPostRedisplay();
}

int main(int argc, char** argr)
{
    glutInit(&argc, argr);

    glutInitWindowSize(600, 600);
    glutInitWindowPosition(1400, 295);

    glutCreateWindow("OpenGL - 2D Template");
    glutDisplayFunc(Display);
    glutIdleFunc(animation);

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    gluOrtho2D(0, 600, 0, 600);

    glutMainLoop();
}