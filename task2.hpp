#include <iostream>
#include <cmath>

void task2 (){
    int deg, big_deg;
    double I_0,I_n, I_big_deg, d;
    d = 0.001/2;
    I_0 = log(7/6.);     //cout<<I_0<<endl;
    std::cout<<"Task 2\t\t\tEnter degree n of x^n (n=31): ";
    std::cin>>deg;
    if (deg==0){
            I_n=I_0;
            std::cout<<"\t"<<"I["<<deg<<"] = "<<I_n<<std::endl;
    }else
        for(int n = 1; n <= deg; n++){
            I_n = (1.)/n-6*(I_0);
            //cout<<"\t\t\t"<<"I_"<<n<<" = "<<I_n<<endl;
            I_0=I_n;
        }
    std::cout <<"\tA) I_"<< deg <<" = "<< I_n<<"\t|\t I_n = 1/n - 6*I_n-1"<<std::endl;
    I_n = 0.;
    for(int k=1; k<=1000; k++){
        I_n+=(0.001)*(pow(d,deg))/(d+6);
        //cout<<"k = "<<k<<"\t"<<"q = "<<q<<endl;
        d+=0.001;
        }
    std::cout <<"\tC) I_"<< deg <<" = "<< I_n <<"\t|\t k = 1000; S_darbu"<<std::endl;

    if (deg==0){
        std::cout << "\tB) I{"<< deg-1 <<"} doesn't exist."<< std::endl;
        } else {
        std::cout<<"\t\t\tEnter number n from approximate I_n = 0 (I_62 = 0): n = ";
        std::cin >> big_deg;
        I_big_deg=0;
            for(int n=big_deg-1; n>=deg; n--){
                I_n=(1.)/(6*(n)) - I_big_deg/6;
                //cout<<"m = "<<m<<"\t"<<"Jm = "<<Jm<<endl;
                I_big_deg = I_n;
            }
            std::cout<<"\tB) I_"<< deg <<" = "<< I_n<<"\t|\t I_n-1 = 1/(6n) - I_n/6\n_______________________________"<<std::endl;
        }
}
