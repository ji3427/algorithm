#include <iostream>
#include <string.h>
#include <cstdlib>
using namespace std;

int board[10][10];
int result[10][10];
int size;
void addmine(int row, int col);
void openmine();
int main(void)
{
	char line[10];
	cin>>size;
	for(int i = 0 ; i < size; i++){
		cin>>line;
		for(int j = 0 ; j < size; j++){
			if(line[j] == '*') {
				addmine(i,j);
				board[i][j] = -100;
			}
		}
	}
	
	for(int i = 0 ; i < size; i++){
		cin>>line;
		for(int j = 0 ; j < size; j++){
			if(line[j] == 'x' && board[i][j] >= 0){
				result[i][j] = board[i][j];
			}
			else if(line[j] == 'x' && board[i][j] < 0){
				openmine();
			}
			else{
				if(result[i][j] >= 0) result[i][j] = 100;
			}
	}
}
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			if(result[i][j] >= 100) cout<<".";
			else if(result[i][j] < 0) cout<<"*";
			else cout<<result[i][j];
		}
		cout<<endl;
	}
}


void addmine(int row, int col){
	if(row -1 >= 0 && col -1 >= 0) board[row-1][col-1]++;
	if(row -1 >= 0) board[row-1][col]++;
	if(row -1 >= 0 && col +1 < size) board[row-1][col+1]++;
	if(col -1 >= 0) board[row][col-1]++;
	if(col +1 < size) board[row][col+1]++;
	if(row +1 < size && col -1 >= 0) board[row+1][col-1]++;
	if(row +1 < size) board[row+1][col]++;
	if(row +1 < size && col +1 < size) board[row+1][col+1]++;
	}
	
void openmine(){
	for(int i = 0 ; i < size ; i++)
		for(int j = 0 ; j < size ; j++)
		if(board[i][j] < 0) result[i][j] = -100;
}
