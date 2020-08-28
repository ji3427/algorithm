#include <string>
#include <vector>
#include <map>
#include <iostream>
#include <algorithm>
using namespace std;

bool compare(int A, int B){
	return A < B;
}


int solution(int distance, vector<int> rocks, int n) {
    int answer = 0;
    map<int,int> dst;
    rocks.push_back(distance);
    sort(rocks.begin(),rocks.end(),compare);
    dst.insert(make_pair(rocks.front(),1));
    for(int i = 1 ; i < rocks.size() ; i++){
		int d = rocks[i] - rocks[i-1];
		if(dst.find(d) == dst.end()) dst.insert(make_pair(d,1));
		else dst[d]++;
	}
	map<int,int>::iterator it = dst.begin();
	for(; it != dst.end() ; it++){
		if(it->second >= n) answer = max(answer,it->first);
	}
    return answer;
}


int main(void){
	vector<int> r = {2,14,11,21,17};
	cout<<solution(25,r,2);
}
