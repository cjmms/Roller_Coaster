#include "tracks.h"


void levelSection(int length, double degree) {

    glColor3f(1.0, 0.0, 0.0); // Red
    glBegin(GL_LINES);
    // starting horizontal line
    glVertex3f(segLength / 2, 0, 0); 
    glVertex3f(-segLength / 2, 0, 0);

    // ending horizontal line
    glVertex3f(segLength / 2, sin(degree * M_PI / 180.0) * length * segLength, length * -segLength); 
    glVertex3f(-segLength / 2, sin(degree * M_PI / 180.0) * length * segLength, length * -segLength);


    // left track
	glVertex3f(segLength / 2, 0, 0);
	glVertex3f(segLength / 2, sin(degree * M_PI / 180.0) * length * segLength, length * -segLength);

    // right track
	glVertex3f(-segLength / 2, 0, 0);
	glVertex3f(-segLength / 2, sin(degree * M_PI / 180.0) * length * segLength, length * -segLength);

    // draw (length - 1) horizontal lines
    for (int i = 1; i < length; i++) {
        glVertex3f(segLength / 2, sin(degree * M_PI / 180.0) * i * segLength, i * -segLength); 
        glVertex3f(-segLength / 2, sin(degree * M_PI / 180.0) * i * segLength, i * -segLength);
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

bool areSame(double a, double b)
{
    double eps = 0.001;
    return fabs(a - b) < eps;
}

void addLevelLineForCurve(Point p, double t) {
    for (double i = 0.2; i < 1; i += 0.1) {
        if (areSame(i, t)) {
            Point opposite;
            opposite.set(-1 * p.x, p.y, p.z);
            setline(p, opposite);
        }
    }
}



void drawCruve(Point start, Point end, Point ctl_1, Point ctl_2) {
    glColor3f(1.0, 0.0, 0.0); 

    Point p_current = start; // set as begin
    for (double t = 0.0; t <= 1.0; t += 0.05)
    {
        Point P = setBezier(start, ctl_1, ctl_2, end, t);
        setline(p_current, P);  // draw small cruve segment
        addLevelLineForCurve(p_current, t);
        p_current = P;
    }
}


Point findEndPoint(Point start, double degree, double length) {
    Point end;
    end.x = start.x;
    end.y = sin(degree * M_PI / 180.0) * length;
    end.z = cos(degree * M_PI / 180.0) * -length;
    return end;
}


void upturn(double x, double y, double z, double degree) {
    Point start, ctl1, ctl2, end;

    start.set(x, y, z);
    end = findEndPoint(start, degree, 10 * segLength);
    ctl1.set(x, end.y / 4 - 5, end.z / 5 );
    ctl2.set(x, end.y * 0.75 - 2, end.z * 0.75);
    drawCruve(start, end, ctl1, ctl2);

    // draw another curve
    ctl1.x *= -1;
    ctl2.x *= -1;
    start.x *= -1;
    end.x *= -1;
    drawCruve(start, end, ctl1, ctl2);
}

// (
//   (
//     (
//       (
//         (
void downturn(double x, double y, double z, double degree) {
    Point start, ctl1, ctl2, end;

    start.set(x, y, z);
    end = findEndPoint(start, degree, 10 * segLength);
    ctl1.set(x, end.y / 4 + 5, end.z / 5 );
    ctl2.set(x, end.y * 0.75 + 2, end.z * 0.75);
    drawCruve(start, end, ctl1, ctl2);

    // draw another curve
    ctl1.x *= -1;
    ctl2.x *= -1;
    start.x *= -1;
    end.x *= -1;
    drawCruve(start, end, ctl1, ctl2);
}



void drawTracks() {
    // ------------------
    //glTranslated(0, 0, -segLength * 100);
    levelSection(200, 0);

    //  )
    //    )
    //      )
    //        )
    //          )
    glTranslated(0, 0, -segLength * 200);
    downturn(segLength / 2, 0, 0, -30);

    // hardcode as -30 degree
    //  |
    //     |
    //        |
    //           |
    //              |
    glTranslated(0, sin(-30 * M_PI / 180.0) * 10 * segLength + 1.3, cos(-30 * M_PI / 180.0) * 10 * -segLength + 1.8);
    levelSection(50, -30);

    // (
    //   (
    //     (
    //       (
    //         (
    glTranslated(0, sin(-30 * M_PI / 180.0) * 50 * segLength, cos(-30 * M_PI / 180.0) * 60 * -segLength   + 9);
    upturn(segLength / 2, 0, 0, -30);

    //             ）
    //          ）
    //       ）
    //    )
    // )
    glTranslated(0, sin(-30 * M_PI / 180.0) * 10 * segLength + 1.3, cos(-30 * M_PI / 180.0) * 10 * -segLength + 1.8);
    upturn(segLength / 2, 0, 0, 30);

    // hardcode as 30 degree
    //              |
    //            |
    //         |
    //      |
    //   |
    glTranslated(0, sin(30 * M_PI / 180.0) * 10 * segLength - 0.5, cos(30 * M_PI / 180.0) * 10 * -segLength + 1.8);
    levelSection(50, 30);

    //               (
    //            (
    //         (
    //      (     
    //   (         
    glTranslated(0, sin(30 * M_PI / 180.0) * 50 * segLength, cos(30 * M_PI / 180.0) * 60 * -segLength   + 9);
    downturn(segLength / 2, 0, 0, 30);

    // --------
    glTranslated(0, sin(30 * M_PI / 180.0) * 10 * segLength + 1, cos(30 * M_PI / 180.0) * 10 * -segLength );
    levelSection(100, 0);
}
