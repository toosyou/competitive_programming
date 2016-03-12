#include <iostream>
#include <stdio.h>

using namespace std;

int main()
{
    int n = 0;
    long long int m = 0;
    int ans[50];
    while(cin >> n >>m){
        int head = 0;
        int end = n-1;
        for(int i=1;i<=n;++i){
            if( m <= 1ll << (n-1-i) ){//put it at the head
                ans[head++] = i;
                //m = (1ll << (n-1-i) ) - m;
            }
            else{ // put it at the end
                ans[end--] = i;
                m = m - (1ll << (n-1-i) );
            }
        }
        for(int i=0;i<n-1;++i){
            printf("%d ",ans[i]);
        }
        printf("%d\n",ans[n-1]);
    }
    return 0;
}

