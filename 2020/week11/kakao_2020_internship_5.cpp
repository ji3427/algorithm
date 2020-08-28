#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <set>
#include <deque>

using namespace std;

map<int,int> m;


int find_parent(int n){
	if(m[n] == 0) return n;
	return find_parent(m[n]);
}


bool solution(int n, vector<vector<int>> path, vector<vector<int>> order) {
    bool answer = true;
    deque<vector<int>> mod;
    int parent,child;
    for(int i = 0 ; i < path.size() ; i++){
		if(path[i][1] == 0 || m.find(path[i][1]) != m.end()) {parent = path[i][1]; child = path[i][0];}
		else if(path[i][0] == 0 || m.find(path[i][0]) != m.end()) {parent = path[i][0]; child = path[i][1];}
		else{
			mod.push_back(path[i]);
			continue;
		}
		m.insert(make_pair(child,parent));
	}
	while(!mod.empty()){
		if(m.find(mod.front().at(1)) != m.end()) {parent = mod.front().at(1); child = mod.front().at(0);}
		else if(m.find(mod.front().at(0)) != m.end()) {parent = mod.front().at(0); child = mod.front().at(1);}
		else{
			mod.push_back(mod.front());
			mod.pop_front();
			continue;
		}
		m.insert(make_pair(child,parent));
        mod.pop_front();
	}
	map<int,int> ans;
    int index = 0;
	for(int i = 0 ; i < order.size() ; i++){
		int key = find_parent(order[i][0]);
		int value = find_parent(order[i][1]);
		map<int,int>::iterator it = ans.find(value);
        if(it->second == key) break;
        index++;
        ans.insert(make_pair(key,value));
	}
	if(index == order.size()) answer = true;
	else answer =false;
    return answer;
}





int main(void){
	
}
