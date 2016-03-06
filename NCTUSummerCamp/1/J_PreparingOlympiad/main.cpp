#include <iostream>
#include <vector>
#include <cstdio>

using namespace std;

int difficulty[15];
bool chosen[15];
int N=0,L=0,R=0,X=0;

bool fit(){
    int max = -1;
    int min = 10000000000;
    int total = 0;
    //get max and min and total
    for(int i=0;i<N;++i){
        if(chosen[i] == false)
            continue;
        if( difficulty[i] > max )
            max = difficulty[i];
        if( difficulty[i] < min )
            min = difficulty[i];
        total += difficulty[i];
    }
    if(total >= L && total <= R && max - min >= X)
        return true;
    return false;
}

int main()
{

    while(scanf("%d%d%d%d",&N,&L,&R,&X) != EOF){//input
        for(int i=0;i<N;++i){
            scanf("%d",&difficulty[i]);
        }
        //init
        int result = 0;
        for(int i=0;i<15;++i){
            chosen[i] = false;
        }

        for(int chosen_counter = 1;chosen_counter <= (1<<N)-1 ; ++chosen_counter){
            int mask = 1;
            for(int i=0;i<N;++i){
                if( (mask & chosen_counter) != 0)
                    chosen[i] = true;
                mask <<= 1;
            }
            if(fit()){
                result++;
            }
            for(int i=0;i<15;++i)
                chosen[i] = false;
        }
        printf("%d\n",result);
    }

    return 0;
}
