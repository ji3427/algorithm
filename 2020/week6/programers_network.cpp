#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

bool nodes[200];

int dfs(int node,vector<vector<int>> computers){
	int n = 0;
	for(; n < computers.size() ; n++){
		if(computers[node][n] == 1 && nodes[n] == false){
			nodes[n] = true;
			dfs(n,computers);
		}
	}
	return 1;
}

int solution(int n, vector<vector<int>> computers) {
    int answer = 0;
    memset(nodes,0,sizeof(nodes));
    for(int i = 0 ; i < n ; i++){
		if(nodes[i] == false){
			answer++;
			dfs(i,computers);
		}
	}
    return answer;
}


int main(void)
{
	vector<vector<int>> c {{1,0,0,1},{0,1,1,0},{0,1,1,0},{1,1,0,1}};
	cout<<solution(4,c);
	//vector<vector<int>> c2 {{1,1,0},{1,1,1},{0,1,1}};
	//cout<<solution(3,c2);
	
}
