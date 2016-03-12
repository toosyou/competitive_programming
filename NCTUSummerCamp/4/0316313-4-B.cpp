#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int max_continue_sum(int *input, int N){
    int max = -1;
    int sum = -1;
    for(int i=0;i<N;++i){
        if(sum < 0)
            sum = input[i];
        else
            sum += input[i];
        if(max < sum){
            max = sum;
        }
    }
    return max;
}

int main()
{
    int N = 0;
    while(scanf("%d",&N)!=EOF){
        int matrix[101][101];
        int sum[101];
        int max_reuslt = -1;

        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                scanf("%d",&matrix[i][j]);
            }
        }

        for(int i=0;i<N;++i){
            for(int j=0;j<N;++j){
                sum[j] = 0;
            }
            for(int j=i;j>=0;--j){
                for(int k=0;k<N;++k){
                    sum[k] += matrix[j][k];
                }
                int tmp_max = max_continue_sum(sum,N);
                if(tmp_max > max_reuslt){
                    max_reuslt = tmp_max;
                }
            }
        }
        printf("%d\n",max_reuslt);

    }
    return 0;
}

