#include <opencv/highgui.h> ///使用 OpenCV 2.1 比較簡單, 只要用 High GUI 即可
#include <opencv/cv.h>
#include <stdio.h>
#include <GL/glut.h>
#include "glm.h"
GLMmodel * head = NULL;
GLMmodel * body = NULL; ///GLMmodel * gundam = NULL;
GLMmodel * arm1 = NULL, * arm2 = NULL;
GLMmodel * hand1 = NULL, * hand2 = NULL;
GLMmodel * bot = NULL;
GLMmodel * leg1 = NULL, * leg2 = NULL;
GLMmodel * knee1 = NULL, * knee2 = NULL;
GLMmodel * foot1 = NULL, * foot2 = NULL;

float teapotX = 0, teapotY = 0, oldX = 0, oldY = 0;
float angle[20] = {}, angle2[20] = {};///float angle = 0, angle2 = 0;
int ID = 0;
void keyboard(unsigned char key, int x, int y) {
    if(key=='0') ID = 0;
    if(key=='1') ID = 1;
    if(key=='2') ID = 2;
    if(key=='3') ID = 3;
    if(key=='4') ID = 4;
    if(key=='5') ID = 5;
    if(key=='6') ID = 6;
    if(key=='7') ID = 7;
    if(key=='8') ID = 8;
    if(key=='9') ID = 9;
}

