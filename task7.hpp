#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

void RK_Dinamical (){
	double k1,l1,k2,l2, k3,l3,k4,l4,k5,l5,k6,l6,k7,l7,x,z,x0,z0,x_roof,z_roof,t,T,h,tol,err1,err2,err, L,
                    N_st,sum,x_1,x_2,x_3,z_1,z_2,z_3;
    ofstream output ("7.txt");
    cout <<"x0-sin(T)       z0-cos(T)      N_st    Step=sum/N_st"<<endl;
	for(int j=0; j<5;j++){
        //cout<< "j = "<<j<<endl;
		T = M_PI*pow(10,1+j);cout<<T<<endl;
		for (int i=0;i<3;i++){
			tol = 1./pow(10,7+2*i);
			x0=0; z0=1;
			t=0;
			h=0.1;
			N_st=1;
			sum=h;
			while(t<T){
                if (t+h > T) {h = T - t;}

                k1 = h*z0;
                l1 = -h*(x0);
                k2 = h*(z0 + (1/5.)*l1);
                l2 = -h*(x0 + (1/5.)*k1);
                k3 = h*(z0+(3/40.)*l1 + (9/40.)*l2);
                l3 = -h*(x0+(3/40.)*k1 + (9/40.)*k2);
                k4 = h*(z0 + (44/45.)*l1 - (56/15.)*l2 + (32/9.)*l3);
                l4 = -h*(x0 + (44/45.)*k1 - (56/15.)*k2 + (32/9.)*k3);
                k5 = h*(z0 + (19372/6561.)*l1 - (25360/2187.)*l2 + (64448/6561.)*l3 - (212/729.)*l4);
                l5 = -h*(x0 + (19372/6561.)*k1 - (25360/2187.)*k2 + (64448/6561.)*k3 - (212/729.)*k4);
                k6 = h*(z0 + (9017/3168.)*l1 - (355/33.)*l2 + (46732/5247.)*l3 +(49/176.)*l4 -(5103/18656.)*l5);
                l6 = -h*(x0 + (9017/3168.)*k1 - (355/33.)*k2 + (46732/5247.)*k3 +(49/176.)*k4 -(5103/18656.)*k5);
                k7 = h*(z0 + (35/384.)*l1 + (500/1113.)*l3 + (125/192.)*l4 - (2187/6784.)*l5 + (11/84.)*l6);
                l7 = -h*(x0 + (35/384.)*k1 + (500/1113.)*k3 + (125/192.)*k4 - (2187/6784.)*k5 + (11/84.)*k6);

                x = x0 + (35/384.)*k1 + (500/1113.)*k3 + (125/192.)*k4 - (2187/6784.)*k5 + (11/84.)*k6;
                z = z0 + (35/384.)*l1 + (500/1113.)*l3 + (125/192.)*l4 - (2187/6784.)*l5 + (11/84.)*l6;

                x_roof = x0 +(5179/57600.)*k1 + (7571/16695.)*k3 + (393/640.)*k4 - (92097/339200.)*k5 + (187/2100.)*k6 + (1/40.)*k7;
                z_roof = z0 +(5179/57600.)*l1 + (7571/16695.)*l3 + (393/640.)*l4 - (92097/339200.)*l5 + (187/2100.)*l6 + (1/40.)*l7;
                N_st+=1;

                err1=fabs(x-x_roof);
                err2=fabs(z-z_roof);
                err=fmax(err1,err2);

                if(err<tol){
                    x0 = x;
                    z0 = z;
                    t += h;
                }
                /// facmax = 1.5, facmin = 0.7, fac = 0.9;
                ///h = h * Min(facmax, Max(facmin, fac * pow(tol/Norma(x_i, y_i, x_k, y_k), 1.0/(P + 1))));
                ///h=h*fmin(1.5, fmax(0.7, 0.98*pow(tol/err, 1./6)));
                h=h*fmin(1.5, fmax(0.7, 0.9*pow(tol/err, 1./6)));
                sum = sum + h;
            }
            if(i==0){
                x_1=x0;
                z_1=z0;
            }
            if(i==1){
                x_2=x0;
                z_2=z0;
            }
            if(i==2){
                x_3=x0;
                z_3=z0;
            }
            L = sum/N_st;
            cout<<fabs(x0-sin(T))<<"\t"<<fabs(z0-cos(T))<< "\t" <<N_st<<"\t"<< L <<endl;
            output<<"$10^{-"<< 7+2*i <<"}$&"<<"$"<<fabs(x0-sin(T))<<"$ & $"<<fabs(z0-cos(T))<< "$ & $" <<N_st<<"$ & $"<<L<<"$ \\\\ "<<endl;
		}
        cout<<" RK: "<<fabs((x_1 - x_2)/(x_2-x_3))<<" "<<fabs((z_1 - z_2)/(z_2-z_3))<<"\n"<<endl;
        output<<fabs((x_1 - x_2)/(x_2-x_3))<<"$ & $"<<fabs((z_1 - z_2)/(z_2-z_3))<<"$ \\\\"<<endl;
	}
}



void task7 (){
    cout<<"\nTask 7\n"<<endl;
    RK_Dinamical();
}
