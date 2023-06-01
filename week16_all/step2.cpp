#include <GL/glut.h>
float teapotX = 0, teapotY = 0;
void motion(int x, int y) {
    teapotX = (x-150)/150.0;
    teapotY = (150-y)/150.0;
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glTranslatef(teapotX, teapotY, 0);
        glutSolidTeapot( 0.3 );
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);

    glutMainLoop();
}
