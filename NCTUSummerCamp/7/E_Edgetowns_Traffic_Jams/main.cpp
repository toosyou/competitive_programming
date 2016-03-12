#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <sstream>
#include <string>

using namespace std;

int A = 0;
int B = 0;
int N = 0;
bool connect_graph[102][102];
bool connect_graph_modified[102][102];
int cost[102][102];
int cost_modified[102][102];

void floyd_warshall(void){
    //init
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cost[i][j] = (connect_graph[i][j] == true ? 1 : 9999);
        }
    }
    for(int i=1;i<=N;++i){
        cost[i][i] = 0;
    }

    //algorithm
    for(int k=1;k<=N;++k){//middle point
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                //relaxing
                cost[i][j] = min(cost[i][j] , cost[i][k] + cost[k][j]);
            }
        }
    }

    //done
    return;
}

void floyd_warshall_modified(void){
    //init
    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            cost_modified[i][j] = (connect_graph_modified[i][j] == true ? 1 : 9999);
        }
    }
    for(int i=1;i<=N;++i){
        cost_modified[i][i] = 0;
    }

    //algorithm
    for(int k=1;k<=N;++k){//middle point
        for(int i=1;i<=N;++i){
            for(int j=1;j<=N;++j){
                //relaxing
                cost_modified[i][j] = min(cost_modified[i][j] , cost_modified[i][k] + cost_modified[k][j]);
            }
        }
    }

    //done
    return;
}

bool king_is_happy(void){

    for(int i=1;i<=N;++i){
        for(int j=1;j<=N;++j){
            if(cost_modified[i][j] > A * cost[i][j] + B)
                return false;
        }
    }
    return true;
}


int main(){

    while(scanf("%d",&N) != EOF && N != 0){
        char buffer[100000];
        cin.getline(buffer,100000);

        //init
        for(int i=0;i<=N;++i){
            for(int j=0;j<=N;++j){
                connect_graph[i][j] = false;
                connect_graph_modified[i][j] = false;
            }
        }

        //input
        for(int i=0;i<N;++i){
            int index_start = 0;
            int index_buffer = 0;
            cin.getline(buffer,100000);
            stringstream iss(buffer);
            iss >>index_start;
            while(iss >> index_buffer){
                connect_graph[index_start][index_buffer] = true;
                //connect_graph[index_buffer][index_start] = true;
                //fuck that, this graph is not bidirectional as it states = ="
            }
        }
        for(int i=0;i<N;++i){
            int index_start = 0;
            int index_buffer = 0;
            cin.getline(buffer,100000);
            stringstream iss(buffer);
            iss >> index_start;
            while(iss >> index_buffer){
                connect_graph_modified[index_start][index_buffer] = true;
            }
        }
        scanf("%d%d",&A,&B);

        //compute
        floyd_warshall();
        floyd_warshall_modified();
        //check
        if(king_is_happy())
            printf("Yes\n");
        else
            printf("No\n");

    }
    return 0;
}

