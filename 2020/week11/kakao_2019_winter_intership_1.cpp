#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int solution(vector<vector<int>> board, vector<int> moves) {
    int answer = 0;
    vector<int> s;
    for(int i = 0 ; i < moves.size() ;i++){
		for(int j = 0 ; j < board.size(); j++){
			if(board[j][moves[i]-1] != 0){
				if(!s.empty() && s.back() == board[j][moves[i]-1]) {s.pop_back(); answer+=2;}
				else s.push_back(board[j][moves[i]-1]);
				board[j][moves[i]-1] = 0;
				break;
			}
		}
	}
    return answer;
}



int main(void){
	vector<vector<int>> a = {{0,0,0,0,0},{0,0,1,0,3},{0,2,5,0,1},{4,2,4,4,2},{3,5,1,3,1}};
	vector<int> m = {1,5,3,5,1,2,1,4};
	cout<<solution(a,m);
}

