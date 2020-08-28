#include <iostream>
#include <queue>
#include <utility>
#include <string.h>
using namespace std;

int dx[4] = {0,0,-1,1};
int dy[4] = {1,-1,0,0};

int board[100][100];

struct node{
	int row;
	int col;
	int time;
};


int main(void){
	int size;
	cin>>size;
	memset(board,0,sizeof(board));
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			cin>>board[i][j];
			if(board[i][j] == 1) board[i][j] = -1;
		}
	}
	int row,col,K;
	cin>>col>>row>>K;
	queue<node> q;
	node temp = {row-1,col-1,0};
	q.push(temp);
	int ans = 0;
	board[row-1][col-1] = 101;
	while(!q.empty()){
		node c = q.front();
		if(c.time == K) ans++;
		q.pop();
		for(int i = 0 ; i < 4 ; i++){
			node t;
			if(c.row + dy[i] < 0 || c.row + dy[i] >= size || c.col + dx[i] < 0 || c.col + dx[i] >= size) continue;
			if(board[c.row + dy[i]][c.col + dx[i]] == 0) 
			{	
				board[c.row + dy[i]][c.col + dx[i]] = c.time+1;
				t.row = c.row + dy[i];
				t.col = c.col + dx[i];
				t.time = c.time + 1;
				q.push(t);
			}
		}
	}
	if(ans == 0) cout<<"OH, MY GOD"<<endl;
	else cout<<ans<<endl;
}
