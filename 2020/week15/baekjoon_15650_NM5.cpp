#include <iostream>
#include <string>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <algorithm>

using namespace std;

vector<int> nums;
bool visit[10];
vector<int> ans;
void dfs(int size){
	if(ans.size() == size){
		for(auto i : ans) cout<<i<<" ";
		printf("\n");
		return;
	}
	for(int i =  0 ; i < nums.size() ; i++){
		if(visit[i] == false){
			visit[i] = true;
			ans.push_back(nums[i]);
			dfs(size);
			ans.pop_back();
			visit[i] = false;
		}
	}
}


int main(void){
	int size,num;
	cin>>size>>num;

	for(int i = 0 ; i < size ; i++){
		int t;
		cin>>t;
		nums.push_back(t);
	}
	memset(visit,0,sizeof(visit));
	sort(nums.begin(),nums.end());
	dfs(num);
}
