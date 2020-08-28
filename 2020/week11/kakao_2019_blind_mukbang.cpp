#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <deque>
#include <algorithm>
#define ll long long

using namespace std;

struct node{
	ll index;
	ll ft;
};
bool compare(node A,node B){
	return A.ft < B.ft;
}

bool comparei(node A,node B){
	return A.index < B.index;
}


int solution(vector<int> food_times, long long k) {
    int answer = 0;
    int mtime = 0;
	deque<node> fl;
	for(int i = 0 ; i < food_times.size() ;i++){
		node t = {i+1,food_times[i]};
		fl.push_back(t);
	}
	sort(fl.begin(),fl.end(),compare);
	while(1){
		if(k - ((fl[0].ft-mtime) * (signed)fl.size()) < 0){
			break;
		}
		k -= (fl[0].ft-mtime) * fl.size();
		int minN = fl[0].ft;
		mtime = fl[0].ft;
		for(auto i : fl){
		cout<<i.index<<" "<<i.ft<<" "<<i.ft-mtime<<endl;
		}
		cout<<"-----------------------"<<endl;
		while(fl[0].ft <= minN ) fl.pop_front();
	}
	k %= fl.size();
	sort(fl.begin(),fl.end(),comparei);
	if(fl.size() == 0) answer = -1;
	else answer = fl[k].index;
    return answer;
}



int main(void){
	vector<int> food_times = {1,2,3,4,5,6,7,8,9,10};
	cout<<solution(food_times,20);
}
