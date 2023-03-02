#include <GL/glut.h>
#include <stdio.h>
float X=0,Y=0,Z=0;
void display()
{
    glClear( GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    glBegin(GL_POLYGON);
     glVertex2f(-0.24,0.19);
     glVertex2f(-0.37,0.11);
     glVertex2f(-0.39,-0.05);
     glVertex2f(-0.33,-0.19);
     glVertex2f(-0.19,-0.27);
     glVertex2f(0.07,-0.31);
     glVertex2f(0.29,-0.31);
     glVertex2f(0.41,-0.23);
     glVertex2f(0.46,-0.07);
     glVertex2f(0.48,0.08);
     glVertex2f(0.43,0.16);
     glVertex2f(0.35,0.24);
     glVertex2f(0.07,0.34);
     glVertex2f(-0.14,0.34);
     glVertex2f(-0.25,0.27);
     glVertex2f(-0.27,0.18);
    glEnd();

    glutSwapBuffers();
}
void mouse(int button,int state,int x, int y)
{

     X=(x-150)/150.0;
     Y=-(y-150)/150.0;
if(state==GLUT_DOWN)printf(" glVertex2f(%.2f,%.2f);\n",X,Y);
}
int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("Week03");
    glutMouseFunc(mouse);
    glutDisplayFunc(display);
    glutMainLoop();
}
