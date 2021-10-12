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
    ofstream output_a ("6a.txt");
    double k1, k3, k4, k5, k6, y_0, y = 0;
    for (int i=0; i<1/h; i++){
        y_0 = f(x);

        k1 = f_1(x);
        k3 = f_1(x + (3./10)*h);
        k4 = f_1(x + (4./5)*h);
        k5 = f_1(x + (8./9)*h);
        k6 = f_1(x + (1.)*h);

        y = y_0 + h*((35./384)*k1 + (500./1113)*k3 + (125./192)*k4 + (-2187./6784)*k5 + (11./84)*k6);
        x += h;

        ///output<< "Err : x = " << x<< ";  y = " << y<<"; f(x) = "<<f(x)<< "; D =" <<abs(y-f(x)) << endl;
        output_a<< x << "; " << y << endl;
    }

    return std::pair<double, double>(x,y);
}

pair<double, double> RKb (double x, double z, int T, double h){
    const double pi = 3.141592653589793;
    double k1,l1,k2,l2, k3,l3,k4,l4,k5,l5, k6,l6, x_K, z_K, t = 0;//  h = 0.001;
    ofstream output ("6b_xz.txt");
    //ofstream outputp ("6b_pp.txt");
    for (int i=0; i < T*pi/h; i++){
        t += h;
        k1 = z;
        l1 = -x;
        k2 = z + (1/5.)*h*l1;
        l2 = -(x + (1/5.)*h*k1);
        k3 = (z +h*((3/40.)*l1 + (9/40.)*l2));
        l3 = -(x +h*((3/40.)*k1 + (9/40.)*k2));
        k4 = z + h*((44/45.)*l1 - (56/15.)*l2 + (32/9.)*l3);
        l4 = -(x +h*((44/45.)*k1 - (56/15.)*k2 + (32/9.)*k3));
        k5 = z + h*((19372/6561.)*l1 - (25360/2187.)*l2 + (64448/6561.)*l3 - (212/729.)*l4);
        l5 = -(x +h*((19372/6561.)*k1 - (25360/2187.)*k2 + (64448/6561.)*k3 - (212/729.)*k4));
        k6 = z + h*((9017/3168.)*l1 - (355/33.)*l2 + (46732/5247.)*l3 +(49/176.)*l4 -(5103/18656.)*l5);
        l6 = -(x + h*((9017/3168.)*k1 - (355/33.)*k2 + (46732/5247.)*k3 +(49/176.)*k4 -(5103/18656.)*k5));
        //k7 = (z + (35/384.)*l1 + (500/1113.)*l3 + (125/192.)*l4 - (2187/6784.)*l5 + (11/84.)*l6);
        //l7 = -(x + (35/384.)*k1 + (500/1113.)*k3 + (125/192.)*k4 - (2187/6784.)*k5 + (11/84.)*k6);
        x_K = x + h*((35/384.)*k1 + (500/1113.)*k3 + (125/192.)*k4 - (2187/6784.)*k5 + (11/84.)*k6);
        z_K = z + h*((35/384.)*l1 + (500/1113.)*l3 + (125/192.)*l4 - (2187/6784.)*l5 + (11/84.)*l6);
        t+=h;
        x=x_K;
        z=z_K;
///x' = z   |  x = sin t / (sin t)' = cos t = z
///z' = -x  | -sin t = -x
        output << x << " " << z << endl;
        //outputp<<"dx = "<< (sin(t) - x) << ";\t dz = "<< (cos(t) - z) << endl;
        //outputp<< (sin(t) - x) << "; "<< (cos(t) - z) << endl;
    }
    //cout<<"delta x "<< (sin(t) - x) << " : delta z "<< (cos(t) - z) << endl;
    return pair <double, double>(x,z);
}

void task6(){
    ofstream output ("6.txt");

    cout<<"\nTask 6a\n"<<endl;
    double h = 1.;
    pair <double, double> h_a;
	for(int i=1;i<=5;i++){
		h/=10;
		h_a = RKa(0, h);
		cout<< "\tx = "<<h_a.first<< ";\t h = "<<h<<"; \t D = "<<abs(f(1) - h_a.second) <<endl;
		output<< "\tx = " << h_a.first << ";\t h = " << h << "; \t D = " << abs(f(1) - h_a.second) <<endl;
	}

    cout<<"Task 6b\n"<<endl;
    double w = 10, h = 0.1;
    pair <double, double> h_b;
    for(int r=1; r <= 3; r++){
        for (int q = 1; q<=3;q++){
            h_b = RKb(0, 1, w, h);
            cout << w<<"\t "<<h<<"\t " << abs(h_b.first)<<"\t" << abs(h_b.second-1)<<endl;
            output<<w<<"\\pi & "<<h<<" & " << abs(h_b.first)<<" & " << abs(h_b.second-1)<<"\\\\"<<endl;
            w*=10;
        }
        w = 10;
        h /= 10;
    }
}

