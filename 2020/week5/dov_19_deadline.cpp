#include <iostream>
#include <queue>
#include <map>
using namespace std;

int main(void){
	multimap<int,int> m;
	int ans = 0;
	int maxtime = 0;
	priority_queue<int,vector<int>,greater<int>> pq;
	while(1){
		int time,value;
		cin>>time>>value;
		if(cin.eof()) break;
		m.insert(make_pair(time,value));
		if(time > maxtime) maxtime = time;
	}
	for(int i = 1 ; i <= maxtime ; i++){
		auto range = m.equal_range(i);
		for(auto it = range.first ; it != range.second ; it++){
			pq.push(it->second);
		}
		while(pq.size() > i){
			pq.pop();
		}
	}
	while(!pq.empty()){
		ans += pq.top();
		pq.pop();
	}
	cout<<ans<<endl;
}
