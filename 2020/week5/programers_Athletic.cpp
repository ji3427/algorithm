#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>> r;
    priority_queue<int,vector<int>,greater<int>> l;
    for(int i : lost) l.push(i);
    for(int i : reserve) r.push(i);
    while(!l.empty()){
		if(r.empty()){answer += l.size();break;}
		if(abs(l.top() - r.top()) <= 1){
			l.pop();
			r.pop();
		}
		else if(l.top() - r.top() > 1){
			answer++;
			r.pop();
		}
		else if(l.top() - r.top() < -1){
			l.pop();
		}
	}
    return n-answer;
}
