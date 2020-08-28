#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <string.h>
#include <map>
#include <set>
#include <queue>

using namespace std;
int board[101][101];
int dp[101][101];
int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

struct node{
	int row;
	int col;
};

int nodeN;

void dfs(int row,int col,int size){
	nodeN++;
	if(row == size - 1 && col == size -1){
		return;
	}
	for(int i = 0 ; i < 4 ; i++){
		if(row + dy[i] >= size || row + dy[i] < 0 || col + dx[i] >= size || col + dx[i] < 0) continue;
		if(dp[row][col] + board[row + dy[i]][col+dx[i]] >= dp[row + dy[i]][col+dx[i]]) continue;
		dp[row + dy[i]][col+dx[i]] = dp[row][col] + board[row + dy[i]][col+dx[i]];
		dfs(row + dy[i],col+dx[i],size);
	}
}

queue<node> list;
int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		int size;
		nodeN = 0;
		memset(board,0,sizeof(board));
		memset(dp,0,sizeof(dp));
		cin>>size;
		for(int i = 0 ; i < size; i++){
			string str;
			cin>>str;
			for(int j = 0 ; j < size ; j++){
				board[i][j] = str[j] - '0';
				dp[i][j] = 100000000;
			}
		}
		dp[0][0] = board[0][0];
		//dfs(0,0,size);
		node start = {0,0};
		list.push(start);
		while(!list.empty()){
			nodeN++;
			node cur = list.front();
			list.pop();
			for(int i = 0 ; i < 4 ; i++){
				if(cur.row + dy[i] >= size || cur.row + dy[i] < 0 || cur.col + dx[i] >= size || cur.col + dx[i] < 0) continue;
				if(dp[cur.row][cur.col] + board[cur.row + dy[i]][cur.col+dx[i]] >= dp[cur.row + dy[i]][cur.col+dx[i]]) continue;
				dp[cur.row + dy[i]][cur.col+dx[i]] = dp[cur.row][cur.col] + board[cur.row + dy[i]][cur.col+dx[i]];
				node next = {cur.row + dy[i],cur.col+dx[i]};
				list.push(next);
			}			
		}
		cout<<"#"<<t+1<<" "<<dp[size-1][size-1]<<endl;
		cout<<"visit node "<<nodeN<<endl;
	}
}
