#include <iostream>
#include <stack>
#include <vector>
#include <string.h>
#include <string>

using namespace std;
int main(void)
{
	vector<string> ans;
	bool visit[26];
	stack<int> st;
	string str;
	cin>>str;
	memset(visit,0,sizeof(visit));
	for(int i = 0 ; i < str.length();){
		cout<<str[i]<<"   "<<visit[i]<<endl;
		if(visit[i] == false){
			for(int j = 0 ; j <= str[i] - 'a' ; j++){
					if(visit[j] == false){
					st.push(j);
					ans.push_back("push");
					cout<<"push"<<endl;
					visit[st.top()] = true;
				}
			}
		}
		else{
				if(st.top() != str[i]-'a'){
					cout<<"impossible"<<endl;
					return 0;
				}
				else{
					ans.push_back("pop");
					cout<<"pop"<<endl;
					st.pop();
					i++;
				}
			}
			cout<<"================================="<<endl;
	}
	for(auto i : ans) cout<<i<<endl;
}
