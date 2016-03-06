#include <iostream>
#include <stdio.h>
#include <stdlib.h>

using namespace std;

int grid[9][9];
int n ;

bool no_conflict(int n){
    //check small
    bool select[10];
    for(int i=0;i<n;++i){
        for(int j=0;j<n;++j){
            int leftest = i*n;
            int uppest = j*n;
            for(int ii=0;ii<10;++ii){//init
                select[ii] = false;
            }
            for(int k=0;k<n;++k){
                for(int m=0;m<n;++m){

                    if(grid[leftest+k][uppest+m] != 0 && select[ grid[leftest+k][uppest+m] ] == true)
                        return false;
                    select[ grid[leftest+k][uppest+m] ] = true;
                }
            }
        }
    }
    //check row
    for(int i=0;i<n*n;++i){
        for(int ii=0;ii<10;++ii){//init
            select[ii] = false;
        }
        for(int j=0;j<n*n;++j){
            if(grid[i][j] != 0 && select[grid[i][j] ] == true)
                return false;
            select[ grid[i][j] ] = true;
        }
    }
    //check column
    for(int j=0;j<n*n;++j){
        for(int ii=0;ii<10;++ii){//init
            select[ii] = false;
        }
        for(int i=0;i<n*n;++i){
            if(grid[i][j] != 0 && select[grid[i][j] ] == true)
                return false;
            select[ grid[i][j] ] = true;
        }
    }

    //all good
    return true;
}

int dfs(int x,int y){
    //find next zero
    bool find_zero = false;
    for(x=0;x<n*n;++x){
        for(y=0;y<n*n;++y){
            if(grid[x][y] == 0){
                find_zero = true;
                break;
            }
        }
        if(find_zero == true)
            break;
    }
    if( x == n*n && y == n*n && find_zero == false){//it's the end
        for(int i=0;i<n*n;++i){
            printf("%d",grid[i][0]);
            for(int j=1;j<n*n;++j){
                printf(" %d",grid[i][j]);
            }
            printf("\n");
        }
        return 1; // the end
    }

    for(int i=1;i<=9;++i){
        grid[x][y] = i;
        if(no_conflict(n) == true){
            if(dfs(x,y)==1)
                return 1;
        }
    }
    grid[x][y] = 0;
    return -1; // no result

}

int main()
{
    bool first = true;
    while(scanf("%d",&n)!=EOF){


        for(int i=0;i<n*n;++i){
            for(int j=0;j<n*n;++j){
                scanf("%d",&grid[i][j]);
            }
        }
        if(first == false)
            printf("\n");
        first = false;
        if(dfs(0,0) == -1){
            printf("NO SOLUTION\n");
        }

    }

    return 0;
}

