#include <iostream>
#include <cstdlib>
#include <cstdio>

using namespace std;

int N = 0;
int source = 0;
int destiny = 0;

bool connect_graph[102][102];
int min_cost[102][102];

int floyd_warshall(void){
    //init
    for(int i=0;i<N;++i)
        for(int j=0;j<N;++j){
            if(connect_graph[i][j])
                min_cost[i][j] = 1;
            else
                min_cost[i][j] = 99999;
        }

    for(int i=0;i<N;++i)
        min_cost[i][i] = 0;

    //relaxing
    for(int i=0;i<N;++i)//i must be middle point, or it won't ac.
        for(int j=0;j<N;++j)
            for(int k=0;k<N;++k){
                min_cost[j][k] = min( min_cost[j][k] , min_cost[j][i] + min_cost[i][k] );
            }

    //find the last
    int last = 0;
    for(int i=0;i<N;++i){
        last = max( last , min_cost[source][i] + min_cost[i][destiny] );
    }
    return last;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int k=0;k<T;++k){

        int R = 0;
        scanf("%d",&N);
        scanf("%d",&R);

        //init
        for(int i=0;i<N;++i)
            for(int j=0;j<N;++j)
                connect_graph[i][j] = false;
        //input
        for(int i=0;i<R;++i){
            int u = 0;
            int v = 0;
            scanf("%d%d",&u,&v);
            connect_graph[u][v] = connect_graph[v][u] = true;
        }
        scanf("%d%d",&source,&destiny);

        //bellman_ford
        printf("Case %d: %d\n",k+1,floyd_warshall());
    }
    return 0;
}

