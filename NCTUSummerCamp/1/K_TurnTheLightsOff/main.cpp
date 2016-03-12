#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

bool ori_map[12][12];
bool map[12][12];

void cpy2map(){
    for(int i=0;i<12;++i)
        for(int j=0;j<12;++j){
            map[i][j] = ori_map[i][j];
        }
}

bool& switch_bool(bool &input){
    input = !input;
    return input;
}

int click_on(int x,int y){
    switch_bool(map[x][y]);
    switch_bool(map[x-1][y]);
    switch_bool(map[x][y-1]);
    switch_bool(map[x+1][y]);
    switch_bool(map[x][y+1]);
    return 1;
}

int cal4step(void){
    int result = 0;
    for(int i=2;i<=10;++i){
        for(int j=1;j<=10;++j){
            if(map[i-1][j] == true){
                result += click_on(i,j);
            }
        }
    }
    for(int j=1;j<=10;++j){
        if(map[10][j] == true)
            return 9999;
    }
    return result;
}

int main()
{
    char name[100];
    while( scanf("%s",name)!=EOF ){
        if(string(name) == "end")
            break;
        //init & input
        for(int i=0;i<12;++i){
            for(int j=0;j<12;++j){
                ori_map[i][j] = false;
            }
        }
        for(int i=1;i<=10;++i){
            char buffer[20];
            scanf("%s",buffer);
            for(int j=1;j<=10;++j){
                if(buffer[j-1] == 'O'){
                    ori_map[i][j] = true;
                }
            }
        }
        //enumerate the first line
        int min = 9999;
        for(int chosen_counter = 0;chosen_counter<(1<<10);++chosen_counter){
            //init
            cpy2map();
            int result = 0;
            int mask = 1;
            for(int i=1;i<=10;++i){
                if((chosen_counter & mask) > 0)
                    result += click_on(1,i);
                mask <<= 1;
            }
            result += cal4step();
            if(result < min){
                min = result;
            }
        }
        if(min > 100)
            min = -1;
        printf("%s %d\n",name,min);
    }
    return 0;
}

