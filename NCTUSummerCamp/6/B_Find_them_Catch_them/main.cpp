#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <cstring>

using namespace std;

int N = 0;
int M = 0;

struct gang_node{
    int index_father;
};

gang_node gang[200002];

int find(int index_orig){
    int index = index_orig;
    while(gang[index].index_father != index){
        index = gang[index].index_father;
    }
    return index;
}

void uni(int index_a,int index_b){
    int father_a = find(index_a);
    int father_b = find(index_b);
    if( father_a < father_b ){
        gang[father_b].index_father = father_a;
    }
    else{
        gang[father_a].index_father = father_b;
    }
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int k=0;k<T;++k){
        scanf("%d%d%*c",&N,&M);
        //init
        for(int i=0;i<=2*N+1;++i){
            gang[i].index_father = i;
        }
        //input 'n calculate
        for(int i=0;i<M;++i){
            char command = 0;
            int a = 0;
            int b = 0;
            scanf("%c%d%d%*c",&command,&a,&b);

            if(command == 'D'){//different
                uni(a,b+N);
                uni(a+N,b);
            }
            else{
                if(find(a) == find(b)){
                    printf("In the same gang.\n");
                }
                else if(find(a) == find(b+N)){
                    printf("In different gangs.\n");
                }
                else{
                    printf("Not sure yet.\n");
                }
            }
        }

    }
    return 0;
}

