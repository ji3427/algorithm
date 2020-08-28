#include <iostream>
#include <vector>
#include <set>
using namespace std;

int board[50][50];
int sizeR,sizeC;

bool searchL(int row,int col){
		if(col - 1 < 0) return false;
		if(board[row][col-1] == 0) return true;
		else return false;
}
bool searchR(int row,int col){
		if(col+1 >= sizeC) return false;
		if(board[row][col+1] == 0) return true;
		else return false;
}
bool searchU(int row,int col){
	if(row - 1 < 0 ) return false;
		if(board[row-1][col] == 0) return true;
		else return false;
}
bool searchD(int row,int col){
	if(row+1 >= sizeR) return false;
	if(board[row+1][col] == 0) return true;
	else return false;
}



int main(void){
	cin>>sizeR>>sizeC;
	int cur_R,cur_C;
	int dir;
	cin>>cur_R>>cur_C>>dir;
	for(int i = 0 ; i < sizeR ; i++){
		for(int j = 0 ; j < sizeC ; j++){
			cin>>board[i][j];
		}
	}
	int ans= 0;
	board[cur_R][cur_C] = 2;
	while(1){
		board[cur_R][cur_C] = 2;
		//cout<<cur_R<<" "<<cur_C<<" "<<dir<<" "<<searchR(cur_R,cur_C)<<" "<<searchL(cur_R,cur_C)<<" "<<searchU(cur_R,cur_C)<<" "<<searchD(cur_R,cur_C)<<endl;
		if(!searchL(cur_R,cur_C) && !searchR(cur_R,cur_C) && !searchU(cur_R,cur_C) && !searchD(cur_R,cur_C)){
			if(dir == 0) cur_R++;
			else if(dir == 1) cur_C--;
			else if(dir == 2) cur_R--;
			else if(dir == 3) cur_C++;
			if(board[cur_R][cur_C] == 1) break;
			continue;
		}
		if(dir == 0){
			if(searchL(cur_R,cur_C) == true){
				dir = 3;
				cur_C--;
				ans++;
			}
			else{
				dir = 3;
				continue;
			}
		}
		else if(dir == 1){
			if(searchU(cur_R,cur_C) == true){
				dir = 0;
				cur_R--;
				ans++;
			}
			else{
				dir = 0;
				continue;
			}
		}
		else if(dir == 2){
			if(searchR(cur_R,cur_C) == true){
				dir = 1;
				cur_C++;
				ans++;
			}
			else{
				dir = 1;
				continue;
			}
		}
		else if(dir == 3){
			if(searchD(cur_R,cur_C) == true){
				dir = 2;
				cur_R++;
				ans++;
			}
			else{
				dir = 2;
				continue;
			}
		}
	}
	cout<<ans+1<<endl;
}

