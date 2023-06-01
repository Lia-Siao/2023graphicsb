#include <GL/glut.h>
float teapotX = 0, teapotY = 0, angle = 0, oldX = 0, oldY = 0;
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
void motion(int x, int y) {
    //teapotX = (x-150)/150.0;
    angle += x - oldX;//teapotY = (150-y)/150.0;
    oldX = x;
    glutPostRedisplay();
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glRotatef(angle, 0, 0, 1); //glTranslatef(teapotX, teapotY, 0);
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
    glutMouseFunc(mouse);

    glutMainLoop();
}
