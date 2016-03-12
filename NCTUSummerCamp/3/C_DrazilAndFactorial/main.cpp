#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <vector>
#include <algorithm>

using namespace std;

int a[20];

int main()
{
    int n=0;
    while(scanf("%d",&n)!=EOF){
        //input
        char input_a[50];
        scanf("%s",input_a);
        for(int i=0;i<n;++i){
            a[i] = input_a[i]-'0';
        }

        vector<int> result;
        for(int i=0;i<n;++i){
            if(a[i] == 0 || a[i] == 1)
                continue;
            else if(a[i] == 2 || a[i] == 3 || a[i] == 5 || a[i] == 7 ){
                result.push_back(a[i]);
            }
            else if(a[i] == 4){
                result.push_back(3);
                result.push_back(2);
                result.push_back(2);
            }
            else if(a[i] == 6){
                result.push_back(5);
                result.push_back(3);
            }
            else if(a[i] == 8){
                result.push_back(7);
                result.push_back(2);
                result.push_back(2);
                result.push_back(2);
            }
            else if(a[i] == 9){
                result.push_back(7);
                result.push_back(3);
                result.push_back(3);
                result.push_back(2);
            }
        }
        sort(result.begin(),result.end());
        for(int i=0;i<result.size();++i){
            printf("%d",result[result.size()-i-1]);
        }
        printf("\n");
    }
    return 0;
}

