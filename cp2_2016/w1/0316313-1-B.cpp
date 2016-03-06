#include <iostream>
#include <cstdio>

using namespace std;

long long int input[100001];
long long int sum[100001];

int main(void){

	int T = 0;

	scanf("%d",&T);

	for(int k=0;k<T;++k){

		int n = 0;
		int m = 0;
		scanf("%d%d",&n,&m);

		sum[0] = 0;
		for(int i=0;i<n;++i){
			scanf("%lld",&input[i]);
		}

		for(int i=1;i<=n;++i){
			sum[i] = sum[i-1] + input[i-1];
		}

		for(int i=0;i<m;++i){
			int from = 0;
			int to = 0;
			scanf("%d%d",&from,&to);
			printf("%lld\n",sum[to] - sum[from-1]);
		}


	}

	return 0;
}