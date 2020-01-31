/*
This Code is absolutely attrocious,
But I am going to leave it here cause it's funny and my first ever prorgram.
*/

#include "pch.h"
#include <iostream>
#include <algorithm>
#include <cmath>
#include <conio.h>
#include <initializer_list>
#define _USE_MATH_DEFINES
#include <math.h>

int main()
{
    using namespace std;

    cout << "ENTER X DIRECTION ADJUSTMENTS: ";
    //ask user for x direction adjustments left is negative right is positive

    long double a = 0;
    cin >> a;
    //a=-a;
    // the amount of movement in the y direction
    cout << "ENTER Y DIRECTION ADJUSTMENTS: ";
    long double b = 0;
    cin >> b;

    //distance between the center of circle 2 and all 3 Gripper
    long double d1;
    long double d2;
    long double d3;

    // The Gripper coordinates
    //
    //Gripper One
    long double Px1 = -0.919821;
    long double Py1 = -0.392337;

    //Gripper Two
    long double Px2 = 0.120137;
    long double Py2 = 0.992757;

    //Gripper Three
    long double Px3 = 0.799685;
    long double Py3 = -0.60042;

    //visible gripper locations
    cout << "\n";
    cout << "Gripper 1x: " << Px1 << endl;
    cout << "Gripper 1y: " << Py1 << endl;
    cout << "\n";
    cout << "Gripper 2x: " << Px2 << endl;
    cout << "Gripper 2y: " << Py2 << endl;
    cout << "\n";
    cout << "Gripper 3x: " << Px3 << endl;
    cout << "Gripper 3y: " << Py3 << endl;
    cout << "\n";

    //distance between each Gripper and the center of circle 2
    d1 = sqrt(pow(Px1 - a, 2) + pow(Py1 - b, 2));
    d2 = sqrt(pow(Px2 - a, 2) + pow(Py2 - b, 2));
    d3 = sqrt(pow(Px3 - a, 2) + pow(Py3 - b, 2));

    //showing the distance between the Grippers and the second circle
    cout << "distance 1 = " << d1 << endl;
    cout << "\n";
    cout << "distance 2 = " << d2 << endl;
    cout << "\n";
    cout << "distance 3 = " << d3 << endl;
    cout << "\n";

    //declare slope (change in y over change in x)
    //    Y2-Y1
    //    -----
    //    X2-X1
    long double m1;
    long double m2;
    long double m3;

    //declaring slopes in radians
    long double rad1;
    long double rad2;
    long double rad3;

    //long double pi = 3.14159265358979323846;

    //SLOPE equations
    m1 = Py1 / Px1;
    m2 = Py2 / Px2;
    m3 = Py3 / Px3;

    //SLOPE to RADIANS equations
    rad1 = atan(m1);
    rad2 = atan(m2);
    rad3 = atan(m3);

    //degrees and corrected degrees
    long double deg1;
    long double deg1corrected;
    long double rad1corrected;
    long double PI = 3.14159265358979323846;
    long double deg2;
    long double deg2corrected;
    long double rad2corrected;

    //convert rad1 to degrees and back
    //to correct for 180
    deg1 = rad1 * (180 / PI);
    deg1corrected = deg1 + 180;
    rad1corrected = deg1corrected * (PI / 180);

    deg2 = rad2 * (180 / PI);
    deg2corrected = deg2 + 180;
    rad2corrected = deg2corrected * (PI / 180);

    //Show SLOPE between center of circle 1 and grippers
    cout << "\n";
    cout << "slope 1 " << m1 << endl;
    cout << "slope 2 " << m2 << endl;
    cout << "slope 3 " << m3 << endl;
    cout << "\n";

    //Show ANGLE between center of circle 1 and grippers
    cout << "radians 1 " << rad1corrected << endl;
    cout << "radians 2 " << rad2 << endl;
    cout << "radians 3 " << rad3 << endl;
    cout << "\n";

    //Find furthest Gripper from the center of circle 2
    long double r = max({ d1, d2, d3 });

    //Show Radius equals longest distance
    cout << "radius = " << r << endl;
    cout << "\n";

    //point to which the Grippers will be grinded
    long double Gx1;
    long double Gx2;
    long double Gx3;
    long double Gy1;
    long double Gy2;
    long double Gy3;

    //distance to be grinded
    long double GD1;
    long double GD2;
    long double GD3;

    //Point to which gripper will be ground off to
    Gx1 = a + r * cos(rad1corrected);
    Gy1 = b + r * sin(rad1corrected);

    Gx2 = a + -r * cos(rad2);
    Gy2 = b + -r * sin(rad2);

    Gx3 = a + r * cos(rad3);
    Gy3 = b + r * sin(rad3);

    //show equation used to solve for grind points
    //grind point 1 shown
    cout << Gx1 << " = " << a << " + " << r << " X " << "cos(" << rad1 << ")" << endl;
    cout << Gy1 << " = " << b << " + " << r << " X " << "sin(" << rad1 << ")" << endl;
    cout << "\n";

    //grind point 1 shown
    cout << Gx2 << " = " << a << " + " << r << " X " << " cos(" << rad2 << ")" << endl;
    cout << Gy2 << " = " << b << " + " << r << " X " << " sin(" << rad2 << ")" << endl;
    cout << "\n";

    //grind point 2 shown
    cout << Gx2 << " = " << a << " + " << r << " X " << " cos(" << rad3 << ")" << endl;
    cout << Gy2 << " = " << b << " + " << r << " X " << " sin(" << rad3 << ")" << endl;
    cout << "\n";

    //grind point 3 shown
    cout << "grind point Gx1 = " << Gx1 << endl;
    cout << "grind point Gy1 = " << Gy1 << endl;
    cout << "\n";
    cout << "grind point Gx2 = " << Gx2 << endl;
    cout << "grind point Gy2 = " << Gy2 << endl;
    cout << "\n";
    cout << "grind point Gx3 = " << Gx3 << endl;
    cout << "grind point Gy3 = " << Gy3 << endl;
    cout << "\n";

    // distance equation for between Gripper point and grind point
    GD1 = sqrt(pow(Gx1 - Px1, 2) + pow(Gy1 - Py1, 2));
    GD2 = sqrt(pow(Gx2 - Px2, 2) + pow(Gy2 - Py2, 2));
    GD3 = sqrt(pow(Gx3 - Px3, 2) + pow(Gy3 - Py3, 2));

    //print the length to be grinded
    cout << "grind Gripper 1: " << GD1 << " MM" << endl;
    cout << "grind Gripper 2: " << GD2 << " MM" << endl;
    cout << "grind Gripper 3: " << GD3 << " MM" << endl;

    system("pause");

    return 0;
}
