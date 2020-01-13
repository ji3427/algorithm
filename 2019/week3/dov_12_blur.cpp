#include <iostream>
#include <string.h>
using namespace std;

int board[10][10];
int main(void){
	int row,col;
	char trash[10];
	cin>>trash;
	cin>>row>>col;
	for(int i = 0 ; i < row ; i++){
		memset(trash,0,sizeof(trash));
		cin>>trash;
		for(int j = 0 ; j < col ; j++){
			board[i][j] = trash[j] - '0';
		}
	}
	cin>>trash;
	int sum = 0;
	for(int i = 0 ; i < row - 1 ; i++){
		for(int j = 0 ; j < col -1; j++){
			board[i][j] = (board[i][j] + board[i + 1][j + 1] + board[i][j + 1] + board[i + 1][j]) / 4;
			cout<<board[i][j];
		}
		cout<<endl;
	}
}
