#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <set>
using namespace std;

vector<set<int>> ans;
void dfs(vector<vector<int>> list,int cur,bool visited[8]){
	if(cur == list.size()){
		set<int> st;
		int i = 0;
		for(i = 0 ; i < 8 ; i++){
			if(visited[i] == true ) st.insert(i);
		}
		for(i = 0 ; i < ans.size() ; i++){
			if(ans[i] == st) break;
		}
		if(i == ans.size()) ans.push_back(st);
		return;
	}
		for(int j = 0 ; j < list[cur].size() ; j++){
			if(!visited[list[cur][j]]) {
				visited[list[cur][j]] = true;
				dfs(list,cur+1,visited);
				visited[list[cur][j]] = false;
			}
		}
}



int solution(vector<string> user_id, vector<string> banned_id) {
    int answer = 0;
    vector<vector<int>> list;
    vector<int> dummy;
    bool visited[8];
    memset(visited,0,sizeof(visited));
    for(int i = 0 ; i < banned_id.size() ; i++){
		list.push_back(dummy);
		for(int j = 0 ; j < user_id.size() ; j++){
			if(banned_id[i].length() != user_id[j].length()) continue;
			else{
				int k = 0;
				for(; k < banned_id[i].length() ; k++){
					if(banned_id[i][k] == '*') continue;
					else if(banned_id[i][k] != user_id[j][k]) break;
				}
				if(k == banned_id[i].length()) list.back().push_back(j);
			}
		}
	}
	dfs(list,0,visited);
	answer = ans.size();
    return answer;
}



int main(void){
	vector<string> v = {"frodo", "fradi", "crodo", "abc123", "frodoc"};
	vector<string> b = {"fr*d*", "*rodo", "******", "******"};
	cout<<solution(v,b);
}
