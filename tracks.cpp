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
    glVertex2f(p1.x,p1.y);
    glVertex2f(p2.x, p2.y);
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
    return p;
}



void drawCruve(Point begin, Point end, Point ctl_1, Point ctl_2) {
    glColor3f(0.0, 0.0, 1.0); // 设定贝塞尔曲线的颜色

    Point p_current = begin; //设为起点
    for (double t = 0.0; t <= 1.0; t += 0.05)
    {
        Point P = setBezier(begin, ctl_1, ctl_2, end, t);
        setline(p_current, P);
        p_current = P;
    }
}
