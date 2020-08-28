#include <queue>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
#define ll long long

struct node{
	pair<int,int> pos;
	int time;
};
int board[10][10];

pair<int,int> moveL(int row,int col){
	while(board[row][col] != -1){
		if(board[row][col] == 1) return make_pair(row,col);
		col--;
	}
	return make_pair(row,col+1);
}
pair<int,int> moveR(int row,int col){
	while(board[row][col] != -1){
		if(board[row][col] == 1) return make_pair(row,col);
		col++;
	}
	return make_pair(row,col-1);
}
pair<int,int> moveU(int row,int col){
	while(board[row][col] != -1){
		if(board[row][col] == 1) return make_pair(row,col);
		row--;
	}
	return make_pair(row+1,col);
}
pair<int,int> moveD(int row,int col){
	while(board[row][col] != -1){
		if(board[row][col] == 1) return make_pair(row,col);
		row++;
	}
	return make_pair(row-1,col);
}

int main(void){
	int n,m;
	cin>>n>>m;
	
	pair<int,int> red;
	pair<int,int> blue;
	queue<node> q;
	pair<int,int> goal;
	int flagR,flagD;
	for(int i = 0 ; i < n ; i++){
		for(int j = 0 ; j < m ; j++){
			char temp;
			cin>>temp;
			if(temp== '#') board[i][j] = -1;
			else if(temp== '.') board[i][j] = 0;
			else if(temp== 'R') red = make_pair(i,j);
			else if(temp== 'B') blue = make_pair(i,j);
			else if(temp== 'O') {board[i][j] = 1; goal = make_pair(i,j);}
		}
	}
	node t;
	t.pos = red;
	t.time = 0;
	q.push(t);
	int red_ans = 0;
	while(!q.empty()){
		if(q.front().time > 10){
			red_ans = -1;
			break;
		}
		int ti = q.front().time;
		pair<int,int> cur = q.front().pos;
		q.pop();
		if(t.pos.first == goal.first && t.pos.second == goal.second){
			red_ans = ti+1;
			break;
		}
		t.time = ti+1;
		t.pos = moveL(cur.first,cur.second);
		if(t.pos.first == cur.first && t.pos.second == cur.second);
		else if(t.pos.first == goal.first && t.pos.second == goal.second){
			red_ans = ti+1;
			flagR = 0;
			break;
		}
		else q.push(t);
		t.pos = moveR(cur.first,cur.second);
		if(t.pos.first == cur.first && t.pos.second == cur.second);
		else if(t.pos.first == goal.first && t.pos.second == goal.second){
			red_ans = ti+1;
			flagR = 1;
			break;
		}
		else q.push(t);
		t.pos = moveU(cur.first,cur.second);
		if(t.pos.first == cur.first && t.pos.second == cur.second) ;
		else if(t.pos.first == goal.first && t.pos.second == goal.second){
			red_ans = ti+1;
			flagR = 2;
			break;
		}
		else q.push(t);
		t.pos = moveD(cur.first,cur.second);
		if(t.pos.first == cur.first && t.pos.second == cur.second) ;
		else if(t.pos.first == goal.first && t.pos.second == goal.second){
			red_ans = ti+1;
			flagR = 3;
			break;
		}
		else q.push(t);
	}
	while(!q.empty()) q.pop();
	t.time = 0;
	t.pos = blue;
	q.push(t);
	int blue_ans = 999;
	if(red_ans < blue_ans|| (red_ans == blue_ans && flagD != flagR)) cout<<red_ans<<endl;
	else cout<<-1;
}



