#include <iostream>
#include <vector>
#include <set>
#include <stdio.h>
#include <string.h>
#include <math.h>
using namespace std;

vector<vector<int>> gear(4);
int isrotate[4];

void rotate(int n){
	int temp = gear[n][7];
	for(int i = 6 ; i >= 0 ; i--){
		gear[n][i+1] = gear[n][i];
	}
	gear[n][0] = temp;
}
void rotateR(int n){
	int temp = gear[n][0];
	for(int i = 0 ; i < 7 ; i++){
		gear[n][i] = gear[n][i+1];
	}
	gear[n][7] = temp;
}

void getrotete(int n,int d){
	if(n == 0){
		isrotate[0] = d;
		if(gear[0][2] == gear[1][6]) isrotate[1] = 0;
		else {
			if(isrotate[0] == 1) isrotate[1] = -1;
			else if(isrotate[0] == -1) isrotate[1] = 1;
		}
		if(gear[1][2] == gear[2][6]) isrotate[2] = 0;
		else {
			if(isrotate[1] == 1) isrotate[2] = -1;
			else if(isrotate[1] == -1) isrotate[2] = 1;
		}
		if(gear[2][2] == gear[3][6]) isrotate[3] = 0;
		else {
			if(isrotate[2] == 1) isrotate[3] = -1;
			else if(isrotate[2] == -1) isrotate[3] = 1;
		}
	}
	else if(n == 1){
		isrotate[1] = d;
		if(gear[0][2] == gear[1][6]) isrotate[0] = 0;
		else {
			if(isrotate[1] == 1) isrotate[0] = -1;
			else if(isrotate[1] == -1) isrotate[0] = 1;
		}
		if(gear[1][2] == gear[2][6]) isrotate[2] = 0;
		else {
			if(isrotate[1] == 1) isrotate[2] = -1;
			else if(isrotate[1] == -1) isrotate[2] = 1;
		}
		if(gear[2][2] == gear[3][6]) isrotate[3] = 0;
		else {
			if(isrotate[2] == 1) isrotate[3] = -1;
			else if(isrotate[2] == -1) isrotate[3] = 1;
		}
	}
	else if(n == 2){
		isrotate[2] = d;
		if(gear[1][2] == gear[2][6]) isrotate[1] = 0;
		else {
			if(isrotate[2] == 1) isrotate[1] = -1;
			else if(isrotate[2] == -1) isrotate[1] = 1;
		}
		if(gear[0][2] == gear[1][6]) isrotate[0] = 0;
		else {
			if(isrotate[1] == 1) isrotate[0] = -1;
			else if(isrotate[1] == -1) isrotate[0] = 1;
		}
		if(gear[2][2] == gear[3][6]) isrotate[3] = 0;
		else {
			if(isrotate[2] == 1) isrotate[3] = -1;
			else if(isrotate[2] == -1) isrotate[3] = 1;
		}		
	}
	else if(n == 3){
		isrotate[3] = d;
		if(gear[2][2] == gear[3][6]) isrotate[2] = 0;
		else {
			if(isrotate[3] == 1) isrotate[2] = -1;
			else if(isrotate[3] == -1) isrotate[2] = 1;
		}	
		if(gear[1][2] == gear[2][6]) isrotate[1] = 0;
		else {
			if(isrotate[2] == 1) isrotate[1] = -1;
			else if(isrotate[2] == -1) isrotate[1] = 1;
		}
		if(gear[0][2] == gear[1][6]) isrotate[0] = 0;
		else {
			if(isrotate[1] == 1) isrotate[0] = -1;
			else if(isrotate[1] == -1) isrotate[0] = 1;
		}
	}

}

void de(){
		for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			cout<<gear[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}


int main(void)
{
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 8 ; j++){
			int num ;
			scanf("%1d",&num);
			if(abs(num) < 2) gear[i].push_back(num);
		}
	}
	int c;
	cin>>c;
//	de();
	for(int i = 0 ; i < c ; i++){
		int n,d;
		cin>>n>>d;
		memset(isrotate,0,sizeof(isrotate));
		getrotete(n-1,d);
		for(int i = 0 ; i < 4 ; i++){
			if(isrotate[i] == 0) continue;
			else if(isrotate[i] == 1) rotate(i);
			else if(isrotate[i] == -1) rotateR(i);
		}
//		de();
	}
	int ans = 0;

	for(int i = 0 ; i < 4 ;i++){
		if(gear[i][0] == 1) ans += pow(2,i);
	}
	
//	cout<<endl;
	cout<<ans;
}
