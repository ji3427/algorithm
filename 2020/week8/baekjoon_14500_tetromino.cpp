#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;

int board[500][500];
int sizeR,sizeC;

int getnext(int row,int col,int n,int flag){
	if(n == 5) return 0;
	vector<int> next(4);
	if(row + 1 < sizeR && flag != 2) next[0] = board[row][col]+getnext(row+1,col,n+1,0);
	if(col + 1 < sizeC && flag != 3) next[1] = board[row][col]+getnext(row,col+1,n+1,1);
	if(row - 1 >= 0 && flag != 0) next[2] = board[row][col]+getnext(row-1,col,n+1,2);
	if(col - 1 >= 0 && flag != 1) next[3] = board[row][col]+getnext(row,col-1,n+1,3);
	sort(next.begin(),next.end());
	return next[3];
}

int getO(int row,int col){
	int max1 = 0,max2 = 0;
	if(row + 2 < sizeR){
		max1 = board[row][col] + board[row+1][col] + board[row+2][col];
		int R=0,L=0;
		if(col +1 < sizeC) R = board[row+1][col+1];
		if(col - 1 >= 0) L = board[row+1][col-1];
		max1 += max(R,L);
	}
	if(col +2 <sizeC){
		max2 = board[row][col] + board[row][col+1] + board[row][col+2];
		int U = 0,D = 0;
		if(row + 1 < sizeR) U = board[row+1][col+1];
		if(row - 1 >= 0) D = board[row-1][col+1];
		max2 += max(U,D);
	}
	return max(max1,max2);
}


int main(void){
	cin>>sizeR>>sizeC;
	int max = 0;
	for(int i = 0 ; i <sizeR ; i++){
		for(int j = 0 ; j < sizeC ; j++){
			cin>>board[i][j];
		}
	}
	for(int i = 0 ; i <sizeR ; i++){
		for(int j = 0 ; j < sizeC ; j++){
			if(getnext(i,j,1,10) > max) max = getnext(i,j,1,10);
			if(getO(i,j) > max) max = getO(i,j);
		}
	}
	cout<<max<<endl;
	
}
