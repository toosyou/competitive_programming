#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <algorithm>

using namespace std;

struct segment{
    int left;
    int right;
    int length;
};

bool segment_cmp(segment a, segment b){
    return a.left < b.left;
}

int main()
{
    int T = 0;
    while(scanf("%d",&T)!=EOF){
        for(int k=0;k<T;++k){

            int M = 0;
            int N = 0;
            segment lines[100001];
            int index_ans[100001];

            scanf("%d",&M);
            for(N=0;;++N){
                scanf("%d%d",&lines[N].left,&lines[N].right);
                if(lines[N].left == 0 && lines[N].right == 0)
                    break;
            }
            sort(lines,lines+N,segment_cmp);

            //calculation
            int pre_i = 0;
            int sofar = 0;
            int need = 0;
            bool not_find = true;
            while(sofar < M){
                int max_sofar = -1;
                not_find = true;
                for(int i=pre_i;i<N;++i){
                    if( lines[i].left > sofar )
                        break;
                    int far = lines[i].right - sofar;
                    if(far > max_sofar){
                        not_find = false;
                        max_sofar = far;
                        index_ans[need] = i;
                        pre_i = i+1;

                    }
                }
                if(not_find){
                    break;
                }
                sofar = lines[index_ans[need]].right;
                need++;
            }
            if(k != 0){
                printf("\n");
            }
            if(not_find){
                printf("0\n");
            }
            else{
                printf("%d",need);
                for(int i=0;i<need;++i){
                    printf("\n%d %d",lines[index_ans[i]].left,lines[index_ans[i]].right);
                }
                printf("\n");
            }

        }
    }
    return 0;
}

