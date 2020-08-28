#include <iostream>
#include <vector>
#include <string>
#include <string.h>
#include <deque>
#include <algorithm>
using namespace std;

int N;
deque<pair<int,int>> q;

int compare(pair<int,int> A, pair<int,int> B){
	if(A.second - A.first == B.second - B.first) return A.first < B.first;
	return A.second - A.first > B.second - B.first;
}

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		cin>>N;
		q.clear();
		int board[200001];
		memset(board,0,sizeof(board));
		q.push_back(make_pair(1,N));
		int index = 1;
		while(index <= N){
			if(index > N) break;
			pair<int,int> f = q.front();
			q.pop_front();
			int mid = (f.first + f.second) / 2;
			board[mid] = index;
			if(f.first < mid ) q.push_back(make_pair(f.first,mid-1));
			if(mid < f.second) q.push_back(make_pair(mid+1,f.second));
			index++;
			sort(q.begin(),q.end(),compare);
		}
		for(int i = 1 ; i <= N ; i++) cout<<board[i]<<" ";
		cout<<endl;
	}
}
