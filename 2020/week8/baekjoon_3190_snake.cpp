#include <iostream>
#include <vector>
#include <deque>
#include <string.h>
#include <algorithm>
#include <utility>
using namespace std;


int board[200][200];
int dir[10000];
deque<pair<int,int>> snake;
int cur_row = 1;
int cur_col  = 1;

bool isin(int cur_row,int cur_col){
	deque<pair<int,int>>::iterator it;
	it = find(snake.begin()+1,snake.end(),make_pair(cur_row,cur_col));
	if(it == snake.end()) return false;
	else return true;
}


int move(int dir){
	switch (dir){
		case 0: //R
		cur_col++;
		if(isin(cur_row,cur_col)) return -1;
		if(board[cur_row][cur_col] == 1){
			board[cur_row][cur_col] = 0;
			snake.push_front(make_pair(cur_row,cur_col));
		}
		else{
			snake.push_front(make_pair(cur_row,cur_col));
			snake.pop_back();
		}
		break;
		case 1: //D
		cur_row++;
		if(isin(cur_row,cur_col)) return -1;
		if(board[cur_row][cur_col] == 1){
			board[cur_row][cur_col] = 0;
			snake.push_front(make_pair(cur_row,cur_col));
		}
		else{
			snake.push_front(make_pair(cur_row,cur_col));
			snake.pop_back();
		}
		break;
		case 2: //L
		cur_col--;
		if(isin(cur_row,cur_col)) return -1;
		if(board[cur_row][cur_col] == 1){
			board[cur_row][cur_col] = 0;
			snake.push_front(make_pair(cur_row,cur_col));
		}
		else{
			snake.push_front(make_pair(cur_row,cur_col));
			snake.pop_back();
		}
		break;
		case 3: //U
		cur_row--;
		if(isin(cur_row,cur_col)) return -1;
		if(board[cur_row][cur_col] == 1){
			board[cur_row][cur_col] = 0;
			snake.push_front(make_pair(cur_row,cur_col));
		}
		else{
			snake.push_front(make_pair(cur_row,cur_col));
			snake.pop_back();
		}
		break;
	}
	return 0;
}




int main(void){
	int size;
	cin>>size;
	memset(board,0,sizeof(board));
	memset(dir,0,sizeof(dir));
	for(int i = 0 ; i < size ; i++){
		board[0][i] = -1;
		board[i][0] = -1;
		board[size+1][i] = -1;
		board[i][size+1] = -1;
	}
	int t,row,col;
	cin>>t;
	for(int i = 0 ; i < t ; i++){
		cin>>row>>col;
		board[row][col] = 1;
	}
	cin>>t;
	for(int i = 0 ; i < t ; i++){
		int n;
		char c;
		cin>>n>>c;
		if(c == 'D') dir[n] = 1;
		else if(c == 'L') dir[n] = -1;
		
	}
	int time = 0;
	int direction = 0;
	snake.push_front(make_pair(1,1));
	while(1){
		if(board[cur_row][cur_col] == -1 ){
			break;
		}
		if(move(direction) == -1) {
			time++;
			break;
		}
		time++;
		direction += dir[time];
		direction %= 4;
		if(direction < 0) direction += 4;
	}
	cout<<time<<endl;
}


