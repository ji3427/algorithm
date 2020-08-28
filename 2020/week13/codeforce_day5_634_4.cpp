#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <string.h>
#include <algorithm>

using namespace std;

int board[9][9];
int visied[10];

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				char c;
				cin>>c;
				board[i][j] = c - '0';
			}
		}
/*		memset(visied,0,sizeof(visied));
		visied[board[0][0] - 1] = true;
		visied[board[1][3] - 1] = true;
		visied[board[2][6] - 1] = true;
		for(int i = 0 ; i < 9 ; i++){
			if(visied[i] == false){
				board[0][0] = i + 1;
				board[1][3] = i + 1;
				board[2][6] = i + 1;
				break;
			}
		}
		memset(visied,0,sizeof(visied));
		visied[board[3][1]] = true;
		visied[board[4][4]] = true;
		visied[board[5][7]] = true;
		for(int i = 0 ; i < 9 ; i++){
			if(visied[i] == false){
				board[3][1] = i + 1;
				board[4][4] = i + 1;
				board[5][7] = i + 1;
				break;
			}
		}
		memset(visied,0,sizeof(visied));
		visied[board[6][2]] = true;
		visied[board[7][5]] = true;
		visied[board[8][8]] = true;
		for(int i = 0 ; i < 9 ; i++){
			if(visied[i] == false){
				board[6][2] = i + 1;
				board[7][5] = i + 1;
				board[7][8] = i + 1;
				break;
			}
		}*/
		board[0][0] = board[0][1];
		board[1][3] = board[1][4];
		board[2][6] = board[2][7];
		board[3][1] = board[3][2];
		board[4][4] = board[4][4];
		board[5][7] = board[5][8];
		board[6][2] = board[6][1];
		board[7][5] = board[7][4];
		board[8][8] = board[8][7];
		for(int i = 0 ; i < 9 ; i++){
			for(int j = 0 ; j < 9 ; j++){
				cout<<board[i][j]<<" ";
			}
			cout<<endl;
		}
	}
}
