#include <iostream>
#include <fstream>
#include <cmath>
#include <string>
double y(double t){//аналитическая кривая и наборы точек, полученные методом эйлера
	return pow(t,2);
}

void task4 (){
    double h = 0.1;
    double D = 0;
    double y_0 = 0;//=0
    double y_K, d;///K=k+1
    double t_k = 0;
    std::cout<<"Task 4"<<std::endl;
///y_{k+1} = y_k + (t_ {k+1}- t_k)* f(t_k, y_k); y_{1} = y_0 + (t_1 - t_0)* y_0;
    for(int q=1; q <= 3; q++){
        std::string c;
        c = "4." + to_string(q)+".txt";
        std::ofstream output(c);
        for(int n=0; n < 10/h;n++){
            y_K = y_0 + h*(2*t_k);
            d = abs(y_K-pow(t_k,2));
            output << t_k << " " << y_K <<endl;//<< " "  d << std::endl;
            y_0=y_K;
            t_k+=h;
            if (d >= D) {D = d;}
            }
        std::cout << "\tError for step h = "<<h<<": " << D <<std::endl;
        t_k=0;
        y_0=0;
        output << std::endl;
        h/=10.;
        }
}
