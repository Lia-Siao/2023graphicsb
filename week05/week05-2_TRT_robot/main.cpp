#include <GL/glut.h>
float angle = 0;
void myCube()
{
    glPushMatrix();
        glScalef(0.5,0.2,0.2);
        glutSolidCube(1);
    glPopMatrix();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glColor3f(1,1,1);
    glutSolidCube(1);

    glPushMatrix();
        glTranslatef(0.5,0.5,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.25,0,0);
        glColor3f(0,1,0);
       myCube();
    glPopMatrix();

    glPushMatrix();
        glTranslatef(-0.5,0.5,0);
        glRotatef(angle,0,0,1);
        glTranslatef(0.25,0,0);
        glColor3f(0,1,0);
       myCube();
    glPopMatrix();

    glutSwapBuffers();
    angle++;
}
int main(int argc,char *argv[])
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week05");
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutMainLoop();
}
