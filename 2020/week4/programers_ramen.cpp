#include <iostream>
#include <string>
#include <vector>
#include <queue>
using namespace std;

int solution(int stock, vector<int> dates, vector<int> supplies, int k) {
    int answer = 0;
    int date = 0;
    int index = 0;
    priority_queue<int,vector<int>,less<int>> pq;
    while(date < k){
		date += stock;
		while(dates[index] <= date){
			pq.push(supplies[index]);
			index++;
		}
		stock = pq.top();
		pq.pop();
		answer++;
	}
    return answer - 1;
}


int main(void)
{
	vector<int> d{4,10,15};
	vector<int> s{20,5,10};
	cout<<solution(4,d,s,30);
}
