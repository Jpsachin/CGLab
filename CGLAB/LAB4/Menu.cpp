#include<GL/freeglut.h>
#include<stdio.h>
#include <stdlib.h>
#define size 20
GLfloat vq[4][2] = {{100.0,100.0},{150.0,100.0},{150.0,150.0},{100.0,150.0}};
GLfloat v[4][2] = {{100.0,100.0},{350.0,100.0},{350.0,350.0},{100.0,350.0}};
GLfloat colors[ ][3] = {{0.0,0.5,0.2},{0.0,0.0,1.0},{0.9,0.4,0.6},{1.0,0.0,0.0},{0.2,0.5,0.7},{0.0,0.5,1.0},{0.0,0.7,0.1},{1.0,1.0,1.0}};
GLsizei ww = 500, wh = 500;

void drawsquare()
{
      glBegin(GL_POLYGON);
     glVertex2fv(v[0]);
     glVertex2fv(v[1]);
     glVertex2fv(v[2]);
     glVertex2fv(v[3]);
    glEnd();
    glFlush();
}

void drawtriangle()
{
      glBegin(GL_POLYGON);
     glVertex2fv(v[0]);
     glVertex2fv(v[1]);
     glVertex2f(225.0,300);
    glEnd();
    glFlush();
}

void topmenu(int id)
{
    switch(id)
    {
        case 3: exit(0);

    }
}

void tri_menu(int id)
{
    if(id==1)
        glColor3f(1,0,0);
    else if(id==2)
        glColor3f(0,1,0);
    else if (id==3)
        glColor3f(0,0,1);
    drawtriangle();
    //glutPostRedisplay();
}

void sqr_menu(int id)
{
    if(id==1)
        glColor3f(1,0,0);
    else if(id==2)
        glColor3f(0,1,0);
    else if (id==3)
        glColor3f(0,0,1);
    drawsquare();
}


void myinit()
{
    glViewport(0,0,ww,wh);
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
      glColor3fv(colors[3]);
      glBegin(GL_POLYGON);
     glVertex2fv(vq[0]);
     glVertex2fv(vq[1]);
     glVertex2fv(vq[2]);
     glVertex2fv(vq[3]);
    glEnd();
    glFlush();

}


int main(int argc, char *argv[])
{
    int sub_menu1, sub_menu2;
    glutInit(&argc, argv);
    glutInitWindowSize(500,500);
    glutInitWindowPosition(300,100);
    glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE);
    glutCreateWindow("Menu function");
    myinit();
    sub_menu1 = glutCreateMenu(sqr_menu);
    glutAddMenuEntry("red",1);
    glutAddMenuEntry("green",2);
    glutAddMenuEntry("blue",3);
    sub_menu2 = glutCreateMenu(tri_menu);
    glutAddMenuEntry("red",1);
    glutAddMenuEntry("green",2);
    glutAddMenuEntry("blue",3);
    glutCreateMenu(topmenu);
    glutAddSubMenu("drawsquare",sub_menu1);
    glutAddSubMenu("drawtriangle",sub_menu2);
    glutAddMenuEntry("quit",3);
    glutAttachMenu(GLUT_RIGHT_BUTTON);
    glutAttachMenu(GLUT_LEFT_BUTTON);
    glutDisplayFunc(display);
    glutMainLoop();
    return 0;
}



