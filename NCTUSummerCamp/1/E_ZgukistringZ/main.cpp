#include <iostream>
#include <string.h>
#include <stdio.h>

using namespace std;

char a[100001];
char ori_b[100001];
char ori_c[100001];
int alphabet_count_a[26];
int alphabet_count_b[26];
int alphabet_count_c[26];
int alphabet_count_rest[26];

int main()
{
    //input & init
    scanf("%s%s%s",a,ori_b,ori_c);
    for(int i=0;i<26;++i){
        alphabet_count_a[i] = 0;
        alphabet_count_b[i] = 0;
        alphabet_count_c[i] = 0;
    }

    char *b = ori_b;
    char *c = ori_c;
    int len_a = strlen(a);
    int len_b = strlen(ori_b);
    int len_c = strlen(ori_c);
    int max_number_b = 9999;
    int max_number_bc = -1;
    pair<int,int> result(-1,-1); //number of (b,c)

    //make len_b > len_c
    if(len_c > len_b){
        swap(b,c);
        swap(len_b,len_c);
    }

    //count for alphabet
    for(int i=0;i<len_a;++i){
        alphabet_count_a[ a[i]-'a' ]++;
    }
    for(int i=0;i<len_b;++i){
        alphabet_count_b[ b[i]-'a' ]++;
    }
    for(int i=0;i<len_c;++i){
        alphabet_count_c[ c[i]-'a' ]++;
    }

    //calculate tha maximum number of b in a
    for(int i=0;i<26;++i){
        if(alphabet_count_b[i] == 0)
            continue;
        if(alphabet_count_a[i] / alphabet_count_b[i] < max_number_b)
            max_number_b = alphabet_count_a[i] / alphabet_count_b[i];
    }

    //enumerate number of b
    for(int i=0;i<=max_number_b;++i){//must add a '=' to it
        int alphabet_count_tmp[26];
        int max_number_c = 9999;

        //calculate the rest of a
        for(int j=0;j<26;++j){
            alphabet_count_tmp[j] = alphabet_count_a[j] - alphabet_count_b[j]*i;
        }
        //calculate the maximum number of c in the rest
        for(int j=0;j<26;++j){
            if(alphabet_count_c[j] == 0)
                continue;
            if(alphabet_count_tmp[j] / alphabet_count_c[j] < max_number_c)
                max_number_c = alphabet_count_tmp[j] / alphabet_count_c[j];
        }
        if( i + max_number_c > result.first + result.second){
            result.first = i ;
            result.second = max_number_c;
            for(int j=0;j<26;++j){
                alphabet_count_rest[j] = alphabet_count_tmp[j] - alphabet_count_c[j]*max_number_c;
            }
        }
    }

    //output the result
    for(int i=0;i<result.first;++i){
        printf("%s",b);
    }
    for(int i=0;i<result.second;++i){
        printf("%s",c);
    }
    for(int i=0;i<26;++i){
        for(int j=0;j<alphabet_count_rest[i];++j){
            printf("%c",i+'a');
        }
    }
    printf("\n");

    return 0;
}

