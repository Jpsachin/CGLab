#include<GL/freeglut.h>
#include<stdio.h>
#include <stdlib.h>
#include<math.h>
#define RAD (3.142/180.0)
GLsizei ww = 500, wh = 500;
GLfloat th=0,x=0.25,y=0.25;
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

}


void keys(unsigned char k,int x,int y)
{
 switch(k)
{
 case '+':glScaled(2,2,2);
	  glutPostRedisplay(); break;
 case '-':glScaled(0.5,0.5,0.5);
	  glutPostRedisplay(); break;
}

}


void key1(int k,int x,int y)
{
 switch(k)
{
 case GLUT_KEY_UP:glTranslated(0,0.2,0);
	  glutPostRedisplay(); break;
 case GLUT_KEY_DOWN:glTranslated(0,-0.2,0);
	  glutPostRedisplay(); break;
  case GLUT_KEY_LEFT:glTranslated(-0.2,0,0);
	  glutPostRedisplay(); break;

case GLUT_KEY_RIGHT:glTranslated(0.2,0,0);
	  glutPostRedisplay(); break;
}

}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    w1 = glutCreateWindow("Translate square");
 
    glutDisplayFunc(display1);
    glutSpecialFunc(key1);
    glutKeyboardFunc(keys);

    myinit();
    glutMainLoop();
    return 0;
}

