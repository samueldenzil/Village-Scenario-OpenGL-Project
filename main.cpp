#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

// PRESS 'n' FOR NIGHT VIEW AND PRESS 'd' FOR DAY VIEW //

void myInit()
{
	glEnable(GL_DEPTH_TEST);
	gluOrtho2D(0,1600,0,800);
	glEnable(GL_LIGHTING); //enable lightining//
	glEnable(GL_LIGHT0); //enable light #0//
	glEnable(GL_COLOR_MATERIAL); //lets us use the glcolor3f//
}

void Sun()
{
	glColor3f(1.000, 0.843, 0.000);
	circle(-0.25, 0.75, 0.18);
}

void Moon()
{
	glPushMatrix();
	glColor3f(1.0, 1.0, 1.0);
	circle(0.75, 0.75, 0.10);
	glPopMatrix();
}

void Cloud1()
{
	glColor3f(0.80, 0.80, 0.80);
	circle(-0.85, 0.77, 0.15);
	circle(-0.79, 0.70, 0.15);
	circle(-0.70, 0.70, 0.15);
	circle(-0.75, 0.77, 0.15);
}

void Cloud2()
{
	glColor3f(0.80, 0.80, 0.80);
	drawcircle(0.35, 0.77, 0.15);
	circle(-0.79, 0.70, 0.15);
	drawcircle(0.55, 0.75, 0.15);
	circle(-0.75, 0.77, 0.15);
}

void Cloud3()
{
	glColor3f(0.80, 0.80, 0.80);
	circle(-0.07, 0.85, 0.15);
	circle(-0.01, 0.80, 0.15);
	circle(0.08, 0.83, 0.15);
	circle(0.02, 0.85, 0.15);
}

void Tree1()
{
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.25, -0.30);
	glVertex2f(-0.25, -0.12);
	glVertex2f(-0.27, -0.12);
	glVertex2f(-0.27, -0.30);
	glEnd();

	glColor3f(0.0f, 0.43f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.36, -0.12);
	glVertex2f(-0.26, 0.12);
	glVertex2f(-0.16, -0.12);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.36, -0.04);
	glVertex2f(-0.26, 0.20);
	glVertex2f(-0.16, -0.04);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.36, -0.04);
	glVertex2f(-0.26, 0.28);
	glVertex2f(-0.16, -0.04);
	glEnd();
}

void Tree2()
{
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.05, -0.20);
	glVertex2f(-0.05, -0.00);
	glVertex2f(-0.07, -0.00);
	glVertex2f(-0.07, -0.20);
	glEnd();

	glColor3f(0.0f, 0.43f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.18, 0.00);
	glVertex2f(-0.06, 0.24);
	glVertex2f(-0.06, 0.00);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.18, 0.08);
	glVertex2f(-0.06, 0.32);
	glVertex2f(0.06, 0.08);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.18, 0.16);
	glVertex2f(-0.06, 0.40);
	glVertex2f(0.06, 0.16);
	glEnd();
}

void Tree3()
{
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(0.92, 0.0);
	glVertex2f(0.92, 0.11);
	glEnd();

	glColor3f(0.0f, 0.43f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.98, 0.10);
	glVertex2f(0.92, 0.50);
	glVertex2f(0.86, 0.10);
	glEnd();
}

void Tree4()
{
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(0.74, 0.0);
	glVertex2f(0.74, 0.11);
	glEnd();

	glColor3f(0.0f, 0.43f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.80, 0.10);
	glVertex2f(0.74, 0.50);
	glVertex2f(0.68, 0.10);
	glEnd();
}

void Tree5()
{
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(0.56, 0.0);
	glVertex2f(0.56, 0.11);
	glEnd();

	glColor3f(0.0f, 0.43f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.61, 0.10);
	glVertex2f(0.56, 0.50);
	glVertex2f(0.50, 0.10);
	glEnd();
}

void Tree6()
{
	glColor3f(0.38f, 0.19f, 0.0f);
	glLineWidth(7);
	glBegin(GL_LINES);
	glVertex2f(-0.46, -0.30);
	glVertex2f(-0.46, -0.20);
	glEnd();

	glColor3f(0.0f, 0.43f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.52, -0.22);
	glVertex2f(-0.46, 0.00);
	glVertex2f(-0.40, -0.22);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.52, -0.17);
	glVertex2f(-0.6, 0.00);
	glVertex2f(-0.40, -0.17);
	glEnd();

	glBegin(GL_POLYGON);
	glVertex2f(-0.52, -0.12);
	glVertex2f(-0.46, 0.40);
	glVertex2f(-0.40, -0.12);
	glEnd();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
	glutInitWindowSize(1200, 700);
	
	glutCreateWindow("Group 7: Village Scenario");
	myInit();
	
	glutDisplayFunc(Display);
	glutReshapeFunc(handleResize);

	glutKeyboardFunc(keyboard);

	glutTimerFunc(25, update, 0);	// Add a timer
	glutMainLoop();
	return 0;
}
