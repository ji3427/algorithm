#include <iostream>
#include <string>
#include <vector>

using namespace std;

bool judge(string w){
	vector<int> s;
	for(int i = 0 ; i < w.length() ;i++){
		if(w[i] == '(') s.push_back(i);
		else if(w[i] == ')'){
			if(s.size() == 0) return false;
			s.pop_back();
		}
	}
	return true;
}


string solution(string p){
	string ans ="";
	string u,v;
	v = p;
	if(p.length() == 0) return "";
	int openB = 0;
	int closeB = 0;
	int cur = 0;
	while(1){
		if(v[cur] == '(') openB++;
		else if(v[cur] == ')') closeB++;
		cur++;
		if(openB == closeB) break;
	}
	u = v.substr(0,cur);
	if(cur +1 >= p.length()) v = "";
	else v = v.substr(cur);
//	cout<<"u : "<<u<<" v : "<<v<<endl;
	if(judge(u)) ans = u + solution(v);
	else{
		ans += "(";
		ans += solution(v);
		ans += ")";
		for(int i = 1 ; i < u.length() - 1 ;i++){
			if(u[i] == '(') ans.push_back(')');
			else if(u[i] == ')') ans.push_back('(');
		}
	}
	return ans;
}

int main(void){
	string a = "(()())()";
	string b = ")(";
	string c = "()))((()";
	cout<<solution(a)<<endl;
	cout<<solution(b)<<endl;
	cout<<solution(c)<<endl;
}
