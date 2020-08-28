#include <iostream>
#include <stack>
#include <string>
#include <vector>
#include <utility>
using namespace std;

stack<int> st;
int main(void)
{
	vector<pair<int,int>> ans;
	string exp;
	cin>>exp;
	for(int i = 0 ; i < exp.length() ; i++){
		if(exp[i] == '(') st.push(i);
		else if(exp[i] == ')'){
			if(st.empty()){
				cout<<"not match"<<endl;
				return 0;
			}
			ans.push_back(make_pair(st.top(),i));
			st.pop();
		}
	}
	if(!st.empty()){
				cout<<"not match"<<endl;
				return 0;
	}
	for(auto i : ans){
		cout<<i.first<<" "<<i.second<<endl;
	}
}
