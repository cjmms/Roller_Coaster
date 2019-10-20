
#include <math.h>
#include <stdio.h>

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