#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int max_continue_sum(int *sum,int N){
    int max_sum = -1;
    int cur_sum = 0;
    for(int i=0;i<N;++i){
        if(sum[i] == -1)
            cur_sum = 0;
        else
            cur_sum += sum[i];
        max_sum = max_sum > cur_sum ? max_sum : cur_sum;
    }
    return max_sum;
}

int main()
{
    int M = 0;
    int N = 0;
    while(scanf("%d%d",&M,&N)!=EOF){
        if(M == 0 && N == 0)
            break;
        int matrix[101][101];
        int sum[101];

        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j){
                scanf("%d",&matrix[i][j]);
            }
        }
        //calculation
        int max_area = -1;

        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j){
                sum[j] = 0;
            }

            for(int j=i;j>=0;--j){
                for(int k=0;k<N;++k){
                    if( matrix[j][k] == 0 && sum[k] != -1)
                        sum[k] += 1;
                    else
                        sum[k] = -1;
                }
                int area = max_continue_sum(sum,N);
                max_area = max_area > area ? max_area : area;
            }
        }
        printf("%d\n",max_area);
    }
    return 0;
}

