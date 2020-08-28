#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <set>
#include <deque>

using namespace std;

string org;
int n;
int maxN;

set<int> s;
void dfs(int index,int cur){
	if(cur == n){
		int ans = stoi(org);
		if(maxN < ans) maxN = ans;
		return;
	}
	for(int i = index ; i < org.length()-1 ; i++){
		for(int j = i + 1; j < org.length() ; j++){
			if(org[i] <= org[j]){
				char temp = org[i];
				org[i] = org[j];
				org[j] = temp;
				dfs(cur+1);
				temp = org[i];
				org[i] = org[j];
				org[j] = temp;				
			}
		}
	}
}

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		cin>>org>>n;
		maxN = -1;
		dfs(0,0);
		cout<<'#'<<t+1<<' '<<maxN<<endl;
	}
}
