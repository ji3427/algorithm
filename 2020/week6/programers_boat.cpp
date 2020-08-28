#include <iostream>
#include <string>
#include <vector>
#include <deque>
#include <algorithm>
using namespace std;

int solution(vector<int> people, int limit) {
    int answer = 0;
    deque<int> person;
    for(int i = 0 ; i < people.size() ; i++) person.push_back(people[i]);
    sort(person.begin(),person.end());
    int sum =  0;
    while(!person.empty()){
		if(!person.empty()&&sum + person.back() <= limit){
			sum += person.back();
			person.pop_back();
		}
		if(!person.empty()&&sum + person.front() <= limit){
			sum += person.front();
			person.pop_front();
		}
		else{
			sum = 0;
			answer++;
		}
	}
	if(sum == 0) return answer;
    return answer+1;
}

int main(void)
{
	vector<int> p{100,70,80,50,20,30,30};
	cout<<solution(p,100);
}
