#include <iostream>
#include <cstdio>
#include <cstdlib>

using namespace std;

int main()
{
    int N = 0;
    int M = 0;
    while(scanf("%d%d",&N,&M)!=EOF){
        int feature[101][101];
        int matrix[101][101];
        for(int i=0;i<N;++i){
            char buffer[101];
            scanf("%s",&buffer);
            for(int j=0;j<M;++j){
                if(buffer[j] == 'B')
                    feature[i][j] = -1;
                else
                    feature[i][j] = 1;
            }
        }
        //init
        for(int i=0;i<N;++i){
            for(int j=0;j<M;++j){
                matrix[i][j] = 0;
            }
        }
        //calculation
        int ans = 0;
        for(int i=N-1;i>=0;--i){
            for(int j=M-1;j>=0;--j){
                if(matrix[i][j] != feature[i][j]){
                    int need_to_add = feature[i][j] - matrix[i][j];
                    for(int k=0;k<=i;++k){
                        for(int m=0;m<=j;++m){
                            matrix[k][m] += need_to_add;
                        }
                    }
                    ans++;
                }
            }
        }
        printf("%d\n",ans);

    }
    return 0;
}

