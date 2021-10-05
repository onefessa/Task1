#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
///T = 2 pi, 10 pi, 100 pi, 1 000 000 pi
///x' = z /  x = sin t / (sin t)' = cos t = z
///z' = -x / -sin t = -x
///y_{n+1} = y_n + h f(t_n)
///______________________________________________________________
/// |   T   |   h   |   |~x~(T) - x(T)|     |    |~z~(T) - z(T)|
/// |_______|_______|_______________________|____________________
/*double x(double t){
    return sin(t);
}
double z(double t){
    return cos(t);
}*/

void task5 (){
    const double pi = 3.141592653589793;
    double h = 0.1;
    double x = 0;
    double z = 1;
    double x_K, z_K;// d; K=k+1
    //double t_k = 0;
    int w = 1;
    cout<<"Task 5"<<endl;
    ofstream output0("5.txt");
    cout<<"T \th\t |~x~(T) - x(T)|  |~z~(T) - z(T)|"<<endl;
    output0<<"T \th\t |~x~(T) - x(T)| \t |~z~(T) - z(T)|"<<endl;
    for (int r = 1; r<=6;r++){
        for(int q=1; q <= 3; q++){
            string c;
            c = "5_" +to_string(w)+"pi_"+to_string(h)+".txt";
            if (w<=100){ofstream output(c);
            for(int n=0; n < w*pi/h; n++){
                x_K = x + h*z;
                z_K = z - h*x;
                output << x_K<<" "<<z_K<<endl;
                x=x_K;
                z=z_K;
                }
            }else{
                for(int n=0; n < w*pi/h; n++){
                    x_K = x + h*z;
                    z_K = z - h*x;
                    x=x_K;
                    z=z_K;
                }
            }
            cout << w<<"\t "<<h<<"\t " << abs(x_K)<<"\t" << abs(z_K-1)<<endl;
            output0<<w<<"\\pi & "<<h<<" & " << abs(x_K)<<" & " << abs(z_K-1)<<"\\\\"<<endl;
            x=0;
            z=1;
            h/=10.;
        }
        h = 0.1;
        w*=10;
    }
}
