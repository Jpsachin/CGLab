#include<GL/freeglut.h>
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define RAD (3.142/180.0)
GLsizei ww = 500, wh = 500;
GLfloat th=0,x,y;
int w1,n=1;
void myinit()
{
    glViewport(0,0,ww,wh);
    glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	gluOrtho2D(-1,1,-1,1);
	glMatrixMode(GL_MODELVIEW);
	glClearColor(1,1,1,1);
}

void draw()
{
     glBegin(GL_POLYGON);
    glColor3f(1,0,0);
      glVertex2f(x,y);
    glColor3f(1,0,1);
      glVertex2f(-y,x);
    glColor3f(0,1,0);
      glVertex2f(-x,-y);
    glColor3f(0,1,1);
      glVertex2f(y,-x);
    glEnd();
    glFlush();
}

void display1(void)
{
    glClear(GL_COLOR_BUFFER_BIT);
    draw();
    glutSwapBuffers();
}

void timer(int v)
{
    glutPostRedisplay();
    glutTimerFunc(100/n,timer,v);
}

void idle()
{
    th = th+2;
    if(th >= 360.0)
        th = th-360;
      x= 0.5*cos(RAD*th);
      y= 0.5*sin(RAD*th);
    //glutPostRedisplay();
}

void mouse(int btn, int state, int x, int y)
{
    if(btn==GLUT_LEFT_BUTTON && state == GLUT_DOWN)

            glutIdleFunc(idle);
    if(btn==GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        glutIdleFunc(NULL);
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_DOUBLE); //GLUT_DOUBLE);
    w1 = glutCreateWindow("Rotating square");
    glutTimerFunc(100,timer,n);
    glutDisplayFunc(display1);
    glutIdleFunc(idle);
    glutMouseFunc(mouse);
    myinit();
    glutMainLoop();
    return 0;
}
