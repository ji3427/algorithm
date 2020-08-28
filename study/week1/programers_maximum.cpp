#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(int A,int B){
	string str1 = to_string(A) + to_string(B);
	string str2 = to_string(B) + to_string(A);
	return stoi(str1) > stoi(str2);
}

string solution(vector<int> numbers) {
    string answer = "";
    sort(numbers.begin(),numbers.end(),compare);
    for(int i = 0 ; i < numbers.size() ; i++){
		answer += to_string(numbers[i]);
	}
    if(answer[0] == '0') answer = "0";
    return answer;
}
