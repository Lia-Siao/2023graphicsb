#include <GL/glut.h>
void display()
{
    glBegin(GL_POLYGON);
    glColor3f(252/255.0,216/255.0,34/255.0);
        glVertex2f((-100)/100.0,-(-100)/100.0);

    glEnd();

    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week02");
    glutDisplayFunc(display);
    glutMainLoop();
}
