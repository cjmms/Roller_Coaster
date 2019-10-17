#include "tracks.h"


void levelSection(int length) {
    glColor3f(1.0, 0.0, 0.0); // Red

    glBegin(GL_LINES);
    // starting horizontal line
    glVertex3f(segLength / 2, 0, 0); 
    glVertex3f(segLength / 2 * -1, 0, 0);

    // ending horizontal line
    glVertex3f(segLength / 2, 0, length * segLength); 
    glVertex3f(segLength / 2 * -1, 0, length * segLength);

    // left track
	glVertex3f(segLength / 2, 0, 0);
	glVertex3f(segLength / 2, 0, length * segLength);

    // right track
	glVertex3f(segLength / 2 * -1, 0, 0);
	glVertex3f(segLength / 2 * -1, 0, length * segLength);

    // draw (length - 1) horizontal lines
    for (int i = 1; i < length; i++) {
        glVertex3f(segLength / 2, 0, i * segLength); 
        glVertex3f(segLength / 2 * -1, 0, i * segLength);
    }

	glEnd();
}