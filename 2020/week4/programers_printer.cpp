#include <string>
#include <vector>
#include <iostream>
#include <string.h>
using namespace std;

int getMax(vector<int> q,bool * visit,int cur){
	int maxN = -1;
	int ans;
	for(int i = 0 ; i < q.size() ; i++){
		cur %= q.size();
		if(!visit[cur] && maxN < q[cur]) {maxN = q[cur]; ans = cur;}
		cur++;
	}
	return ans;
}

int solution(vector<int> priorities, int location) {
    int answer = 0;
    bool visit[100];
    int order[100];
    int cur = 0;
    memset(visit,0,sizeof(visit));
    for(int i = 0 ; i < priorities.size() ; i++){
		order[i] = getMax(priorities,visit,cur);
		cur = order[i];
		visit[order[i]] = true;
	}
	for(int i = 0 ; i < priorities.size() ; i++){
		if(order[i] == location) {answer = i+1; break;}
	}
    return answer;
}

int main(void){
	vector<int> p{1,1,9,1,1,1};
	cout<<solution(p,0);
}
