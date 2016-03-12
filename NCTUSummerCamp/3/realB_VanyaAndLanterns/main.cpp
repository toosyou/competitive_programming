#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int a[100];

int main()
{
    int n=0;
    int length=0;
    while(scanf("%d%d",&n,&length)!=EOF){
        //input
        a[0]=0;
        for(int i=0;i<n;++i){
            scanf("%d",&a[i+1]);
        }
        a[n+1]=length;
        //sort
        sort(a,a+n+1);
        //calculate for every interval
        float max_d = 0.0f;
        for(int i=0;i<n+1;++i){
            float d = ((float)(a[i+1]-a[i]) )/2.0f;
            if(i==0 || i == n){
                d = (float)(a[i+1]-a[i]);
            }
            if(max_d < d){
                max_d = d;
            }
        }
        printf("%f\n",max_d);
    }
    return 0;
}

