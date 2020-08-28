#include <iostream>
#include <vector>
using namespace std;


// 0 : x+1  1 : y+1  2 : x - 1 3 : y - 1
//  0 >   1 -> 2 2 -> 3 3 -> 0

int pos_x[4] ={1,0,-1,0};
int pos_y[4] ={0,-1,0,1};

bool board[101][101];

int main(void){
	int cur_x,cur_y;
	int d,g;
	int size;
	cin>>size;
	int ans = 0;
	vector<int> spots;
	for(int i = 0 ; i < size ; i++){
		spots.clear();
		cin>>cur_x>>cur_y>>d>>g;
		if(cur_x >= 0 && cur_y >= 0&&cur_x <= 100 && cur_y <= 100)board[cur_x][cur_y] = true;
		cur_x += pos_x[d];
		cur_y += pos_y[d];
		if(cur_x <= 100 && cur_y <= 100)board[cur_x][cur_y] = true;
		spots.push_back(d);
		for(int j = 0 ; j < g ; j++){
			vector<int> new_spot;
			vector<int>::reverse_iterator it = spots.rbegin();
			for(; it != spots.rend() ; it++){
				int dir = (*it) + 1;
				if(dir > 3) dir = 0;
				new_spot.push_back(dir);
				cur_x += pos_x[dir];
				cur_y += pos_y[dir];
				if(cur_x >= 0 && cur_y >= 0&&cur_x <= 100 && cur_y <= 100)board[cur_x][cur_y] = true;
			}
			spots.insert(spots.end(),new_spot.begin(),new_spot.end());
		}
	}
	for(int i = 0 ; i < 100 ; i++){
		for(int j = 0 ; j < 100 ; j++){
			if(board[i][j] && board[i][j+1] && board[i+1][j] && board[i+1][j+1]){
				ans++;
			} 
		}
	}
	cout<<ans<<endl;
}
