#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
using namespace std;

struct node{
	vector<int> s; 
	vector<int> l; 
};

int board[20][20];


int cal(node n){
	int ssum = 0, lsum = 0;
	for(int i = 0 ; i < n.s.size() ; i++){
		for(int j = i + 1 ; j < n.s.size(); j++){
			ssum += board[n.s[i]][n.s[j]];
			ssum += board[n.s[j]][n.s[i]];
		}
	}
	for(int i = 0 ; i < n.l.size() ; i++){
		for(int j = i + 1 ; j < n.l.size(); j++){
			lsum += board[n.l[i]][n.l[j]];
			lsum += board[n.l[j]][n.l[i]];
		}
	}
	return abs(ssum - lsum);
}

void de(node n){
	int ssum = 0, lsum = 0;
	for(int i = 0 ; i < n.s.size() ; i++){
		for(int j = i + 1 ; j < n.s.size(); j++){
			ssum += board[n.s[i]][n.s[j]];
			ssum += board[n.s[j]][n.s[i]];
		}
	}
	for(int i = 0 ; i < n.l.size() ; i++){
		for(int j = i + 1 ; j < n.l.size(); j++){
			lsum += board[n.l[i]][n.l[j]];
			lsum += board[n.l[j]][n.l[i]];
		}
	}
	for(auto i : n.s) cout<<i<<" ";
	cout<<ssum<<endl;
	for(auto i : n.l) cout<<i<<" ";
	cout<<lsum<<endl;
}

int main(void){
	int size;
	int min = 3000000;
	cin>>size;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			cin>>board[i][j];
		}
	}
	node n;
	queue<node> q;
	q.push(n);
	while(1){
		n = q.front();
		int index = n.s.size() + n.l.size();
		if(index == size) break;
		node next = n;
		next.s.push_back(index);
		q.push(next);
		next = n;
		next.l.push_back(index);
		q.push(next);
		q.pop();
	}
	while(!q.empty()){
		if(q.front().s.size() == size / 2 && min > cal(q.front())) {
			min = cal(q.front());
			//de(q.front());
		}
		q.pop();
	}
	cout<<min<<endl;
}



