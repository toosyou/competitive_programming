#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>

using namespace std;

//int cost_graph[1002][1002];
struct cost_node{
    int index_b;
    int cost;
};

vector< vector<cost_node> > cost_list;
int min_cost[1002];
int number_systems = 0;
int number_holes = 0;

//adjacency matrix won't work
//However, adjacency list will

void bellman_ford(int source){
    //init
    for(int i=0;i<number_systems;++i){
        min_cost[i] = 999999999;
    }
    min_cost[source] = 0;
    //relaxing
    for(int i=0;i<number_systems-1;++i){
        for(int a=0;a<number_systems;++a){
            for(int j=0;j<cost_list[a].size();++j){
                int b = cost_list[a][j].index_b;
                min_cost[b] = min( min_cost[b] , min_cost[a] + cost_list[a][j].cost );
            }
        }
    }
    //done
    return;
}

bool has_neg_circle(void){
    for(int a=0;a<number_systems;++a){
        for(int j=0;j<cost_list[a].size();++j){
            int b = cost_list[a][j].index_b;
            if( min_cost[b] > min_cost[a] + cost_list[a][j].cost )
                return true;
        }
    }
    return false;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int k=0;k<T;++k){

        scanf("%d%d",&number_systems,&number_holes);
        //init
        cost_list.clear();
        cost_list.resize(number_systems);

        //input
        for(int i=0;i<number_holes;++i){
            int x = 0;
            int y = 0;
            int t = 0;
            scanf("%d%d%d",&x,&y,&t);
            cost_node tmp;
            tmp.index_b = y;
            tmp.cost = t;
            cost_list[x].push_back(tmp);
        }

        //bellman_ford
        bellman_ford(0);//from earth
        if(has_neg_circle())
            printf("possible\n");
        else
            printf("not possible\n");

    }
    return 0;
}
