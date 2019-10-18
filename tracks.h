//#include "GL/freeglut.h"

#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include <math.h>
#include <stdio.h>


#define segLength -5


class Point{
public:
    double x, y, z;
    void setxy(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }
};

// draw a level line segment
void levelSection(int length);

// draw a segment between p1 and p2
void setline(Point p1, Point p2);

// return a point on the Bezier curve base on variable t
Point setBezier(Point p1, Point p2, Point p3, Point p4, double t);

// draw Bezier curve based on two ending points, two control points
void drawCruve(Point begin, Point end, Point ctl_1, Point ctl_2);

// x value is fixed, width is fixed, end points can be calculated 
void downturn(double x, double y, double z, double degree);


void upturn(double y, double z, double degree);
