#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <deque>
#include <set>

using namespace std;

long long calc(deque<long long> nums,deque<char> op,vector<char> priority){
	for(int i = 0 ; i < 3 ; i++){
		deque<long long> tempN;
		deque<char> tempO;
		tempN.push_back(nums.front());
		nums.pop_front();
		while(!op.empty()){
			if(op.front() == priority[i]){
				long long N;
				if(op.front() == '-') N = tempN.back() - nums.front();
				else if(op.front() == '*') N = tempN.back() * nums.front();
				else if(op.front() == '+') N = tempN.back() + nums.front();
				tempN.pop_back();
				tempN.push_back(N);
				nums.pop_front();
				op.pop_front();
			}
			else{
				tempN.push_back(nums.front());
				nums.pop_front();
				tempO.push_back(op.front());
				op.pop_front();
			}
		}
		nums = tempN;
		op = tempO;
	}
	return nums[0];
}


long long solution(string expression) {
    long long answer = 0;
    int before = 0;
    deque<long long> n;
    deque<char> o;
    for(int i = 0 ; i < expression.size() ; i++){
		if(expression[i] == '+' || expression[i] == '*' || expression[i] == '-'){
			o.push_back(expression[i]);
			string s = expression.substr(before,i-before);
			n.push_back(stoi(s));
			before = i + 1;
		}
	}
	string s = expression.substr(before,expression.size() - 1);
	n.push_back(stoi(s));
	vector<char> p;
	vector<char> ops;
	ops.push_back('*');
	ops.push_back('-');
	ops.push_back('+');
	sort(ops.begin(),ops.end());
	do{
		p.clear();
		for(int i=0; i<ops.size(); i++){
			p.push_back(ops[i]);
		}
		long long a = abs(calc(n,o,p));
		if(answer < a) answer = a;
	} while(next_permutation(ops.begin(), ops.end()));
    return answer;
}

int main(void){
	cout<<solution("50*6-3*2");
}
