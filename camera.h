#ifdef __APPLE__
#include <OpenGL/Opengl.h>
#include <GLUT/glut.h>
#else
#include <GL/glew.h>
#include <GL/glut.h>
#endif

#include "tracks.h"

//#include "tools.h"


void cameraAperature();
void cameraSpeed(double speed);
void camera();