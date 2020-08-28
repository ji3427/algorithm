#include <iostream>
#include <vector>
#include <string.h>
using namespace std;


struct cam{
	int row;
	int col;
	int camN;
};

vector<cam> c;
int sizeC,sizeR;
int minN;
int (*searchL(int row,int col,int board[][8]))[8]{
	for(int i = col ; i >= 0 ; i--){
		if(board[row][i] == 0) board[row][i] = -1;
		else if(board[row][i] == 6) break;
	}
	return board;
}
int (*searchR(int row,int col,int board[][8]))[8]{
	for(int i = col ; i < sizeC ; i++){
		if(board[row][i] == 0) board[row][i] = -1;
		else if(board[row][i] == 6) break;
	}
	return board;
}
int (*searchU(int row,int col,int board[][8]))[8]{
	for(int i = row ; i >= 0 ; i--){
		if(board[i][col] == 0) board[i][col] = -1;
		else if(board[i][col] == 6) break;
	}
	return board;
}
int (*searchD(int row,int col,int board[][8]))[8]{
	for(int i = row ; i < sizeR ; i++){
		if(board[i][col] == 0) board[i][col] = -1;
		else if(board[i][col] == 6) break;
	}
	return board;
}

int dfs(int cur,int board[][8]){
	int origin[8][8];
	memcpy(origin,board,sizeof(origin));
	if(cur == c.size()){
		int ans = 0;
		for(int i = 0 ; i < sizeR ; i++){
			for(int j = 0 ; j < sizeC ; j++){
				if(board[i][j] == 0) ans++;
			}
		}
		return ans;
	}
	for(int i = cur ; i < c.size() ; i++){
		if(c[i].camN == 1){
			if(minN > dfs(cur+1,searchL(c[i].row,c[i].col,board))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,board));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchR(c[i].row,c[i].col,board))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,board));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchU(c[i].row,c[i].col,board))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,board));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchD(c[i].row,c[i].col,board))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,board));
			memcpy(board,origin,sizeof(origin));
		}
		else if(c[i].camN == 2){
			if(minN > dfs(cur+1,searchR(c[i].row,c[i].col,searchL(c[i].row,c[i].col,board)))) minN = dfs(cur+1,searchR(c[i].row,c[i].col,searchL(c[i].row,c[i].col,board)));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchU(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board)))) minN = dfs(cur+1,searchU(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board)));
			memcpy(board,origin,sizeof(origin));
		}
		else if(c[i].camN == 3){
			if(minN > dfs(cur+1,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board)))) minN = dfs(cur+1,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board)));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchR(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board)))) minN = dfs(cur+1,searchR(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board)));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchL(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board)))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board)));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchU(c[i].row,c[i].col,searchL(c[i].row,c[i].col,board)))) minN = dfs(cur+1,searchU(c[i].row,c[i].col,searchL(c[i].row,c[i].col,board)));
			memcpy(board,origin,sizeof(origin));
		}
		else if(c[i].camN == 4){
			if(minN > dfs(cur+1,searchL(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board))))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board))));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchD(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board))))) minN = dfs(cur+1,searchD(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board))));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchL(c[i].row,c[i].col,searchD(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board))))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,searchD(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board))));
			memcpy(board,origin,sizeof(origin));
			if(minN > dfs(cur+1,searchL(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board))))) minN = dfs(cur+1,searchL(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchD(c[i].row,c[i].col,board))));
			memcpy(board,origin,sizeof(origin));
		}
		else if(c[i].camN == 5){
			if(minN > dfs(cur+1,searchD(c[i].row,c[i].col,searchL(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board)))))) minN = dfs(cur+1,searchD(c[i].row,c[i].col,searchL(c[i].row,c[i].col,searchU(c[i].row,c[i].col,searchR(c[i].row,c[i].col,board)))));
			memcpy(board,origin,sizeof(origin));
		}
	}
	return 100;
}


int main(void){
	    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
	int board[8][8];
	cin>>sizeR>>sizeC;
	minN = 200;
	for(int i = 0 ; i < sizeR;i++){
		for(int j = 0 ; j < sizeC ; j++){
			cin>>board[i][j];
			if(board[i][j] != 0 && board[i][j] != 6){
				cam temp;
				temp.row = i;
				temp.col = j;
				temp.camN = board[i][j];
				c.push_back(temp);
			}
		}
	}
	dfs(0,board);
	cout<<minN<<endl;
}
