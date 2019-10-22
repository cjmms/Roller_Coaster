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
// #include "tools.h"


#define segLength 5


class Point{
public:
    double x, y, z;
    void set(double _x, double _y, double _z) {
        x = _x;
        y = _y;
        z = _z;
    }
};


// draw a level line segment
void levelSection(int length, double degree);

// draw a segment between p1 and p2
void setline(Point p1, Point p2);

// return a point on the Bezier curve base on variable t
Point setBezier(Point p1, Point p2, Point p3, Point p4, double t);

// draw Bezier curve based on two ending points, two control points
void drawCruve(Point begin, Point end, Point ctl_1, Point ctl_2);

// x value is fixed, width is fixed, end points can be calculated 
void downturn(double x, double y, double z, double degree);

void upturn(double y, double z, double degree);

// calculate the ending point of a curve base on the degree of the slope and starting point
Point findEndPoint(Point start, double degree, double length);

// draw the Roller Coaster tracks
void drawTracks();

// point p is one end of the level line, t is linear interpolation of the curve
void addLevelLineForCurve(Point p, double t);


// compare two double values
bool areSame(double a, double b);

void drawCylinder(Point p1, Point p2);
