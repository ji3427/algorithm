#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int board[100][100];
int size;
int len;
int main(void){
	int ans = 0;
	cin>>size;
	cin>>len
	for(int i = 0 ; i < size; i++){
		for(int j = 0 ; j < size ; j++){
			cin>>board[i][j];
		}
	}
	for(int i = 0 ; i < size ; i++){
		if(sol(i,0)) ans++;
		if(sol(i,1)) ans++;
	}
	cout<<ans;
}


bool sol(int line,int vertical){
	bool bf[100];
	memset(bf,0,sizeof(bf));
	if(vertical == 0){
		for(int i = 0 ; i < size ; i++){
			if(board[line][i] )
		}
	}
}


int judge(vector<int> l){
	
}

