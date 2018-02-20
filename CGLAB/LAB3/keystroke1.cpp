#include <stdio.h>
#include <GL/glut.h>
#include <GL/glu.h>
#include <GL/gl.h>
#include<string.h>
#include<stdlib.h>
#define size 20
GLfloat vq[4][2]={{100.0,100.0},{150.0,100.0},{150.0,150.0},{100.0,150.0}};
GLsizei ww=500, wh=500;
void disp(int w,int y)
{
y=wh-y;
glClearColor(1,1,1,1);
glLineWidth(2.0);
	glBegin(GL_POLYGON);
		glVertex2f(w+size,y+size);
		glVertex2f(w-size,y+size);
		glVertex2f(w-size,y-size);
		glVertex2f(w+size,y-size);
	glEnd();
	glFlush();
}
void key(unsigned char k,int x,int y)
{
	switch(k)
	{
		case 'r':glColor3f(1,0,0);
		break;
		case 'g':glColor3f(0,1,0);
		break;
		case 'b':glColor3f(0,0,1);
		break;
		case 'q':exit(0);
	}
}

void mouse(int btn,int state,int x,int y)
{
	if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
		disp(x,y);
}
void myinit()
{
 glMatrixMode(GL_PROJECTION);
 glLoadIdentity();
 gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
 glMatrixMode(GL_MODELVIEW);
 glClearColor(1,1,1,1);
 glColor3f(1,0,0);
 }
 
 void display(void)
 {
 
  glClear(GL_COLOR_BUFFER_BIT);
   glClearColor(1,1,1,1);
   glColor3f(0,0,0);
   glBegin(GL_POLYGON);
    glVertex2fv(vq[0]);
    glVertex2fv(vq[1]);
    glVertex2fv(vq[2]);
    glVertex2fv(vq[3]);
   glEnd();
   glFlush();
   }
   
   int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(500,500);
	glutInitWindowPosition(100,100);
	glutCreateWindow("Key and Mouse");
	myinit();
	glutDisplayFunc(display);
	glutMouseFunc(mouse);
	glutKeyboardFunc(key);
	glutMainLoop();
	return 0;
	}

		
