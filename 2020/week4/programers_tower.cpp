#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;


queue<int> st;
vector<int> solution(vector<int> heights) {
    vector<int> answer;
    vector<int> pop_num;
    for(int i = 0 ; i < heights.size() ; i++){
		st.push(heights[i]);
	}
	while(!st.empty()){
		int num = st.front();
		cout<<num<<" ";
		int count = 0;
		for(int i = 0 ; i < pop_num .size(); i++){
			if(num < pop_num[i]) {count = i+1}
		}
		st.pop();
		pop_num.push_back(num);
		answer.push_back(count);
		cout<<endl;
		}
    return answer;
}

int main(void)
{
	vector<int> t {6,9,5,7,4};
	for(auto i : solution(t))
		cout<<i<<endl;
	
}
