#include <iostream>
#include <math.h>

void task1 (){
    double eps=1;
    double x=1;
    double y=1;
    while(1+eps>1){
        eps/=1.1;
        }
    std::cout << "Task 1 \n\ta) eps:= " << eps << std::endl;

    while((1+x) != x){
        x*=1.1;
        }
    std::cout << "\tb) x:= " << x << std::endl;

    while((pow(10,20)+y) != y){
        y*=1.1;
        }
    std::cout << "\tc) y:= ";
    std::cout <<  y <<"\n_______________________________"<<std::endl;
}

