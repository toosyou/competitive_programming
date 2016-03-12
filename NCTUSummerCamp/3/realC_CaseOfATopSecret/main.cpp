#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <algorithm>

using namespace std;

int x[200001];

int main()
{
    int n = 0;
    int m = 0;
    while(scanf("%d%d",&n,&m)!=EOF){
        //input
        for(int i=0;i<n;++i){
            scanf("%d",&x[i]);
        }
        sort(x,x+n);

        for(int k=0;k<m;++k){
            int index_peg = 0;
            int length_rest = 0;
            bool direction_right = true;
            scanf("%d%d",&index_peg,&length_rest);
            index_peg--;
            //calculation
            int half_spin = 0;
            while(length_rest>0 && half_spin<2){
                int index_peg_next = -1;

                if(direction_right == true){//do the right spin
                    if(index_peg == n-1){//the last peg
                        half_spin++;
                        direction_right = false;
                        continue;
                    }

                    for(int i=index_peg+1;i<n;++i){//find next peg
                        if(x[i] - x[index_peg] <= length_rest){
                            index_peg_next = i;
                            half_spin = 0;
                        }
                    }

                    if(index_peg_next == -1){//can't spin right
                        direction_right = false;
                        half_spin++;
                        continue;
                    }
                    else{//find one peg to spin
                        length_rest -= (x[index_peg_next] - x[index_peg]);
                        index_peg = index_peg_next;
                        direction_right = false;
                    }
                }
                else{//do the left spin
                    if(index_peg == 0){//the last peg
                        half_spin++;
                        direction_right = true;
                        continue;
                    }

                    for(int i=index_peg-1;i>=0;--i){//find next peg
                        if(x[index_peg] - x[i] <= length_rest){
                            index_peg_next = i;
                            half_spin = 0;
                        }
                    }

                    if(index_peg_next == -1){//can't spin left
                        direction_right = true;
                        half_spin++;
                        continue;
                    }
                    else{//find one peg to spin
                        length_rest -= (x[index_peg] - x[index_peg_next] );
                        index_peg = index_peg_next;
                        direction_right = true;
                    }
                }
            }
            printf("%d\n",index_peg+1);
        }

    }
    return 0;
}

