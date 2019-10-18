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


void setline(Point p1, Point p2) {
    glBegin(GL_LINES);

    glVertex3f(p1.x, p1.y, p1.z);
    glVertex3f(p2.x, p2.y, p2.z);

    glEnd();
}

Point setBezier(Point p1, Point p2, Point p3, Point p4, double t) {
    Point p;
    double a1 = pow((1 - t), 3);
    double a2 = pow((1 - t), 2) * 3 * t;
    double a3 = 3 * t*t*(1 - t);
    double a4 = t*t*t;
    p.x = a1*p1.x + a2*p2.x + a3*p3.x + a4*p4.x;
    p.y = a1*p1.y + a2*p2.y + a3*p3.y + a4*p4.y;
    p.z = a1*p1.z + a2*p2.z + a3*p3.z + a4*p4.z;
    return p;
}



void drawCruve(Point start, Point end, Point ctl_1, Point ctl_2) {
    glColor3f(1.0, 0.0, 0.0); 

    Point p_current = start; // set as begin
    for (double t = 0.0; t <= 1.0; t += 0.05)
    {
        Point P = setBezier(start, ctl_1, ctl_2, end, t);
        setline(p_current, P);  // draw small cruve segment
        if ((int)(t * 100) % 10 == 0 && t != 1 && t != 0) {
            Point opposite;
            opposite.set(-1 * p_current.x, p_current.y, p_current.z);
            setline(p_current, opposite);
        }
        p_current = P;
    }
}

void upturn(double y, double z, double degree) {
    Point start, ctl1, ctl2, end;
    // ctl1.setxy(2, -2);
	// ctl2.setxy(4, 1);
    drawCruve(start, end, ctl1, ctl2);
}


void downturn(double x, double y, double z, double degree) {
    Point start, ctl1, ctl2, end;
    ctl1.set(x, 0, -1.5);
	ctl2.set(x, -0.5, -3.5);
    start.set(x, y, z);
    end.set(x, -2, -4);
    drawCruve(start, end, ctl1, ctl2);

    ctl1.set(-x, 0, -1.5);
	ctl2.set(-x, -0.5, -3.5);
    start.set(-x, y, z);
    end.set(-x, -2, -4);
    drawCruve(start, end, ctl1, ctl2);
}



void drawTracks() {
    levelSection(100);
    glTranslated(0, 0, segLength * 100);
    downturn(segLength / 2, 0, 0, 30);

}
