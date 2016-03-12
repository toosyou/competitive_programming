#include <iostream>
#include <queue>
#include <set>
#include <cstdio>

using namespace std;

int main(void){

	multiset<int> queue;
	int input_command = 0;

	while( scanf("%d",&input_command) != EOF ){
		if( input_command == -2 ){
			if(queue.size() > 0){
				printf("%d ", *(--queue.end()) );
				queue.erase( --queue.end() );
			}
		}else if( input_command == -1 ){
			if(queue.size() > 0){
				printf("%d ", *queue.begin() );
				queue.erase( queue.begin() );
			}
		}else if( input_command == 0 ){
			queue.clear();
		}else{
			queue.insert( input_command );
		}
	}

	return 0;
}