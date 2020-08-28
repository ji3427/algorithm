#include <iostream>
#include <deque>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int N,M;
struct virus{
	int row;
	int col;
	int time;
};

int bfs(int zeroN,deque<virus> q,int board[][50]){
	int ans = 0;
	while(!q.empty()){
		virus f;
		f = q.front();
		q.pop_front();
		if(f.row - 1 >= 0 && board[f.row-1][f.col] == 0){
			virus temp = {f.row - 1,f.col,f.time+1};
			q.push_back(temp);
			zeroN--; 
			board[f.row-1][f.col] = 2;
		}
		else if(f.row - 1 >= 0 && board[f.row-1][f.col] == 3){
			virus temp = {f.row - 1,f.col,f.time+1};
			q.push_back(temp);
			board[f.row-1][f.col] = 2;			
		}
		if(f.row + 1 < N && board[f.row+1][f.col] == 0){
			virus temp = {f.row + 1,f.col,f.time+1};
			q.push_back(temp);
			zeroN--; 
			board[f.row+1][f.col] = 2;
		}
		else if(f.row + 1 < N && board[f.row+1][f.col] == 3){
			virus temp = {f.row + 1,f.col,f.time+1};
			q.push_back(temp);
			board[f.row+1][f.col] = 2;			
		}
		if(f.col - 1 >= 0 && board[f.row][f.col - 1] == 0){
			virus temp = {f.row ,f.col - 1,f.time+1};
			q.push_back(temp);
			zeroN--; 
			board[f.row][f.col-1] = 2;
		}
		else if(f.col - 1 >= 0 && board[f.row][f.col-1] == 3){
			virus temp = {f.row,f.col - 1,f.time+1};
			q.push_back(temp);
			board[f.row][f.col - 1] = 2;			
		}
		if(f.col + 1 < N && board[f.row][f.col+1] == 0){
			virus temp = {f.row ,f.col+1,f.time+1};
			q.push_back(temp);
			zeroN--; 
			board[f.row][f.col+1] = 2;
		}
		else if(f.col + 1 < N && board[f.row][f.col + 1] == 3){
			virus temp = {f.row,f.col+1,f.time+1};
			q.push_back(temp);
			board[f.row][f.col+1] = 2;			
		}
		if(zeroN < 1) return f.time;
	}
	return 1000000;
}


int main(void){
	int board[50][50];
	int cur[50][50];
	cin>>N>>M;
	deque<virus> ori;
	int min_T = 1000000;
	int zeroN = 0;
	for(int i = 0 ; i < N ; i++){
		for(int j = 0 ; j < N ; j++){
			cin>>board[i][j];
			if(board[i][j] == 2){virus v = {i,j,0}; ori.push_back(v);board[i][j] = 3;} 
			if(board[i][j] == 0) zeroN++;
		}
	}
	if(zeroN == 0) {cout<<"0";return 0;}
	deque<virus> q;
	vector<int> ind;
	
	for(int i = 0 ; i < M ; i++) ind.push_back(1);
	for(int i = 0 ; i < ori.size() - M ; i++) ind.push_back(0);
	sort(ind.begin(),ind.end());
	do{
		q.clear();
		memcpy(cur,board,sizeof(board));
		for(int i = 0 ; i < ind.size() ; i++){
			if(ind[i] == 1){
				q.push_back(ori[i]);
				cur[ori[i].row][ori[i].col] = 2;
			}
		}
		int ans = bfs(zeroN,q,cur);
		if(min_T > ans) min_T = ans;
	}while(next_permutation(ind.begin(),ind.end()));	
	if(min_T > 10000) cout<<-1<<endl;
	else cout<<min_T+1<<endl;
}
