#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int N = -1;
    while(scanf("%d",&N) != EOF && N != 0){
        int take_max = 0;
        int input = 0;
        int max_reault = -1;
        for(int i=0;i<N;++i){
            scanf("%d",&input);
            if(take_max > 0)
                take_max = take_max + input;
            else
                take_max = input;
            if(max_reault < take_max)
                max_reault = take_max;
        }
        if(max_reault > 0)
            printf("The maximum winning streak is %d.\n",max_reault);
        else
            printf("Losing streak.\n");
    }
    return 0;
}

