#include <iostream>
#include <vector>
#include <string>
using namespace std;

int board[100][100];

//기둥 1 보 2


vector<vector<int>> solution(int n, vector<vector<int>> build_frame) {
    vector<vector<int>> answer;
    for(int i = 0 ; i < build_frame.size() ; i++){
		int col = build_frame[i][0];
		int row = build_frame[i][1];
		int gob = build_frame[i][2];
		int dob = build_frame[i][3];
		if(gob == 1){
			if(dob == 0){
				
			}
			else if(dob = =1){
				if(row == 0 || board[row-1][col] == 1 || board[row][col+1] == 2 || board[row][col-1] == 2){
					board[row][col] = 1;
				}
			}
		}
		else if(gob == 0){
			if(dob == 0){
				
			}
			else if(dob == 1){
				
			}
		}
	}
    return answer;
}


int main(void){
	string a = "a";
	cout<<solution(a);
}
