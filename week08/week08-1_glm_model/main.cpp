#include <GL/glut.h>
#include "glm.h"
GLMmodel *pmodel=NULL;
void display()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if(pmodel==NULL){
        pmodel=glmReadOBJ("f-16.obj");
        glmUnitize(pmodel);
    }
    glmDraw(pmodel,GLM_SMOOTH|GLM_MATERIAL);

    //glutSolidTeapot( 0.3 );
    glutSwapBuffers();
}
int main(int argc, char**argv)
{
    glutInit( &argc, argv );
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
    glutCreateWindow("week08");

    glutDisplayFunc(display);
    glutMainLoop();
}