int myTexture(char * filename)
{
    IplImage * img = cvLoadImage(filename); ///OpenCV讀圖
    cvCvtColor(img,img, CV_BGR2RGB); ///OpenCV轉色彩 (需要cv.h)
    glEnable(GL_TEXTURE_2D); ///1. 開啟貼圖功能
    GLuint id; ///準備一個 unsigned int 整數, 叫 貼圖ID
    glGenTextures(1, &id); /// 產生Generate 貼圖ID
    glBindTexture(GL_TEXTURE_2D, id); ///綁定bind 貼圖ID
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖T, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT); /// 貼圖參數, 超過包裝的範圖S, 就重覆貼圖
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); /// 貼圖參數, 放大時的內插, 用最近點
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST); /// 貼圖參數, 縮小時的內插, 用最近點
    glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, img->width, img->height, 0, GL_RGB, GL_UNSIGNED_BYTE, img->imageData);
    return id;
}
void mouse(int button, int state, int x, int y) {
    oldX = x;
    oldY = y;
}
void motion(int x, int y) {
    teapotX += (x - oldX) / 150.0 * 10; ///teapotX = (x-150)/150.0;
    teapotY += (oldY - y) / 150.0 * 10; ///teapotY = (150-y)/150.0;
    angle[ID] += x - oldX;
    angle2[ID] += oldY - y;
    oldX = x;
    oldY = y;
    glutPostRedisplay();
    printf("  glTranslatef( %.2f, %.2f, 0 ); \n", teapotX, teapotY );
}
void display() {
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glPushMatrix();
        glScalef(1.6, 1.6, 1.6);
        glTranslatef(0, -0.5, 0);///往下一半
        glPushMatrix();
            glColor3f(1,1,1);
            glScalef(0.04, 0.04, 0.04);
            glRotatef(angle[0], 0, 1, 0); ///身體的轉動
            glmDraw(body, GLM_MATERIAL|GLM_TEXTURE);///glmDraw(gundam, GLM_MATERIAL|GLM_TEXTURE);

            glPushMatrix();///左手
                glTranslatef(-4.07, +21.33, 0 );
                glRotatef(angle[1], 0, 1, 0);
                glRotatef(angle2[1], 1, 0, 0);
                glTranslatef( 4.07, -21.33, 0 );///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm1, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-4.40, +18.53, 0 );
                    glRotatef(angle[2], 0, 1, 0);
                    glRotatef(angle2[2], 1, 0, 0);
                    glTranslatef( 4.40, -18.53, 0 );///glTranslatef(teapotX, teapotY, 0);
                    glmDraw(hand1, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();


            glPushMatrix();///右手
                glTranslatef(+4.07, +21.33, 0 );
                glRotatef(angle[3], 0, 1, 0);
                glRotatef(angle2[3], 1, 0, 0);
                glTranslatef(-4.07, -21.33, 0 );///glTranslatef(teapotX, teapotY, 0);
                glmDraw(arm2, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(+4.40, +18.53, 0 );
                    glRotatef(angle[5], 0, 1, 0);
                    glRotatef(angle2[4], 1, 0, 0);
                    glTranslatef(-4.40, -18.53, 0 );///glTranslatef(teapotX, teapotY, 0);
                    glmDraw(hand2, GLM_MATERIAL|GLM_TEXTURE);
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();
                glTranslatef(-0.00, +22.53, 0 );
                glRotatef(angle[5], 0, 1, 0);
                glRotatef(angle2[5], 1, 0, 0);
                glTranslatef( 0.00, -22.53, 0 );///glTranslatef(teapotX, teapotY, 0);
                glmDraw(head, GLM_MATERIAL|GLM_TEXTURE);
            glPopMatrix();


            glPushMatrix();///左腳
                glmDraw(bot, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(-2.00, +14.27, 0 );
                    glRotatef(angle[6], 0, 1, 0);
                    glRotatef(angle2[6], 1, 0, 0);
                    glTranslatef( 2.00, -14.27, 0 );///glTranslatef(teapotX, teapotY, 0);
                    glmDraw(leg1, GLM_MATERIAL|GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(-2.00, +9.87, 0 );
                        glRotatef(angle[7], 0, 1, 0);
                        glRotatef(angle2[7], 1, 0, 0);
                        glTranslatef( 2.00, -9.87, 0 );///glTranslatef(teapotX, teapotY, 0);
                        glmDraw(knee1, GLM_MATERIAL|GLM_TEXTURE);

                        glPushMatrix();
                            glTranslatef(-2.13, +2.40, 0 );
                            glRotatef(angle[8], 0, 1, 0);
                            glRotatef(angle2[8], 1, 0, 0);
                            glTranslatef( 2.13, -2.40, 0 );///glTranslatef(teapotX, teapotY, 0);
                            glmDraw(foot1, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

            glPushMatrix();///右腳
                glmDraw(bot, GLM_MATERIAL|GLM_TEXTURE);

                glPushMatrix();
                    glTranslatef(+2.00, +14.27, 0 );
                    glRotatef(angle[9], 0, 1, 0);
                    glRotatef(angle2[9], 1, 0, 0);
                    glTranslatef(-2.00, -14.27, 0 );///glTranslatef(teapotX, teapotY, 0);
                    glmDraw(leg2, GLM_MATERIAL|GLM_TEXTURE);

                    glPushMatrix();
                        glTranslatef(+2.00, +9.87, 0 );
                        glRotatef(angle[10], 0, 1, 0);
                        glRotatef(angle2[10], 1, 0, 0);
                        glTranslatef(-2.00, -9.87, 0 );///glTranslatef(teapotX, teapotY, 0);
                        glmDraw(knee2, GLM_MATERIAL|GLM_TEXTURE);

                        glPushMatrix();
                            glTranslatef(+2.13, +2.40, 0 );
                            glRotatef(angle[11], 0, 1, 0);
                            glRotatef(angle2[11], 1, 0, 0);
                            glTranslatef(-2.13, -2.40, 0 );///glTranslatef(teapotX, teapotY, 0);
                            glmDraw(foot2, GLM_MATERIAL|GLM_TEXTURE);
                        glPopMatrix();
                    glPopMatrix();
                glPopMatrix();
            glPopMatrix();

        glPopMatrix();




        glColor3f(0,1,0);
        glutSolidTeapot( 0.02 );

    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE|GLUT_DEPTH);
    glutInitWindowSize(500,500);
    glutCreateWindow("week16");

    glutDisplayFunc(display);
    glutMotionFunc(motion);
    glutMouseFunc(mouse);
    glutKeyboardFunc(keyboard);

    head = glmReadOBJ("model/head.obj");
    body = glmReadOBJ("model/body.obj"); ///gundam = glmReadOBJ("model/Gundam.obj");
    arm1 = glmReadOBJ("model/arm1.obj");
    arm2 = glmReadOBJ("model/arm2.obj");
    hand1 = glmReadOBJ("model/hand1.obj");
    hand2 = glmReadOBJ("model/hand2.obj");
    bot = glmReadOBJ("model/bot.obj");
    leg1 = glmReadOBJ("model/leg1.obj");
    leg2 = glmReadOBJ("model/leg2.obj");
    knee1 = glmReadOBJ("model/knee1.obj");
    knee2 = glmReadOBJ("model/knee2.obj");
    foot1 = glmReadOBJ("model/foot1.obj");
    foot2 = glmReadOBJ("model/foot2.obj");

    myTexture("model/Diffuse.jpg");
    glEnable(GL_DEPTH_TEST);

    glutMainLoop();
}
