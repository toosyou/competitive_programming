#include <iostream>
#include <stdio.h>

using namespace std;

int f91(int input){
    /*int number_f91 = 1;
    while(number_f91 > 0){
        if(input >= 101){
            number_f91--;
            input = input - 10;
        }
        else if(input <= 100){
            number_f91++;
            input = input + 11;
        }
    }
    return input;*/
    return input <= 100 ? 91 : input - 10;
}

int main(){
    int input = 0;
    while(scanf("%d",&input) != EOF){
        if(input == 0)
            break;
        printf("f91(%d) = %d\n",input,f91(input));
    }
    return 0;
}

