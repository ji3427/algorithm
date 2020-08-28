#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <set>
#include <utility>

using namespace std;

vector<pair<int,int>> m;

string solution(vector<int> numbers, string hand) {
    string answer = "";
    int cur_L,cur_R;
    m.push_back(make_pair(3,1));
    m.push_back(make_pair(0,0));
    m.push_back(make_pair(0,1));
    m.push_back(make_pair(0,2));
    m.push_back(make_pair(1,0));
    m.push_back(make_pair(1,1));
    m.push_back(make_pair(1,2));
    m.push_back(make_pair(2,0));
    m.push_back(make_pair(2,1));
    m.push_back(make_pair(2,2));
    m.push_back(make_pair(3,0)); //*
    m.push_back(make_pair(3,2)); //#
    cur_L = 10;
    cur_R = 11;
    for(int i = 0 ; i < numbers.size() ; i++){
		if(numbers[i] == 1 || numbers[i] == 4 || numbers[i] == 7){
			cur_L = numbers[i];
			answer.push_back('L');
		}
		else if(numbers[i] == 3 || numbers[i] == 6 || numbers[i] == 9){
			cur_R = numbers[i];
			answer.push_back('R');
		}
		else{
			if(abs(m[cur_L].first - m[numbers[i]].first) + abs(m[cur_L].second - m[numbers[i]].second) < abs(m[cur_R].first - m[numbers[i]].first) + abs(m[cur_R].second - m[numbers[i]].second)){
				cur_L = numbers[i];
				answer.push_back('L');
			}
			else if(abs(m[cur_L].first - m[numbers[i]].first) + abs(m[cur_L].second - m[numbers[i]].second) > abs(m[cur_R].first - m[numbers[i]].first) + abs(m[cur_R].second - m[numbers[i]].second)){
				cur_R = numbers[i];
				answer.push_back('R');			
			}
			else{
				if(hand == "right"){
					cur_R = numbers[i];
					answer.push_back('R');					
				}
				else if(hand == "left"){
					cur_L = numbers[i];
					answer.push_back('L');
				} 
			}
		}
	}
    return answer;
}


int main(void){
	vector<int> a = {1, 3, 4, 5, 8, 2, 1, 4, 5, 9, 5};
	string i = solution(a,"right");
	cout<<i<<endl;
}
