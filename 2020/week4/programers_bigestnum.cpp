#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int compare(string A, string B){
	int len = min(A.length(),B.length());
	for(int i = 0 ; i < len ; i++){
		if(A[i] == B[i]) continue;
		return A[i] > B[i];
	}
	string str1 = A.substr(A.length() - len);
	string str2 = B.substr(B.length() - len);
	return stoi(str1,nullptr,10) > stoi(str2,nullptr,10);
}



string solution(vector<int> numbers) {
    string answer = "";
    vector<string> nums;
    for(auto i : numbers)
		nums.push_back(to_string(i));
	sort(nums.begin(),nums.end(),compare);
	for(auto i : nums)
		answer.append(i);
    return answer;
}

int main(void){
	vector<int> n{3,30,34};
	cout<<solution(n);
}
