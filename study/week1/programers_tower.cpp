#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;



vector<int> solution(vector<int> heights) {
    vector<int> answer;
    while(!heights.empty()){
		int index = heights.size();
		int H = heights.back();
		vector<int> temp = heights;
		while(!temp.empty() && temp.back() <= H){
			temp.pop_back();
			index--;
		}
		answer.push_back(index);
		heights.pop_back();
	}
	reverse(answer.begin(),answer.end());
    return answer;
}


int main(void){
	vector<int> h = {6,9,5,7,4};
	for(auto i : solution(h)){
		cout<<i<<" "<<endl;
	}
}
