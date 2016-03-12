#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <sstream>
#include <vector>

using namespace std;

int n = 0;
int m = 0;

int graph[102][102];
int min_cost[102];

struct edge{
    int from;
    int to;
    int value;
};

vector<edge> edges;

bool bellman_ford(){
    //init
    for(int i=0;i<n+1;++i){
        min_cost[i] = 0;
    }

    //single source
    for(int k=0;k<n+1;++k){
        for(int i=0;i<edges.size();++i){
            edge &this_edge = edges[i];
            if( min_cost[ this_edge.to ] > min_cost[this_edge.from] + this_edge.value ){
                min_cost[ this_edge.to ] = min_cost[this_edge.from] + this_edge.value;
                if(k == n)
                    return true;
            }
        }
    }
    //done
    return false;
}

int main()
{
    while(scanf("%d",&n) != EOF && n != 0 && scanf("%d",&m) != EOF){
        //init
        edges.clear();

        //input
        for(int i=0;i<m;++i){
            int index_start = 0;
            int size = 0;
            char operation[20] = {0};
            int weight = 0;
            scanf("%d%d%s%d",&index_start,&size,operation,&weight);
            if(operation[0] == 'g'){//greater than
                edge tmp;
                tmp.from = index_start+size;
                tmp.to = index_start - 1;
                tmp.value = -weight - 1;
                edges.push_back(tmp);
            }
            else{//less than
                edge tmp;
                tmp.from = index_start - 1;
                tmp.to = index_start+size;
                tmp.value = weight - 1;
                edges.push_back(tmp);
            }
        }

        //compute
        if( bellman_ford() )
            printf("successful conspiracy\n");
        else
            printf("lamentable kingdom\n");
    }
    return 0;
}

