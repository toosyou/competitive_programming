#include <iostream>
#include <stdio.h>

using namespace std;

char input[100001];

int find_AB(int first){
    if(first == -1)
        return -1;
    for(int i=first;input[i]!='\0';++i){
        if(input[i] == 'A' && input[i+1] == 'B'){
            return i+2;
        }
    }
    return -1;
}

int find_BA(int first){
    if(first == -1)
        return -1;
    for(int i=first;input[i]!='\0';++i){
        if(input[i] == 'B' && input[i+1] == 'A'){
            return i+2;
        }
    }
    return -1;
}

int main()
{
    //input
    scanf("%s",input);

    if(find_BA(find_AB(0)) != -1 || find_AB(find_BA(0)) != -1){
        printf("YES\n");
    }
    else
        printf("NO\n");

    return 0;
}

