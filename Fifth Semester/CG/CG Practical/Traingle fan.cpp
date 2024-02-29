#include <GL/glut.h>
#include <stdio.h>

void display()
{
    glClear(GL_COLOR_BUFFER_BIT);
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(1.0, 0.5, 0.5);
    glVertex3f(-0.5, -0.5, 0.0);
    glVertex3f(0.0, -0.5, 0.0);
    glVertex3f(0.75, 0.75, 0.0);
    glColor3f(0.5, 1.0, 0.5);
    glVertex3f(1.0, 0.5, 0.5);
    glEnd();
    glutSwapBuffers();
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGBA | GLUT_DOUBLE);
    glutInitWindowPosition(600, 100);
    glutInitWindowSize(500, 300);
    glutCreateWindow(" My Glut window");
    glClearColor(0.5, 0.5, 1.0, 1.0);
    glutDisplayFunc(display);
    glutMainLoop();
}
