#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

struct node{
	int priority;
	int pos;
};

bool ismax(deque<node> list, int pivot){
	for(node n : list){
		if(n.priority > pivot) return false;
	}
	return true;
}

int solution(vector<int> priorities, int location) {
    int answer = 1;
    deque<node> list;
    node temp;
    for(int i = 0 ; i < priorities.size() ; i++){
		temp.priority = priorities[i];
		temp.pos = i;
		list.push_back(temp);
	}
	while(!list.empty()){
		temp = list.front();
		list.pop_front();
		if(ismax(list,temp.priority )){
			if(temp.pos == location) break;
			answer++;
		}
		else{
			list.push_back(temp);
		}
	}
    return answer;
}

int main(void){
	vector<int> p = {1,1,9,1,1,1};
	cout<<solution(p,0);
}
