#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

int n = 0;

double table[22][22][22];
int path[22][22][22];

int main()
{
    while(scanf("%d",&n) != EOF){
        //init
        for(int k=0;k<n;++k){
            for(int i=0;i<n;++i){
                for(int j=0;j<n;++j){
                    table[i][j][k] = 0;
                }
            }
        }
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                path[i][j][0] = i;
            }
        }

        //input
        for(int i=0;i<n;++i){
            for(int j=0;j<n;++j){
                if(i == j){
                    table[i][j][0] = 1.0;
                    continue;
                }
                else
                    scanf("%lf",&table[i][j][0]);
            }
        }

        //modified floyd warshall
        bool find_ans = false;
        for(int step=1;step<n;++step){
            for(int k=0;k<n;++k){
                for(int i=0;i<n;++i){
                    for(int j=0;j<n;++j){
                        if( table[i][j][step] < table[i][k][step-1] * table[k][j][0] ){
                            table[i][j][step] = table[i][k][step-1] * table[k][j][0];
                            path[i][j][step] = k;
                        }
                    }
                }
            }
            //check
            for(int i=0;i<n;++i){
                if(table[i][i][step] > 1.01){
                    find_ans = true;
                    //output the ans
                    int last = i;
                    vector<int> ans;
                    for(int j=0;j<=step;++j){
                        ans.push_back(last);
                        last = path[i][last][step-j];
                    }
                    ans.push_back(i);
                    for(int j=ans.size()-1;j>=0;--j){
                        if(j==0)
                            printf("%d",ans[j]+1);
                        else
                            printf("%d ",ans[j]+1);
                    }
                    printf("\n");
                    break;
                }
            }
            if(find_ans)
                break;
        }
        if(find_ans == false)
            printf("no arbitrage sequence exists\n");

    }
    return 0;
}
