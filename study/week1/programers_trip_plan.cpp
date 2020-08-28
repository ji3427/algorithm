#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <string.h>

using namespace std;

vector<string> answer;

bool comp(vector<string> A, vector<string> B){
    if(A[0].compare(B[0]) == 0) return A[1].compare(B[1]) < 0;
    return A[0].compare(B[0]) < 0;
}

int dfs(vector<string> plan,vector<vector<string>> tickets,bool check[]){
	if(plan.size() == tickets.size() + 1){
		answer = plan;
		return 1;
	}
	for(int i = 0 ; i <tickets.size() ; i++){
		if(check[i] == false && plan.back() == tickets[i][0]){
			plan.push_back(tickets[i][1]);
			check[i] = true;
			if(dfs(plan,tickets,check) == 1) break;
			check[i] = false;
			plan.pop_back();
		}
	}
	return 0;
}

vector<string> solution(vector<vector<string>> tickets) {
    sort(tickets.begin(),tickets.end(),comp);
	vector<string> plan = {"ICN"};
	bool check[10000];
	memset(check,0,sizeof(check));
	dfs(plan,tickets,check);
    return answer;
}

int main(void){
	vector<vector<string>> t = {{"ICN", "SFO"}, {"ICN", "ATL"}, {"SFO", "ATL"}, {"ATL", "ICN"}, {"ATL", "SFO"}};
	for(string str : solution(t)){
		cout<<str<<" | ";
	}
}
