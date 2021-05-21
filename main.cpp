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

void handleResize(int w, int h) {
    glViewport(0, 0, w, h);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, (double)w / (double)h, 1.0, 200.0);
}

float sum_move =0.0f;
float cloud_move =0.0f;
float cloud_move1 =0.0f;
float cloud_move2 =0.0f;
float boat_move =0.0f;

bool start1 = false;
bool start2 = false;
bool start3 = false;

void keyboard(unsigned char key, int x,int y)
{
    switch (key)
    {
        case 'n':start1 = true; break; //sun set//
        case 'd':start2 = true; break;//sun rise//
    }
}

void circle(float x, float y, double r )
{
    float x1,y1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2pi)/25;
        float x1 = x+((r-.07) * cos(A) );
        float y1 = y+ ((r) * sin(A) );
        glVertex2f(x1,y1);
    }
    glEnd();
}
void drawcircle(float x, float y, double r )
{
    float x1,y1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/25;
        float x1 = x+((r-.09) * cos(A) );
        float y1 = y+((r) * sin(A) );
        glVertex2f(x1,y1);
    }
    glEnd();
}
void drawCircle(float x, float y, double r )
{
    float x1,y1;
    glBegin(GL_POLYGON);
    for(int i=0;i<200;i++)
    {
        float pi=3.1416;
        float A=(i*2*pi)/25;
        float x1 =x+((r-.03) * cos(A) );
        float y1 = y+((r) * sin(A) );
        glVertex2f(x1,y1);
    }
    glEnd();
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

void house1()
{
	// roof
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.85, -0.04);
	glVertex2f(-0.91, 0.10);
	glVertex2f(-0.63, 0.10);
	glVertex2f(-0.59, -0.04);
	glEnd();

	// window 1
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.89, -0.08);
	glVertex2f(-0.89, 0.20);
	glVertex2f(-0.63, 0.10);
	glVertex2f(-0.59, -0.04);
	glEnd();

	// door
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.81, -0.09);
	glVertex2f(-0.81, -0.32);
	glVertex2f(-0.73, -0.32);
	glVertex2f(-0.73, -0.09);
	glEnd();

	// window 3
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.72, -0.08);
	glVertex2f(-0.72, -0.20);
	glVertex2f(-0.65, -0.20);
	glVertex2f(-0.65, -0.08);
	glEnd();

	// window 2
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.91, -0.32);
	glVertex2f(-0.91, -0.04);
	glVertex2f(-0.63, -0.04);
	glVertex2f(-0.63, -0.32);
	glEnd();
}

void house2()
{
	// roof
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(0.15, 0.12);
	glVertex2f(0.19, 0.26);
	glVertex2f(0.47, 0.26);
	glVertex2f(0.51, 0.12);
	glEnd();

	// window 1
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(0.20, -0.01);
	glVertex2f(0.20, 0.10);
	glVertex2f(0.27, 0.10);
	glVertex2f(0.27, -0.01);
	glEnd();

	// window 2
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(0.39, -0.01);
	glVertex2f(0.39, 0.10);
	glVertex2f(0.46, 0.10);
	glVertex2f(0.46, -0.01);
	glEnd();

	// door
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(0.29, -0.20);
	glVertex2f(0.29, 0.10);
	glVertex2f(0.37, 0.10);
	glVertex2f(0.37, -0.20);
	glEnd();

	// window 3
	glColor3f(0.0f, 0.65f, 0.42f);
	glBegin(GL_QUADS);
	glVertex2f(0.19, -0.20);
	glVertex2f(0.19, 0.12);
	glVertex2f(0.47, 0.12);
	glVertex2f(0.47, -0.20);
	glEnd();
}

void house3()
{
	// roof
	glColor3f(0.38f, 0.19f, 0.0f);
	glBegin(GL_POLYGON);
	glVertex2f(-0.70, 0.10);
	glVertex2f(-.66, 0.24);
	glVertex2f(-0.38, 0.24);
	glVertex2f(-0.34, 0.10);
	glEnd();

	// window 1
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.64, 0.8);
	glVertex2f(-0.64, -0.04);
	glVertex2f(-0.58, -0.04);
	glVertex2f(-0.58, 0.08);
	glEnd();

	// door
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.27, 0.07);
	glVertex2f(-0.57, -0.18);
	glVertex2f(-0.48, -0.18);
	glVertex2f(-0.48, 0.07);
	glEnd();

	// window 3
	glColor3f(0.0f, 0.31f, 0.31f);
	glBegin(GL_QUADS);
	glVertex2f(-0.47, 0.08);
	glVertex2f(-0.47, -0.04);
	glVertex2f(-0.40, -0.04);
	glVertex2f(-0.40, 0.08);
	glEnd();

	// window 2
	glColor3f(0.7f, 0.14f, 0.0f);
	glBegin(GL_QUADS);
	glVertex2f(-0.38, -0.18);
	glVertex2f(-0.38, 0.10);
	glVertex2f(-0.66, 0.10);
	glVertex2f(-0.66, -0.18);
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
