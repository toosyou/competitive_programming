#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

int money[200001];

int main()
{
    int N = 0;
    while(scanf("%d",&N)!=EOF){
        for(int i=0;i<N;++i){
            scanf("%d",&money[i]);
            money[i] += i;
        }
        sort(money,money+N);
        bool yes_it_fit = true;
        for(int i=1;i<N;++i){
            if(money[i-1]-i+1 > money[i]-i){
                yes_it_fit = false;
                break;
            }
        }
        if(yes_it_fit){
            for(int i=0;i<N;++i){
                if(i != 0)
                    printf(" ");
                printf("%d",money[i]-i);
            }
            printf("\n");
        }
        else{
            printf(":(\n");
        }
    }
    return 0;
}

