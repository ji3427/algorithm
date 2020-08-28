#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int cube[6][3][3];
int cur[6][3][3];
// 0 : 윗, 흰 1 : 아래 노랑 2: 앞 빨강  3 왼쪽 초록 4: 뒷 오랜지 5 오른쪽 파랑
//0 +,- 2,3,4,5 row[0] 바뀜 + : 빨 -> 초 -> 오렌지 -> 파랑  
//1 +,- 2,3,4,5 row[2] 바뀜 + :  빨 -> 초 -> 오렌지 -> 파랑
//2  + - 3,5 col[2] 0,1 row[2] 흰 -> 초->노->파랑
//4 + - 3,5 col[0] 0,1 row[0] 흰 -> 초 -> 노 -> 파
//3, + - 0,1,2,4 col[0] 바뀜   
//5 + - 0,1,2,4 col[2] 바뀜

void swapR(int pageA,int rowA,int pageB,int rowB){
	int temp[3];
	for(int i = 0 ; i < 3 ; i++){
		temp[i] = cur[pageA][rowA][i];
		cur[pageA][rowA][i] = cur[pageB][rowB][i];
		cur[pageB][rowB][i] = temp[i];
	}
}

void swapC(int pageA,int colA,int pageB,int colB){
	int temp[3];
	for(int i = 0 ; i < 3 ; i++){
		temp[i] = cur[pageA][i][colA];
		cur[pageA][i][colA] = cur[pageB][i][colB];
		cur[pageB][i][colB] = temp[i];
	}
}
void swapCR(int pageA,int colA,int pageB,int colB){
	int temp[3];
	for(int i = 0 ; i < 3 ; i++){
		temp[i] = cur[pageA][i][colA];
		cur[pageA][i][colA] = cur[pageB][2-i][colB];
		cur[pageB][i][colB] = temp[i];
	}
}
void swapM(int pageA,int rowA,int pageB,int colB){
	int temp[3];
	for(int i = 0 ; i < 3 ; i++){
		temp[i] = cur[pageA][rowA][i];
		cur[pageA][rowA][i] = cur[pageB][i][colB];
		cur[pageB][i][colB] = temp[i];
	}
}



void rotate(int dir,int flag){
	switch(dir){
	case 'U':
	if(flag == '+'){
		swapR(2,0,3,0);
		swapR(2,0,4,0);
		swapR(2,0,5,0);
	}
	else if(flag == '-'){
		swapR(2,0,5,0);
		swapR(2,0,4,0);
		swapR(2,0,3,0);
	}
	break;
	case 'D':
	if(flag == '-'){
		swapR(2,2,3,2);
		swapR(2,2,4,2);
		swapR(2,2,5,2);
	}
	else if(flag == '+'){
		swapR(2,2,5,2);
		swapR(2,2,4,2);
		swapR(2,2,3,2);
	}
	break;
	case 'R':
	if(flag == '+'){
		swapC(2,2,0,2);
		swapC(2,2,4,2);
		swapC(2,2,1,2);
	}
	else if(flag == '-'){
		swapC(2,2,1,2);
		swapC(2,2,4,2);
		swapC(2,2,0,2);
	}
	break;
	case 'L':
	if(flag == '-'){
		swapC(2,0,0,0);
		swapC(2,0,4,0);
		swapC(2,0,1,0);
	}
	else if(flag == '+'){
		swapC(2,0,1,0);
		swapC(2,0,4,0);
		swapC(2,0,0,0);
	}
	break;
	case 'F':
	if(flag == '+'){
		
	}
	else if(flag == '-'){
		
	}
	break;
	case 'B':
	if(flag == '+'){
		
	}
	else if(flag == '-'){
		
	}
	break;
	}
}



int main(void){
	for(int i = 0 ; i < 6 ; i++){
		for(int j = 0 ; j < 3 ; j++){
			for(int k = 0 ; k < 3 ; k++){
				cube[i][j][k] = i;
			}
		}
	}
	int size;
	cin>>size;
	for(int i = 0 ; i < size ; i++){
		memcpy(cur,cube,sizeof(cube));
		int N;
		cin>>N;
		for(int j = 0 ; j < N ; j++){
			char dir,flag;
			cin>>dir>>flag;
			rotate(dir,flag);
			
		for(int row = 0 ; row < 3 ; row++){
			for(int col = 0 ; col < 3 ; col++){
				cout<<cur[2][row][col];
			}
			cout<<endl;
		}
		}

	}
}
