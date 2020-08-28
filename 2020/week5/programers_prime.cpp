#include <iostream>
#include <string>
#include <vector>

using namespace std;

void swapnum(vector<int>& v,int index1,int index2){
	int temp = v[index1];
	v[index1] = v[index2];
	v[index2] = temp;
}

int solution(string numbers) {
    int answer = 0;
    vector<int> num;
    for(int i = 0 ; i < numbers.length() ; i++) num.push_back(numbers[i] - '0');
    for(int i = 0 ; i < num.size() ; i++){
		swap(num,0,i);
		
	}
    return answer;
}


int 
