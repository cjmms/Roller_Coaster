#include "tracks.h"


void levelSection(int length) {
    glBegin(GL_LINES);
	glColor3f(1.0, 0.0, 0.0); // Red
	glVertex3f(-2.5, 0, 0);
	glColor3f(0.0, 1.0, 0.0); // Green
	glVertex3f(-2.5, 0, -5);

	glColor3f(1.0, 0.0, 0.0); // Red
	glVertex3f(2.5, 0, 0);
	glColor3f(0.0, 1.0, 0.0); // Green
	glVertex3f(2.5, 0, -5);
	glEnd();

}