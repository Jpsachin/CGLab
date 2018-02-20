#include<GL/freeglut.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
GLsizei ww=500,wh=500;

void disptext(char *name,float x,float y)
{
int n,i;
n=strlen(name);
glRasterPos2f(x,y);

for(i=0;i<n;i++)
{
glutBitmapCharacter(GLUT_BITMAP_HELVETICA_18,name[i]);
//glutBitmapCharacter(GLUT_BITMAP_HELVETICA_12,name[i]);
}
glFlush();
}

void display(void)
{
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0.1,0);
disptext("Computer",100,200);
glColor3f(0.1,1,0);
disptext("Graphics",100,100);
}
void setcolor()
{
glColor3f((float)(rand()%100)/150,(float)(rand()%100)/150,(float)(rand()%100)/150);
}
void mouse(int btn,int state,int x,int y)
{
 setcolor();
 if(btn==GLUT_LEFT_BUTTON&&state==GLUT_DOWN)
   disptext("Hellow",x,500-y);
   if(btn==GLUT_RIGHT_BUTTON&&state==GLUT_DOWN)
   disptext("WORLD",x,500-y);
}
void myinit()
{
glViewport(0,0,ww,wh);
glMatrixMode(GL_PROJECTION);
glLoadIdentity();
gluOrtho2D(0.0,(GLdouble)ww,0.0,(GLdouble)wh);
glMatrixMode(GL_MODELVIEW);
glClearColor(1,1,1,1);
glClear(GL_COLOR_BUFFER_BIT);
glColor3f(1,0,0);
}

int main(int argc,char **argv)
{
glutInit(&argc,argv);
glutInitDisplayMode(GLUT_SINGLE|GLUT_RGB);
glutInitWindowPosition(100,100);
glutInitWindowSize(500,500);
glutCreateWindow("TEXT");
myinit();
glutDisplayFunc(display);
glutMouseFunc(mouse);
glutMainLoop();
return 0;
}

