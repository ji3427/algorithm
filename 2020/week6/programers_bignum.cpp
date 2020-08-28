#include <iostream>
#include <string>
#include <vector>

using namespace std;

int getmax(int s,int e,string number){
	int max = -1;
	int index;
	for(int i = s ; i <= e ; i++){
		if(number[i] - '0' > max){
			max = number[i] -'0';
			if(max == 9) return i;
			index = i;
		}
	}
	return index;
}


string solution(string number, int k) {
    string answer = "";
    int size = number.length() - k;
    int start = 0;
    while(k < number.length()){
		answer.push_back(number[getmax(start,k,number)]);
		start = getmax(start,k,number) + 1;
		k++;
	}
    return answer;
}

int main(void){
	cout<<solution("23",1);
}
