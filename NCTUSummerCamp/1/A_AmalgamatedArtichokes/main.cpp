#include <iostream>
#include <math.h>

using namespace std;

double price(double p,double a,double b,double c,double d,double k){
    return p*(sin(a*k+b)+cos(c*k+d)+2.0);
}

int main(){

    double p=0,a=0,b=0,c=0,d=0;
    unsigned int n = 0;
    while(cin >> p >> a >> b >> c >> d >> n){
        double max_decline = 0.0;
        double max_value = -99999.9;
        for(unsigned int i=1;i<=n;++i){
            double value = price(p,a,b,c,d,(double)i);
            //get maximum value from price(i)
            if(value >= max_value){
                max_value = value;
            }//update max_decline
            else if( max_value - value > max_decline){
                max_decline = max_value - value;
            }
        }
        printf("%lf\n",max_decline);
    }
    return 0;
}

