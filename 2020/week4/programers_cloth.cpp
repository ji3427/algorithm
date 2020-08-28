#include <iostream>
#include <vector>
#include <map>
#include <string>
using namespace std;


int solution(vector<vector<string>> clothes) {
    int answer = 1;
    map<string,int> m;
    for(int i = 0 ; i < clothes.size() ; i++){
		if(m.find(clothes[i][1]) != m.end()){
			(m.find(clothes[i][1])->second)++;
		}
		else{
			m.insert(make_pair(clothes[i][1],1));
		}
	}
	for(auto i = m.begin() ; i != m.end() ; i++){
		answer *= (i->second + 1);
	}
    return answer - 1;
}

int main(void){
	vector<string> c1;
	c1.push_back("yellow_hat");
	c1.push_back("headgear");
	vector<string> c2;
	c2.push_back("blue_hat");
	c2.push_back("headgear");
	vector<string> c3;
	c3.push_back("blue_sunglass");
	c3.push_back("eye");
	vector<vector<string>> cs;
	cs.push_back(c1);
	cs.push_back(c2);
	cs.push_back(c3);
	cout<<solution(cs);
}


