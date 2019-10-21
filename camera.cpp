#include "camera.h"



double eye_y = 0.0;
double eye_z = 0.0;

double z_slope = 0.0;
double y_slope = 0.0;
double t_slope = 0;
double t_up = 0.0;

int DOWN = 1;
int UP = -1;

Point start, ctl1, ctl2, end;

double t = 0.0;

void cameraAperture() {


}


void cameraSpeed(double speed) {
    eye_z -= 0.063 * speed;
    //look_z -= 0.063 * speed;
}

void findCtlPoints(double degree, int turn, int length) {
    start.set(0, eye_y, eye_z);
    end = findEndPoint(start, degree, length * segLength);

    // printf("difference: %f and %f\n", end.z / 5 - 500,  end.z/5 + start.z);
    // printf("start z: %f\n", start.z);
    // printf("end z: %f\n", end.z);

    ctl1.set(0, start.y + end.y / 4 + 5 * turn, end.z / 5 + start.z);
    ctl2.set(0, start.y + end.y * 0.75 + 2 * turn, end.z * 0.75 + start.z);

    end.z += start.z;
    end.y += start.y;
}


void camera() {
    // level section length 100
    if (eye_z > -5 * 100) {
        cameraSpeed(10);
    }
    else if (!areSame(1, t)) {
        if (t == 0) findCtlPoints(-30, DOWN, 10);

        Point P = setBezier(start, ctl1, ctl2, end, t+=0.025);
        eye_z = P.z;
        eye_y = P.y;
        //printf("turn t: %f, y: %f, z: %f\n", t, eye_y, eye_z);
    } else if (!areSame(1.1, t_slope)) {
        if (t_slope == 0) {
            z_slope = eye_z;
            y_slope = eye_y;
        }
        double degree = 26.5;
        eye_z = z_slope - 50 * segLength * cos(degree * M_PI / 180.0) * t_slope;
        eye_y = y_slope - 50 * segLength * sin(degree * M_PI / 180.0) * t_slope;

        //printf("turn t_slope: %f, y: %f, z: %f\n", t_slope, eye_y, eye_z);
        t_slope += 0.0025;
    } else if (!areSame(1, t_up)) {
        if (t_up == 0) findCtlPoints(-30, UP, 10);
        printf("start_y: %f, start_z: %f\n", start.y, start.z);
        printf("end_y: %f, end_z: %f\n", end.y, end.z);

        printf("ctl1_y: %f, ctl1_z: %f\n", ctl1.y, ctl1.z);
        printf("ctl2_y: %f, ctl2_z: %f\n\n", ctl2.y, ctl2.z);


        Point P = setBezier(start, ctl1, ctl2, end, t_up+=0.025);
        eye_z = P.z;
        eye_y = P.y;

        //printf("turn t_slope: %f, y: %f, z: %f\n", t_up, eye_y, eye_z);
    }


    // downturn


    gluLookAt(	0.0, eye_y + 2, eye_z, 
	 			0.0, eye_y + 1, eye_z - 5, 
	 			0.0, 1.0, 0.0);
}