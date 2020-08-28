#include <iostream>
#include <utility>
#include <vector>
#include <string.h>
using namespace std;

int board[20][20];
int dice [6]; //0L 1M 2R 3U 4D 5O

void moveR(){
	int td[6];
	memcpy(td,dice,sizeof(dice));
	dice[1] = td[0];
	dice[2] = td[1];
	dice[5] = td[2];
	dice[0] = td[5];
}
void moveL(){
	int td[6];
	memcpy(td,dice,sizeof(dice));
	dice[0] = td[1];
	dice[1] = td[2];
	dice[5] = td[0];
	dice[2] = td[5];
}
void moveU(){
	int td[6];
	memcpy(td,dice,sizeof(dice));
	dice[1] = td[4];
	dice[3] = td[1];
	dice[5] = td[3];
	dice[4] = td[5];
}
void moveD(){
	int td[6];
	memcpy(td,dice,sizeof(dice));
	dice[4] = td[1];
	dice[1] = td[3];
	dice[3] = td[5];
	dice[5] = td[4];
}


int main(void){
	int row,col;
	pair<int,int> cur;
	int size;
	cin>>row>>col;
	cin>>cur.first>>cur.second;
	cin>>size;
	for(int i = 0 ; i < row ; i++){
		for(int j = 0 ; j < col ; j++){
			cin>>board[i][j];
		}
	}
	memset(dice,0,sizeof(dice));
	int dir;
	for(int s = 0 ; s < size ; s++){
		cin>>dir;
		if(dir == 1){
			cur.second++;
			if(cur.second >= col){cur.second--; continue;}
			moveR();
		}
		else if(dir == 2){
			cur.second--;
			if(cur.second < 0) {cur.second++;continue;}
			moveL();
		}
		else if(dir == 3){
			cur.first--;
			if(cur.first < 0) {cur.first++;continue;}
			moveU();
		}
		else if(dir == 4){
			cur.first++;
			if(cur.first >= row) {cur.first--;continue;}
			moveD();
		}
		if(board[cur.first][cur.second] == 0){
			board[cur.first][cur.second] = dice[5];
		}
		else{
			dice[5] = board[cur.first][cur.second];
			board[cur.first][cur.second] = 0;
		}
		cout<<dice[1]<<endl;
	}
	
}
