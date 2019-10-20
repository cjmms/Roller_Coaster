#include "camera.h"

double z_dis = 0.0;

void cameraAperture() {


}

void cameraSpeed(double speed) {
    z_dis += 0.063 * speed;
}


void camera() {
    if(z_dis <= 5 * 100) cameraSpeed(10);
    gluLookAt(	0.0, 2.0, 0.0 - z_dis, 
	 			0.0, 1.0, -5.0 - z_dis, 
	 			0.0, 1.0, 0.0);
}