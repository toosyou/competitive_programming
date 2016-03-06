#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <time.h>

using namespace std;

int main()
{
    int N = 0;
    bool first_input = true;
    while(scanf("%d",&N) != EOF){
        if(N == 0)
            break;
        if(first_input == false){
            printf("\n");
        }
        bool no_solution = true;
        for(int first=10234;first<=98765;++first){

            bool selected[10];
            bool macon = false;
            int second = 0;
            int succeed_count = 0;

            for(int i=0;i<10;++i)//init
                selected[i] = false;

            if(first % N != 0)//if first cannot be divised by N,continue;
                continue;

            //check if first has same digits
            for(int i=0,tmp=first;i<5;++i){
                int single_digit = tmp%10;
                if(selected[single_digit] == true){
                    macon = true;
                    break;
                }
                else{
                    selected[single_digit] = true;
                }
                tmp/=10;
            }
            if(macon == true)
                continue;

            second = first / N; // get second number
            //check if it fits
            for(int i=0,tmp=second;i<5;++i){
                selected[ tmp%10 ] = true;
                tmp /= 10;
            }
            for(int i=0;i<10;++i){
                if(selected[i] == true)
                    succeed_count ++;
            }
            if(succeed_count == 10){
                if(first < 10000)
                    continue;
                printf("%d / ",first);
                if(second < 10000)
                    printf("0");
                printf("%d = %d\n",second,N);
                no_solution = false;
            }
        }
        if(no_solution){
            printf("There are no solutions for %d.\n",N);
        }
        first_input = false;
    }
    return 0;
}
