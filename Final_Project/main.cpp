#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"

GLMmodel*head=NULL;
GLMmodel*body=NULL;
GLMmodel*uparmR=NULL;
GLMmodel*lowarmR=NULL;
int show[4]={1,1,1,1};
int ID=2;
float teapotX=0,teapotY=0,angle[20]={};
FILE * fout =NULL;
FILE * fin =NULL;
void  keyboard(unsigned char key,int x,int y)
{
    if(key=='0')ID=0; //show[0]=!show[0];
    if(key=='1')ID=1; //show[1]=!show[1];
    if(key=='2')ID=2; //show[2]=!show[2];
    if(key=='3')ID=3; //show[3]=!show[3];
    glutPostRedisplay();
}
void display()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    if(head==NULL){
        head=glmReadOBJ("model/hand.obj");
        body=glmReadOBJ("model/body.obj");
        uparmR=glmReadOBJ("model/RAU.obj");
        lowarmR=glmReadOBJ("model/RAD.obj");
    }
    glPushMatrix();
        glScalef(0.3,0.3,0.3);
        glPushMatrix();
            //glTranslatef(teapotX,teapotY,0);
            if(ID==0)glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[0])glmDraw(body,GLM_MATERIAL);
        glPopMatrix();

        if(ID==1)glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[1])glmDraw(head,GLM_MATERIAL);

        glPushMatrix();
            glTranslatef(1.340000,0.540000,0);
            glRotatef(angle[2],0,0,1);
            glTranslatef(-1.340000,-0.540000,0);

        if(ID==2)glColor3f(1,0,0);
        else glColor3f(1,1,1);
        if(show[2])glmDraw(uparmR,GLM_MATERIAL);

        glPushMatrix();
            //glTranslatef(teapotX,teapotY,0);
            glTranslatef(1.860000,0.220000,0);
            glRotatef(angle[3],0,0,1);
            glTranslatef(-1.860000,-0.220000,0);

            if(ID==3)glColor3f(1,0,0);
            else glColor3f(1,1,1);
            if(show[3])glmDraw(lowarmR,GLM_MATERIAL);
        glPopMatrix();
    glPopMatrix();

    glPopMatrix();
    glColor3f(0,1,0);
    glutSolidTeapot(0.02);
    glutSwapBuffers();
}
int oldX=0,oldY=0;
void  mouse(int button,int state,int x,int y)
{
    if(state==GLUT_DOWN){
        oldX=x;
        oldY=y;
    }
}
void motion(int x,int y){
    teapotX+=(x-oldX)/150.0*3;
    teapotY-=(y-oldY)/150.0*3;
    printf("glTranslatef(%f,%f,0);\n",teapotX,teapotY);
    angle[ID]+=x-oldX;
    oldX=x;
    oldY=y;
    glutPostRedisplay();
}
int main(int argc,char** argv)
{
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutCreateWindow("week14");

    glutMotionFunc(motion);
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboard);
    glutMouseFunc(mouse);

    glutMainLoop();
}
