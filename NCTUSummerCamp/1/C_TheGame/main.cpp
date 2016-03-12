#include <iostream>
#include <stdio.h>

using namespace std;

int board[21][21];
int direction[4][2]={{1,0},{0,1},{-1,1},{1,1}};

bool check(int x,int y){
    int this_color = board[x][y];
    if(this_color == 0)
        return false;

    for(int i=0;i<4;++i){//check four direction
        bool this_direction_good = true;
        int move_x = direction[i][0];
        int move_y = direction[i][1];

        for(int j=0;j<4;++j){//check four moar stones
            int now_x = x + move_x*(j+1);
            int now_y = y + move_y*(j+1);

            if( now_x < 1 || now_x > 19  || now_y < 1 || now_y > 19){
                this_direction_good = false;
                break;
            }
            if( board[now_x][now_y] != this_color){
                this_direction_good = false;
                break;
            }
        }
        if(this_direction_good &&
                board[x-move_x][y-move_y] != this_color &&
                board[x+move_x*5][y+move_y*5] != this_color){
            printf("%d\n%d %d\n",this_color,x,y);
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
        bool no_one_wins = true;

        //init & input
        for(int i=0;i<21;++i)
            for(int j=0;j<21;++j)
                board[i][j] = 0;
        for(int i=1;i<=19;++i)
            for(int j=1;j<=19;++j)
                scanf("%d",&board[i][j]);

        for(int i=1;i<=19 && no_one_wins ;++i){
            for(int j=1;j<=19 && no_one_wins ;++j){
                if(check(i,j) == true)
                    no_one_wins = false;
            }
        }
        if(no_one_wins){
            printf("0\n");
        }
    }
    return 0;
}

