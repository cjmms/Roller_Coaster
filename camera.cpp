#include "camera.h"



double eye_y = 0.0;
double eye_z = -500.0;

double z_slope = 0.0;
double y_slope = 0.0;
double t_slope_1 = 0;
double t_slope_2 = 0.0;
double t_up_1 = 0.0;
double t_up_2 = 0.0;
double t_down_1 = 0.0;
double t_down_2 = 0.0;

int DOWN = 1;
int UP = -1;

double speed = 15;

Point start, ctl1, ctl2, end;

void setSpeed(double input) {
    speed = input;
}

double getSpeed(double speed) {
    if (speed == 5) return 0.5;
    else if (speed == 10) return 1;
    else return 2;
}

void cameraAperture() {


}


void cameraSpeed(double speed) {
    eye_z -= 0.063 * speed * getSpeed(speed);
}

void findCtlPoints(double degree, int turn, int length) {
    start.set(0, eye_y, eye_z);
    end = findEndPoint(start, degree, length * segLength);

    ctl1.set(0, start.y + end.y / 4 + 5 * turn, end.z / 5 + start.z);
    ctl2.set(0, start.y + end.y * 0.75 + 2 * turn, end.z * 0.75 + start.z);

    end.z += start.z;
    end.y += start.y;
}


void camera() {
    // level section length 100
    if (eye_z > -segLength * 200) {
        cameraSpeed(speed);
    }
    else if (!areSame(1, t_down_1)) {
        if (t_down_1 == 0) findCtlPoints(-30, DOWN, 10);
        Point P = setBezier(start, ctl1, ctl2, end, t_down_1 += 0.025 );
        eye_z = P.z;
        eye_y = P.y;
    } 
    else if (!areSame(1.1, t_slope_1)) {
        if (t_slope_1 == 0) {
            z_slope = eye_z;
            y_slope = eye_y;
        }
        double degree = 26.5;
        eye_z = z_slope - 50 * segLength * cos(degree * M_PI / 180.0) * t_slope_1 ;
        eye_y = y_slope - 50 * segLength * sin(degree * M_PI / 180.0) * t_slope_1 ;
        t_slope_1 += 0.0025 * getSpeed(speed);
    } 
    else if (!areSame(1, t_up_1)) {
        if (t_up_1 == 0) findCtlPoints(-30, UP, 10);
        Point P = setBezier(start, ctl1, ctl2, end, t_up_1 += 0.025 );
        eye_z = P.z;
        eye_y = P.y;
    } 
    else if (!areSame(1, t_up_2)) {
        if (t_up_2 == 0) findCtlPoints(30, UP, 10);
        Point P = setBezier(start, ctl1, ctl2, end, t_up_2 += 0.025 );
        eye_z = P.z;
        eye_y = P.y;
    } 
    else if (!areSame(1.1, t_slope_2)) {
        if (t_slope_2 == 0) {
            z_slope = eye_z;
            y_slope = eye_y;
        }
        double degree = 26.9;
        eye_z = z_slope - 50 * segLength * cos(degree * M_PI / 180.0) * t_slope_2 ;
        eye_y = y_slope + 50 * segLength * sin(degree * M_PI / 180.0) * t_slope_2 ;
        t_slope_2 += 0.0025 * getSpeed(speed);
    } 
    else if (!areSame(1, t_down_2)) {
        if (t_down_2 == 0) findCtlPoints(30, DOWN, 10);

        Point P = setBezier(start, ctl1, ctl2, end, t_down_2 += 0.025 );
        eye_z = P.z;
        eye_y = P.y; 
    } 
    else {
        eye_y = 0.0;
        eye_z = -500.0;
        z_slope = 0.0;
        y_slope = 0.0;
        t_slope_1 = 0;
        t_slope_2 = 0.0;
        t_up_1 = 0.0;
        t_up_2 = 0.0;
        t_down_1 = 0.0;
        t_down_2 = 0.0;
    }
    // downturn


    gluLookAt(	0.0, eye_y + 2, eye_z, 
	 			0.0, eye_y + 1, eye_z - 5, 
	 			0.0, 1.0, 0.0);
}