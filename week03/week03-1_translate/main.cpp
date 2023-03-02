#include <GL/glut.h>
void display()
{
    glPushMatrix();
        glTranslated(0.5,0.5,0);
        glutSolidTeapot(0.3);
    glPopMatrix();

    glutSwapBuffers();
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week03");
    glutDisplayFunc(display);
    glutMainLoop();
}
