#include <iostream>
#include <vector>
#include <queue>

int horse_moveC[2] = {1,2};
int horse_moveR[2] = {2,1};
int monkey_moveC[4] = {-1,0,1,0};
int monkey_moveR[4] = {0,1,0,-1};
using namespace std;

int board[200][200];

struct pos{
    int row;
    int col;
    int K;
    int move;
};


int main(void){
    int K;
    int answer = -1;
    int row,col;
    cin>>K>>col>>row;
    for(int i = 0 ; i < row; i++){
		for(int j = 0 ; j < col ; j++){
			cin>>board[i][j];
		}
    }
    queue<pos> q;
    pos temp = {0,0,0,0};
    q.push(temp);
    while(!q.empty()){
		pos data = q.front();
		q.pop();
		cout<<"cur row col : "<<data.row<<" "<<data.col<<" "<<data.move<<endl;
		if(data.row == row - 1 && data.col == col-1){
			answer = data.move;
			break;
		}
		if(data.K < K){
			for(int i = 0 ; i < 2 ; i++){
				temp = data;
				if(temp.row + horse_moveR[i] >= row || temp.col + horse_moveC[i] >= col || temp.row + horse_moveR[i] < 0 || temp.col + horse_moveC[i] < 0 ){
					continue;
				}
			temp.row += horse_moveR[i];
			temp.col += horse_moveC[i];
			temp.K++;
			temp.move++;
			q.push(temp);
			}
		}
		for(int i = 0 ; i < 4 ; i++){
			temp = data;
			if(temp.row + monkey_moveR[i] >= row || temp.col + monkey_moveC[i] >= col || temp.row + monkey_moveR[i] < 0 || temp.col + monkey_moveC[i] < 0 || board[temp.row + monkey_moveR[i]][temp.col + monkey_moveC[i]] == 1){
				continue;
			}
			temp.row += monkey_moveR[i];
			temp.col += monkey_moveC[i];
			temp.move++;
			if(monkey_moveR[i] < 0 || monkey_moveC[i] < 0){
				if(temp.K < K) q.push(temp);
			}
			else q.push(temp);
		}
    }
    cout<<answer<<endl;
}
