#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> answer;
vector<int> nums;
int N,M;


void dfs(int cnt,int start){
	if(cnt == M){
		for(auto i : answer) cout<<i<<" ";
		cout<<"\n";
		return;
	}
	for(int i = start ; i < nums.size() ;i++){
		answer.push_back(nums[i]);
		dfs(cnt+1,i);
		answer.pop_back();
	}
	
}


int main(void){
	cin>>N>>M;
	for(int i = 0 ; i < N ; i++){
		int t;
		cin>>t;
		nums.push_back(t);
	}
	sort(nums.begin(),nums.end());
	dfs(0,0);
}
