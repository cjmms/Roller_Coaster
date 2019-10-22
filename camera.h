#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "tracks.h"


void cameraAperature();

// this method only work for speed in level section
void cameraSpeed(double speed);

// decreibe how camera moves
// create position of camera at the end
// get called each time buffer swap
void camera();

// accept input (5, 10, 15)
// convert input as ratio (0.5, 1.0, 2.0)
double getSpeed(int speed);

void setSpeed(double input);

// camera move along with a curve
// degree can be negtive or positive
// degree is different and can be modified.
double slopeMove(double t, double degree);

// camera move along with a curve
// degree is required to calculated end point
// turn: UP or DOWN
double curveMove(double degree, int turn, double t);