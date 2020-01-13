#include <iostream>
#include <string.h>
using namespace std;
bool board[101][101];



void black(int row, int col, int L){
	for(int i = row ; i < row + L ; i++){
		for(int j = col ; j < col + L ; j++){
			board[i][j] = true;
		}
	}
}

void white(int row, int col, int L){
	for(int i = row ; i < row + L ; i++){
		for(int j = col ; j < col + L ; j++){
			board[i][j] = false;
		}
	}
}

int test(int row, int col, int L){
	int size = 0;
	for(int i = row ; i < row + L ; i++){
		for(int j = col ; j < col + L ; j++){
			if(board[i][j]){ 
				size++;
//				cout<<"("<<i<<", "<<j<<")"<<endl;
		}
		}
	}
	return size;

}

int main(void)
{
	int num;
	cin>>num;
	char text[10];
	int row,col,L;
	memset(board,0,sizeof(board));
	for(int i = 0 ; i < num ; i++){
		cin>>text>>row>>col>>L;
		if(text[0] == 'B') black(row,col,L);
		else if(text[0] == 'W') white(row,col,L);
		else if(text[0] == 'T') cout<<test(row,col,L)<<endl;
	}
}
