#include <iostream>
#include <vector>
#include <string>
#include <string.h>
using namespace std;

struct node{
	bool end;
	node* alph[26];
};

int ans;
node* root[10001];

void dfs(int index,string q,node * cur){
	if(cur == NULL) return;
	if(index == q.length()){
		if(cur->end == true) ans++;
		return;
	}
	if(q[index] == '?'){
		for(int i = 0 ; i < 26 ; i++){
			if(cur->alph[i]) dfs(index+1,q,cur->alph[i]);
		}
	}
	else{
		dfs(index+1,q,cur->alph[q[index] - 'a']);
	}
}

vector<int> solution(vector<string> words, vector<string> queries) {
    vector<int> answer;
    for(int i = 0 ; i < words.size() ; i++){
		int size = words[i].length();
		root[size] = (node*)malloc(sizeof(node));
		memset(root[size],0,sizeof(node));
		node * cur = root[size];
		for(int j = 0 ; j < words[i].length() ; j++){
			if(!cur->alph[words[i][j] - 'a']){
				cur->alph[words[i][j] - 'a'] = (node*)malloc(sizeof(node));
				memset(cur->alph[words[i][j] - 'a'],0,sizeof(node));
				cur->alph[words[i][j] - 'a'] -> end = false;
			}
			cur = cur->alph[words[i][j] - 'a'];
		}
		cur->end = true;
	}
    for(int i = 0 ; i < queries.size() ; i++){
		string query = queries[i];
		ans = 0;
		dfs(0,query,&root);
		answer.push_back(ans);
	}
    return answer;
}


int main(void){
	vector<string> s = {"frodo", "front", "frost", "frozen", "frame", "kakao"};
	vector<string> q = {"fro??", "????o", "fr???", "fro???", "pro?"};
	vector<int> ans = solution(s,q);
	for(auto i : ans) cout<<i<<" ";
	cout<<endl;
}
