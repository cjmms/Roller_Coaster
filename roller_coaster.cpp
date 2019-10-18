//#include "GL/freeglut.h"

#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "tracks.h"


// x axis is red, y axis is green, z axis is blue
void drawThreeAxises () {
    double length = 1.5f;
    glBegin(GL_LINES);
    glColor3f(1.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(length, 0.0, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 1.0, 0.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, length, 0.0);
    glEnd();

    glBegin(GL_LINES);
    glColor3f(0.0, 0.0, 1.0);
    glVertex3f(0.0, 0.0, 0.0);
    glVertex3f(0.0, 0.0, length);
    glEnd();
}

void draw() {
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

	glLoadIdentity();
	gluLookAt(	0.0, 1.0, 5.0, 
				0.0, 0.0, 0.0, 
				0.0, 1.0, 0.0);
	

	//levelSection(100);

	drawThreeAxises();

	downturn(segLength / 2, 1, 1, 30);

	glutSwapBuffers();
}


void init_lighting() {
	glEnable(GL_DEPTH_TEST);
	// glEnable(GL_LIGHTING);
	// glEnable(GL_NORMALIZE);
	// glEnable(GL_COLOR_MATERIAL);
	// glEnable(GL_LIGHT0);
}

void changeSize(int w, int h) {
	float ratio = (float)w/ (float)h;

	glMatrixMode(GL_PROJECTION);
	glLoadIdentity();
	glViewport(0, 0, w, h);
	gluPerspective(60.0, ratio, 1.0, 100.0);  // specify a viewing frustum
	glMatrixMode(GL_MODELVIEW);
}

int main(int argc, char *argv[])
{
	glutInit(&argc, argv);  // initialize the library
	glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
	glutInitWindowSize(600, 480);  // define size of the window
	glutInitWindowPosition(100, 100);  // define position of the window
	glutCreateWindow("Hello teapot");

	init_lighting();

	glutReshapeFunc(changeSize);
	glutDisplayFunc(draw);  // display callback
	glutMainLoop();  // enter event processing loop

	return 0;
}
