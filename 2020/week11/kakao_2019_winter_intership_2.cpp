#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
using namespace std;

map<int,int> m;


bool compare(pair<int,int> A,pair<int,int> B){
	return A.second > B.second;
}
vector<int> solution(string s) {
    vector<int> answer;
    int start,end;
    string sub,ss;
    for(int i = 1 ; i <s.length() - 1 ; i++){
		if(s[i] == '{') start = i;
		else if(s[i] == '}'){
			end = i;
			sub = s.substr(start+1,end - start-1);
			stringstream f(sub);
			while(getline(f,ss,',')){
				int num = atoi(ss.c_str());
				if(m.find(num) == m.end()) m.insert(make_pair(num,1));
				else m[num]++;
			}
		}
	}
	vector<pair<int,int>> sorted;
    map<int,int>::iterator it = m.begin();
    for(;it != m.end() ; it++){
		sorted.push_back(make_pair(it->first,it->second));
	}
	sort(sorted.begin(),sorted.end(),compare);
	for(int i = 0 ; i < sorted.size() ; i++){
		answer.push_back(sorted[i].first);
	}
    return answer;
}


int main(void){
	string a = "{{2},{2,1},{2,1,3},{2,1,3,4}}";
	vector<int> v = solution(a);
	for(auto i : v){
		cout<<i<<" ";
	}
	cout<<endl;
}
