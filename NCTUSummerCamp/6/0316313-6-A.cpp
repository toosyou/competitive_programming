#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <stack>
#include <vector>

using namespace std;

int N = 0;
int M = 0;

bool friend_map[30001][30001]; // true for friends
vector<int> friend_list[30001];
bool friended[30001];


int dfs(int index){
    int ans = 1;
    stack<int> st;
    friended[index] = true;
    st.push(index);
    while(!st.empty()){
        int now = st.top();
        st.pop();
        for(int j=0;j<friend_list[now].size();++j){
            int index_friend = friend_list[now][j];
            if(friended[index_friend] == false){
                friended[index_friend] = true;
                st.push(index_friend);
                ans++;
            }
        }
    }
    return ans;
}

int main()
{
    int T = 0;
    scanf("%d",&T);
    for(int k=0;k<T;++k){
        scanf("%d%d",&N,&M);
        //init
        for(int i=0;i<=N;++i)
            friend_list[i].clear();
        for(int i=0;i<=N;++i)
            friended[i] = false;
        //input
        for(int i=0;i<M;++i){
            int a = 0;
            int b = 0;
            scanf("%d%d",&a,&b);
            friend_list[a].push_back(b);
            friend_list[b].push_back(a);
        }//done

        //calculate for the max
        int max = -1;
        for(int i=1;i<=N;++i){
            if(friended[i] == true)
                continue;
            int dfs_result = dfs(i);
            if(max < dfs_result)
                max = dfs_result;
        }
        printf("%d\n",max);
    }
    return 0;
}
