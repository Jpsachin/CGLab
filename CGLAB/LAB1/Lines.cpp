#include <iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>

using namespace std;

void myinit()
{

	glClearColor(0,1,0,0);// background color
	glClear(GL_COLOR_BUFFER_BIT);
	//gluOrtho();
	//gluOrtho2D(0,0,50,50);
	}
	
void Dispaly()
{
	glColor3f(1,1,0);// Color
	glBegin(GL_LINES);
	glVertex2f(0.0,0.0);
	glVertex3f(0.5,0.5,0.0);
	glEnd();
	glFlush();
	}
	
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(300,300);
	glutInitWindowPosition(500,200);
	glutCreateWindow("Lines");
	myinit();
	glutDisplayFunc(Dispaly);
	glutMainLoop();
	return 0;
	}
	
