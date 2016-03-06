#include <iostream>
#include <cstdio>
#include <vector>
#include <stack>

using namespace std;

bool connection[101][101];
bool visited[101];

int n =0;
int number_visited = 0;
void dfs(int now){
    for(int i=1;i<=n;++i){
        if(connection[now][i] == true){
            if(visited[i] == true)
                continue;
            number_visited++;
            visited[i] = true;
            dfs(i);
        }
    }
}

int main()
{
    while(scanf("%d",&n) != EOF && n != 0){
        //init
        for(int i=0;i<101;++i){
            for(int j=0;j<101;++j){
                connection[i][j] = false;
            }
        }
        //input graph
        while(1){
            int index_start = 0;
            int index_buffer = 0;
            scanf("%d",&index_start);
            if(index_start == 0)
                break;
            while(scanf("%d",&index_buffer)!=EOF && index_buffer != 0){
                connection[index_start][index_buffer] = true;
            }
        }
        //input request
        int m = 0;
        scanf("%d",&m);
        for(int k=0;k<m;++k){
            //input
            int target_index = 0;
            scanf("%d",&target_index);
            //compute
            //init
            number_visited = 0;
            for(int i=0;i<=n;++i)
                visited[i] = false;
            dfs(target_index);
            printf("%d",n - number_visited);
            for(int i=1;i<=n;++i){
                if(visited[i] == false)
                    printf(" %d",i);
            }
            printf("\n");
        }


    }
    return 0;
}

