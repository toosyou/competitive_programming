#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int a[200001];

int main()
{
    int n=0;
    int w=0;

    while(scanf("%d%d",&n,&w)!=EOF){
        //input
        for(int i=0;i<2*n;++i){
            scanf("%d",&a[i]);
        }
        //sort it
        sort(a,a+2*n);
        float x = min((float)a[0],(float)a[n]/2.0f);
        if(3.0*x*(float)n > w){
            printf("%f\n",(float)w);
        }
        else{
            printf("%f\n",x*3.0*(float)n);
        }
    }

    return 0;
}

