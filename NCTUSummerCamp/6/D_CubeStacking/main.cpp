#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

struct node{
    int index_father;
    int son;
    int deep;
};

node cubes[30001];

int find(int index){
    if(cubes[index].index_father == index)
        return index;
    int original_father = cubes[index].index_father;
    cubes[index].index_father = find( cubes[index].index_father );
    cubes[index].deep += cubes[original_father].deep;
    return cubes[index].index_father;
}

void uni(int index_high,int index_low){
    int father_high = find(index_high);
    int father_low = find(index_low);
    cubes[father_low].index_father = father_high;
    cubes[father_low].deep += cubes[father_high].son + 1;
    cubes[father_high].son += cubes[father_low].son + 1;
}

int main()
{
    int P = 0;
    scanf("%d",&P);
    //init
    for(int i=0;i<30001;++i){
        cubes[i].index_father = i;
        cubes[i].son = 0;
        cubes[i].deep = 0;
    }
    for(int k=0;k<P;++k){
        char command = 0;
        int x = 0;
        int y = 0;
        scanf("%*c%c",&command);
        if(command == 'C'){
            scanf("%d",&x);
            printf("%d\n",cubes[find(x)].son - cubes[x].deep);
        }
        else{// M
            scanf("%d%d",&x,&y);
            uni(x,y);
        }

    }
    return 0;
}

