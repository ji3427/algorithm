#include <iostream>
#include <string>
#include <vector>
#include <map>
using namespace std;


int* itoarr(int num){
	int * arr = (int*)malloc(sizeof(int)*3);
	int index = 2;
	while(num != 0){
		arr[index] = num % 10;
		num /= 10;
		index--;
	}
	return arr;
}


int solution(vector<vector<int>> baseball) {
	int * num;
	int answer = 0;
	for(int i = 123 ; i <= 987 ;i++){
		num = itoarr(i);
		int count = 0;
		if(!num[1] || !num[2] || num[0] == num[1] || num[1] == num[2] || num[2] == num[0]) continue;
		for(int j = 0 ; j < baseball.size() ; j++){
			int * temp = itoarr(baseball[j][0]);
			int strike = 0;
			int ball = 0;
			for(int k = 0 ; k < 3 ; k++){
				if(num[k] == temp[k]) strike++;
				if(num[k] == temp[(k+1) % 3] || num[k] == temp[(k+2) % 3]) ball++;
			}
			if(strike == baseball[j][1] && ball == baseball[j][2])
				count++;
		}
		if(count == baseball.size()) answer++;
	}
    return answer;
}





int main(void)
{
	vector<vector<int>> a {{123,1,1},{356,1,0},{327,2,0},{489,0,1}};
	cout<<solution(a);
}
