#include <iostream>
#include <fstream>
#include <cmath>
#include <string>

double y(double t){//аналитическая кривая и наборы точек, полученные методом эйлера
	return pow(t,2);
}
void task4 (){
    double h = 0.1;
    //double D = 0;
    double y_0 = 0;//=0
    double y_K;// d; K=k+1
    double t_k = 0;
    std::cout<<"Task 4"<<std::endl;
    std::ofstream output0("4.txt");
    std::cout<<"f(0) = "<<f(0)<<std::endl;///f(to)
///y_{k+1} = y_k + (t_ {k+1}- t_k)* f(t_k, y_k); y_{1} = y_0 + (t_1 - t_0)* y_0;
    for(int q=1; q <= 3; q++){
        std::string c;
        c = "4a." + to_string(q)+".txt";
        std::ofstream output(c);
        for(int n=0; n < 10/h;n++){
            y_K = y_0 + h*(2*t_k);
            //d = abs(y_K-pow(t_k,2));
            output << t_k << " " << y_K;// << " " << d << std::endl;
            y_0=y_K;
            t_k+=h;
            //if (d >= D) {D = d;}
            }
        std::cout<<"A) t_k = "<<t_k<<std::endl;///f(to)
        std::cout << "\tError for step h = "<<h<<": " << abs(y_K-pow(t_k,2)) <<std::endl;
        output0<<"Error for step h = "<<h<<": " << abs(y_K-pow(t_k,2)) <<std::endl;
        t_k=0;
        y_0=0;
        output << std::endl;
        h/=10.;
        }
    h = 0.1;
    y_0=f(t_k);
    std::cout<<"t_k = "<<t_k<<"y_0 = "<<y_0<<std::endl;///f(to)
    for(int q=1; q <= 3; q++){
        std::string c;
        c = "4b." + to_string(q)+".txt";
        std::ofstream output(c);
        for(int n=0; n < 2.5/h; n++){
            y_K = y_0 + h*f_1(t_k);
            //d = abs(y_K-f(t_k));
            output << t_k << " " << y_K << std::endl;//<< " " << d << std::endl;
            y_0=y_K;
            t_k+=h;
            //if (d >= D) {D = d;}
            }
        std::cout<<"B) t_k = "<<t_k<<std::endl;///f(to)
        std::cout << "\tError for step h = "<<h<<": " << abs(y_K-f(t_k)) <<std::endl;
        output0<<"Error for step h = "<<h<<": " << abs(y_K-f(t_k)) <<std::endl;
        t_k=0;
        y_0=f(t_k);
        output << std::endl;
        h/=10.;
        }
}
