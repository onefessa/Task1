#include <iostream>
#include <fstream>
#include <iomanip>
#include <cmath>
using namespace std;
double f(double x){
    return 5.*cos(8.*x) + exp(3.*pow(x,2)) + 1/cos(cos(x));
    //return pow(x,2);
}
double f_1(double x){
    return -40*sin(8*x)+6*x*exp(3*pow(x,2))-sin(x)*tan(cos(x))*1/cos(cos(x));
    //return 2*x;
}
double R1 (double x, double h){
	return abs(f_1(x) - (1./h)*(f(x+h)-f(x)));
}
double R2 (double h, double eps){
	return h/2+2*eps/h;
}
void task3 (){
    double xo, h = 1.;

    ofstream outputR1("3.h_R1.txt");
    ofstream outputR2("3.h_R2.txt");
    cout << "Task 3\n\tEnter x_0 from [0,1]: Xo = ";
    cin >> xo;
    cout<<"\n\th\tR1=|f'(Xo)-(f(Xo+h)-f(Xo))/h|\tR2=h/2+2*eps/h, eps=10^(-8)\n"<<endl;

    for(int i=0; i <= 20;i++){
        cout<<"\t"<<h << "\t"<<R1(xo,h) << "\t\t\t\t" << R2(h, pow(10,-8))<<endl;
        outputR1  << h << " "<<R1(xo,h) << endl;
        outputR2  << h << " "<<R2(h, pow(10,-8)) << endl;
        h/=10;
    }
}

