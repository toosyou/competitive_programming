#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <utility>
#include <queue>

using namespace std;

int M = 0;
int N = 0;

bool enemies[102][102];
int trips[102][102];
pair<int,int> start_point;
pair<int,int> end_point;

bool point_is_legal(int x, int y){
    if(x >= 0 && x < M && y >= 0 && y < N){
        return true;
    }
    return false;
}

int bfs(void){
    bool find_end = false;
    queue< pair<int,int> >next;
    //init with start_point
    next.push(start_point);
    trips[start_point.first][start_point.second] = 0;
    while(!next.empty() && find_end == false){
        pair<int,int> this_point = next.front();
        next.pop();
        for(int i=-1;i<=1;++i){
            for(int j=-1;j<=1;++j){
                if(point_is_legal(this_point.first+i,this_point.second+j)){
                    pair<int,int> next_step(this_point.first+i,this_point.second+j);
                    if( next_step == end_point){
                        find_end = true;
                        trips[next_step.first][next_step.second] =  min(trips[next_step.first][next_step.second],trips[this_point.first][this_point.second]+1);
                    }
                    else if( enemies[next_step.first][next_step.second] == false &&
                            trips[next_step.first][next_step.second] > trips[this_point.first][this_point.second]+1 ){
                        next.push(next_step);
                        trips[next_step.first][next_step.second] = trips[this_point.first][this_point.second]+1;
                    }
                }
            }
        }
    }
    return trips[end_point.first][end_point.second];
}

int main(void){
    int T = 0;
    scanf("%d",&T);
    for(int k=0;k<T;++k){
        scanf("%d%d",&M,&N);
        //init
        for(int i=0;i<M;++i){
            for(int j=0;j<N;++j){
                enemies[i][j] = false;
                trips[i][j] = 9999;
            }
        }
        //input
        for(int i=0;i<M;++i){
            char buffer[102];
            scanf("%s",buffer);
            for(int j=0;j<N;++j){
                if(buffer[j] == 'A'){
                    start_point.first = i;
                    start_point.second = j;
                }
                else if(buffer[j] == 'B'){
                    end_point.first = i;
                    end_point.second = j;
                }
                else if(buffer[j] == 'Z'){
                    enemies[i][j] = true;
                    //make one move
                    for(int m=-2;m<=2;++m){
                        for(int n=-2;n<=2;++n){
                            if(point_is_legal(i+m,j+n)){
                                if(abs(m) + abs(n) == 3)
                                    enemies[ i+m ][ j+n ] = true;
                            }
                        }
                    }
                }
            }
        }

        //bfs
        int ans = bfs();
        if(ans == 9999)
            printf("King Peter, you can't go now!\n");
        else
            printf("Minimal possible length of a trip is %d\n",ans);

    }
    return 0;
}
