#include <iostream>
#include<GL/glut.h>
#include<GL/glu.h>
#include<GL/gl.h>
int iterations=20;
using namespace std;

GLfloat triangle[3][2] = {{-1.0, -1.0}, 
                          { 0.0,  1.0}, 
                          { 1.0, -1.0}};

GLfloat p[2]={0.0, 0.0};
//double colors[1000] = {0};

void myinit()
{

	glClearColor(0,0,0,0);// background color
	glClear(GL_COLOR_BUFFER_BIT);
	//gluOrtho();
	//gluOrtho2D(0,0,50,50);
	}
void drawTriangle(GLfloat *p) {
    //glPolygonMode(GL_FRONT_AND_BACK,GL_FILL);	
	//glShadeModel(shading);
	glBegin(GL_POINTS);
		//en este caso los vértices están dados en el sentido de las manecillas del reloj
		glColor3f(1, 1, 1);
		glVertex2fv(p);
	/*	glColor3f(1, 0, 0);
		glVertex2fv(b);
		glColor3f(1, 0, 0);
		glVertex2fv(c); */
	glEnd();
	glFlush();
}
void divideTriangle(GLfloat *a, GLfloat *b, GLfloat *c, GLfloat *p, int iteraciones) {
     GLfloat v[2];
     int j;
     if (iteraciones > 0) {
        //encontrar los puntos medios de cada arista del triángulo
        for (j = 0; j < 2; j++) 
            v[j] = (a[j] + p[j]) / 2;
		

        //por cada triángulo que entra, se crean 4 triángulos más pequeños y recursivamente estos se dividen a su vez
        divideTriangle( b, c, a, v,iteraciones-1);
		// commenting this will create a Sierpinski Triangle
        //divideTriangle(v[0], v[1], v[2], iteraciones-1);

    }else {
        //dibujar el triángulo de la iteración 0
        drawTriangle(a);
     }
}	

void Dispaly()
{
	//glColor3f(1,1,0);// Color	
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); 
	divideTriangle(triangle[0], triangle[1], triangle[2], p,iterations);
	glFlush();
	}
	
int main(int argc,char **argv)
{
	glutInit(&argc,argv);
	glutInitDisplayMode(GLUT_RGB|GLUT_SINGLE);
	glutInitWindowSize(700,500);
	glutInitWindowPosition(500,200);
	glutCreateWindow("Lines");
	myinit();
	glutDisplayFunc(Dispaly);
	glutMainLoop();
	return 0;
	}
	
