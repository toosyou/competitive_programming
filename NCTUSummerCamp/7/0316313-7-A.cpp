#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int R = 0;
int C = 0;
pair<int,int> start_point;
pair<int,int> end_point;

bool bombs[1002][1002];
int steps[1002][1002];

int bfs(void){
    bool find_end = false;
    //init with start_point
    queue< pair<int,int> > next;
    next.push(start_point);
    steps[start_point.first][start_point.second] = 0;
    //bfs
    while(!next.empty() && find_end == false){
        pair<int,int> this_point = next.front();
        next.pop();
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                if(abs(i) + abs(j) == 1){
                    if( bombs[this_point.first+i][this_point.second+j] == false &&
                            steps[this_point.first+i][this_point.second+j] > steps[this_point.first][this_point.second] + 1){
                        steps[this_point.first+i][this_point.second+j] = steps[this_point.first][this_point.second] + 1;
                        pair<int,int> next_point( this_point.first+i , this_point.second+j );
                        next.push(next_point);
                        if(next_point == end_point)
                            find_end = true;
                    }
                }
            }
        }
    }
    return steps[end_point.first][end_point.second];
}

int main()
{
    while(scanf("%d%d",&R,&C) != EOF && !(R == 0 && C == 0)){
        //init
        for(int i=0;i<=R+1;++i){
            for(int j=0;j<=C+1;++j){
                bombs[i][j] = false;
                steps[i][j] = 99999;
                if(i == 0 || j == 0 || i == R+1 || j == C+1){
                    bombs[i][j] = true;
                    steps[i][j] = 0;
                }
            }
        }

        //input
        int rows = 0;
        scanf("%d",&rows);
        for(int i=0;i<rows;++i){
            int index_row = 0;
            int number_bomb = 0;
            scanf("%d%d",&index_row,&number_bomb);
            for(int j=0;j<number_bomb;++j){
                int index_column = 0;
                scanf("%d",&index_column);
                bombs[index_row+1][index_column+1] = true;
            }
        }
        scanf("%d%d",&start_point.first,&start_point.second);
        start_point.first++; start_point.second++;
        scanf("%d%d",&end_point.first,&end_point.second);
        end_point.first++; end_point.second++;

        //compute
        printf("%d\n",bfs());
    }
    return 0;
}

