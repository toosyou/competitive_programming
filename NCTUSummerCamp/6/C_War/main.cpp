#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int index_father[20002];

int find(int index){
    while(index_father[index] != index){
        index = index_father[index];
    }
    return index;
}

int uni(int index_a, int index_b){
    int father_a = find(index_a);
    int father_b = find(index_b);
    if(father_a < father_b){
        index_father[father_b] = father_a;
    }
    else if(father_b < father_a){
        index_father[father_a] = father_b;
    }
    else{
        return -1;
    }
    return 0;
}

int main()
{
    int n = 0;
    scanf("%d",&n);
    //init
    for(int i=0;i<=2*n+1;++i){
        index_father[i] = i;
    }
    //input
    int c = 0;
    int x = 0;
    int y = 0;
    while(scanf("%d%d%d",&c,&x,&y)!=EOF && !(c == 0 && x == 0 && y == 0)){
        if(c == 1){// set friends
            if(find(x) == find(y+n)){ // enemies check
                printf("-1\n");
            }
            else{
                uni(x,y);
                uni(x+n,y+n);
            }
        }
        else if(c == 2){// set enemies
            if(find(x) == find(y)){// friends check
                printf("-1\n");
            }
            else{
                uni(x,y+n);
                uni(x+n,y);
            }
        }
        else if(c == 3){// are friends
            if(find(x) == find(y)){// friends check
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
        else if(c == 4){// are enemies
            if(find(x) == find(y+n)){ // enemies check
                printf("1\n");
            }
            else{
                printf("0\n");
            }
        }
    }
    return 0;
}

