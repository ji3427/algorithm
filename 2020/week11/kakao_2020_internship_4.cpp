#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <set>

using namespace std;

int dy[4] = {0,0,-1,1};
int dx[4] = {1,-1,0,0};
int size;
int minN;
int visit[25][25];

void dfs(int row,int col,int before,int value,vector<vector<int>> &board){
	visit[row][col] = value;
	if(row == size - 1 && col == size - 1) {if(value < minN) minN = value; return;}
	for(int i = 0 ; i < 4 ; i++){
		if(row + dx[i] < 0 || row + dx[i] >= size || col + dy[i] < 0 || col + dy[i] >= size) continue;
		if(board[row + dx[i]][col+dy[i]] == 0 && !((i == 0 && before == 1) || (i == 1 && before == 0) || (i == 2 && before == 3) || (i == 3 && before == 2))){
			int next_value; 
			if(before == -1) next_value = value + 100;
			else if((before < 2 && i >= 2) || (before >= 2 && i < 2)) next_value = value + 600;	
			else next_value = value + 100;
			if(next_value >  visit[row+dx[i]][col+dy[i]]) continue;
			dfs(row+dx[i],col+dy[i],i,next_value,board);
		} 
	}
}


int solution(vector<vector<int>> board) {
    minN = 10000000;
    size = board.size();
    for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			visit[i][j] = 100000000;
		}
	}
	visit[0][0] = 0;
    dfs(0,0,-1,0,board);
    int answer = minN;
    return answer;
}


int main(void){
	vector<vector<int>> board = {{0,1,1},{0,0,0},{1,1,0}};
	cout<<solution(board);
}
