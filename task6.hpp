#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
/* 0         |
/// c_2      |   a_21
/// c_3      |   a_31    a_32
_____________|________________
///          |   b_1     b_2 */

/// 0        |
/// 1./5     |   1./5
/// 3./10    |   3./40          9./40
/// 4./5     |   44./45         -56./15       32./9
/// 8./9     |   19372./6561    25360./2187     64448./6561     -212./729
/// 1        |   9017./3168     -355./33        46732./5247     49./176     -5103./18656
/// 1        |   35./384        0               500./1113       125./192    -2187./6784     11./84
///__________|____________________________________________________________________________________________
/// y_1      |   35./384        0               500./1113       125./192    -2187./6784     11./84      0

pair <double, double> RKa (double x, double h){
    ofstream output ("6.txt");
    double k1, k3, k4, k5, k6, y = 0, y_0 = f(x);
    for (int i=0; i<1/h; i++){
        k1 = f_1(x);
        k3 = f_1(x + (3./10)*h);
        k4 = f_1(x + (4./5)*h);
        k5 = f_1(x + (8./9)*h);
        k6 = f_1(x + (1.)*h);
        y += y_0 + h*((35./384)*k1 + (500./1113)*k3 + (125./192)*k4 + (-2187./6784)*k5 + (11./84)*k6);
        x += h;
        output<< "Pogreshnost' : x = " << x<< ";  y = " << y<<"; f(x) = "<<f(x)<< "; " <<abs(y-f(x)) << endl;
    }
    return std::pair<double, double>(x,y);
}


pair<double, double> RKb (double x, double z){
    const double pi = 3.141592653589793;
    double k1[2], k3[2], k4[2], k5[2], k6[2], x_K, z_K, t = 0,  h = 0.01;
    ofstream output ("6b_xz.txt");
    ofstream outputp ("6b_pp.txt");
    for (int i=0; i < 100*pi/h; i++){
        k1[0] = z;
        k1[1] = -x;
        //k2[0] = x + h*(1./5);
        //k2[1] = -z - h*(1./5);
        k3[0] = z + h*(3./10);
        k3[1] = -x - h*(3./10);
        k4[0] = z + h*(4./5);
        k4[1] = -x - h*(4./5);
        k5[0] = z + h*(8./9);
        k5[1] = -x - h*(8./9);
        k6[0] = z + h*(1.);
        k6[1] = -x - h*(1.);
        //k7[0] = x + h*(1.);
        //k7[1] = -z - h*(1.);
        x_K = x + h*((35./384)*k1[0] + (500./1113)*k3[0] + (125./192)*k4[0] + (-2187./6784)*k5[0] + (11./84)*k6[0]);
        z_K = z + h*((35./384)*k1[1] + (500./1113)*k3[1] + (125./192)*k4[1] + (-2187./6784)*k5[1] + (11./84)*k6[1]);
        t+=h;
        x=x_K;
        z=z_K;
///x' = z   |  x = sin t / (sin t)' = cos t = z
///z' = -x  | -sin t = -x
        output << x << " " << z << endl;
        outputp<<"dx = "<< (sin(t) - x) << ";\t dz = "<< (cos(t) - z) << endl;
    }
    cout<<"delta x "<< (sin(t) - x) << " : delta z "<< (cos(t) - z) << endl;
    return pair <double, double>(x,z);
}

void task6(){
    cout<<"Task 6a\n"<<endl;

    pair <double, double> h1a = RKa(0, 0.1);
    cout<< "\tx = "<<h1a.first<< ";\t h = 0.1; \t D = "<<abs(f(1) - h1a.second) <<endl;
    pair <double, double> h2a = RKa(0, 0.01);
    cout<< "\tx = "<<h2a.first<< ";\t h = 0.01; \t D = "<<abs(f(1) - h2a.second) <<endl;
    pair <double, double> h3a = RKa(0, 0.001);
    cout<< "\tx = "<<h3a.first<< ";\t h = 0.001; \t D = "<<abs(f(1) - h3a.second) <<endl;

    cout<<"Task 6b\n"<<endl;
    pair <double, double> h1b = RKb(0, 1);
    cout<< "h = 0.001;\tx = "<<h1b.first<<"\tz = "<<h1b.second<<endl;
}
