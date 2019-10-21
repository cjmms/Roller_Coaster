#include "camera.h"



double eye_y = 0.0;
double eye_z = 0.0;

double z_slope = 0.0;
double y_slope = 0.0;
double t_slope = 0;

Point start, ctl1, ctl2, end;

double t = 0.0;

void cameraAperture() {


}


void cameraSpeed(double speed) {
    eye_z -= 0.063 * speed;
    //look_z -= 0.063 * speed;
}

void findCtlPoints() {
    start.set(0, eye_y, eye_z);
    end = findEndPoint(start, -30, 10 * segLength);
    
    ctl1.set(0, end.y / 4 + 5, end.z / 5 - 500);
    ctl2.set(0, end.y * 0.75 + 2, end.z * 0.75 - 500);

    end.z += -500;
}


void camera() {
    // level section length 100
    if (eye_z > -5 * 100) {
        cameraSpeed(10);
        //printf("striangt\n");
    }
    else if (!areSame(1, t)) {
        if (t == 0) findCtlPoints();

        Point P = setBezier(start, ctl1, ctl2, end, t+=0.025);
        eye_z = P.z;
        eye_y = P.y;
        printf("turn t: %f, y: %f, z: %f\n", t, eye_y, eye_z);
    } else if (!areSame(1.1, t_slope)) {
        if (t_slope == 0) {
            z_slope = eye_z;
            y_slope = eye_y;
        }
        double degree = 26.5;
        eye_z = z_slope - 50 * segLength * cos(degree * M_PI / 180.0) * t_slope;
        eye_y = y_slope - 50 * segLength * sin(degree * M_PI / 180.0) * t_slope;

        printf("turn t_slope: %f, y: %f, z: %f\n", t_slope, eye_y, eye_z);
        t_slope += 0.0025;
    }


    // downturn


    gluLookAt(	0.0, eye_y + 2, eye_z, 
	 			0.0, eye_y + 1, eye_z - 5, 
	 			0.0, 1.0, 0.0);
}