#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <cstdlib>
#include <algorithm>
using namespace std;

int compare(int A,int B){
	return A > B;
}

vector<int> solution(vector<string> operations) {
    vector<int> answer;
    deque<int> nums;
    for(int i = 0 ; i < operations.size(); i++){
		const char * str = operations[i].c_str();
		if(str[0] == 'I'){
			int num = atoi(str + 2);
			nums.push_back(num);
		}
		else if(str[0] == 'D'){
            if(nums.size() == 0) continue;
			sort(nums.begin(),nums.end(),compare);
			if(str[2] == '1') nums.pop_front();
			else if(str[2] == '-') nums.pop_back();
		}
	}
    if(nums.size() == 0){
		answer.push_back(0);
		answer.push_back(0);
	}
	else{
		sort(nums.begin(),nums.end(),compare);
		answer.push_back(nums[0]);
		answer.push_back(nums[nums.size() - 1]);
	}
    return answer;
}

int main(void)
{
	vector<string> o{"I -45", "I 653", "D 1", "I -642", "I 45", "I 97", "D 1", "D -1", "I 333"};
	vector<int> a = solution(o);
	cout<<a[0]<<" "<<a[1]<<endl;
}
