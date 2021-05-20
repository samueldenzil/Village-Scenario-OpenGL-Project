#include <iostream>
#include <stdlib.h>
#include <GL/gl.h>
#include <GL/glut.h>
#include <math.h>

using namespace std;

// PRESS 'n' FOR NIGHT VIEW AND PRESS 'd' FOR DAY VIEW //

void myInit(){
    glEnable(GL_DEPTH_TEST);
    gluOrtho2D(0,1600,0,800);
    glEnable(GL_LIGHTING); //enable lightining//
    glEnable(GL_LIGHT0); //enable light #0//
    glEnable(GL_COLOR_MATERIAL); //lets us use the glcolor3f//
}
