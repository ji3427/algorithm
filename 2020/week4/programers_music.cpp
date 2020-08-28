#include <string>
#include <vector>
#include <tuple>
#include <map>
#include <set>
#include <utility>
#include <iostream>
#include <algorithm>
using namespace std;



struct node{
	int index;
	int played;
};
map<string,vector<struct node>> m;

int comparepair(pair<string,int> p1, pair<string,int> p2){
	return p1.second > p2.second;
}
int compare(struct node n1, struct node n2){
	return n1.played > n2.played;
}
vector<int> solution(vector<string> genres, vector<int> plays) {
    vector<int> answer;
    map<string,int> type;
    vector<pair<string,int>> typeV;
	for(int i = 0 ; i < plays.size();i++){
		type[genres[i]] += plays[i];
		struct node n;
		n.index = i;
		n.played = plays[i];
		m[genres[i]].push_back(n);
	}
	for(auto i = type.begin() ; i != type.end() ; i++){
		typeV.push_back(make_pair(i->first,i->second));
	}
	sort(typeV.begin(),typeV.end(),comparepair);
	for(int i = 0 ; i < typeV.size() ; i++){
		sort(m[typeV[i].first].begin(),m[typeV[i].first].end(),compare);
		for(int j = 0 ; j < m[typeV[i].first].size() ; j++){
			if(j == 2) break;
			answer.push_back(m[typeV[i].first][j].index);
		}
	}
    return answer;
}


int main(void){
	vector<string> g{"classic","pop","classic","classic","pop"};
	vector<int> p{500,600,150,800,2500};
	for(auto i : solution(g,p)){
		cout<<i<<endl;
	}
}


