#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int T = 0;
    while(scanf("%d",&T) != EOF){
        for(int k=0;k<T;++k){
            int N = 0;
            int number_growing = 0;
            int ans = 0;
            bool can_grow[101];
            char input_buffer[101];

            scanf("%d",&N);
            scanf("%s",input_buffer);
            for(int i=0;i<N;++i){
                if(input_buffer[i] == '.'){
                    can_grow[i] = true;
                    number_growing++;
                }
                else
                    can_grow[i] = false;
            }

            //binary search for ans
            /*int lower = 0;
        int upper = number_growing+1;
        while(lower < upper){
            int have = (lower + upper)/2;
            int needed = 0;
            //greedy for needed
            for(int i=0;i<N;++i){
                if(can_grow[i]){
                    needed++;
                    i += 2;
                }
            }
            if(needed > have){

            }
            else{

            }
        }*/
            for(int i=0;i<N;++i){
                if(can_grow[i]){
                    ans++;
                    i += 2;
                }
            }
            printf("Case %d: %d\n",k+1,ans);
        }
    }
    return 0;
}
