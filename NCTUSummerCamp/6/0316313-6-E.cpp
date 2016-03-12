#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int breed[100001];
bool gotten[10001];

int main()
{
    int N = 0;
    int K = 0;
    scanf("%d%d",&N,&K);
    //init
    int ans = 0;
    for(int i=0;i<=K;++i){
        gotten[i] = false;
    }
    //input
    for(int k=0;k<N;++k){
        scanf("%d",&breed[k]);
    }
    for(int i=0,j=0;i<N;++i){
        if( gotten[ breed[i] ] == false ){
            gotten[ breed[i] ] = true;
            j++;
        }
        if( j == K){
            for(int k=0;k<=K;++k)
                gotten[k] = false;
            j = 0;
            ans++;
        }
    }
    printf("%d\n",ans+1);
    return 0;
}

