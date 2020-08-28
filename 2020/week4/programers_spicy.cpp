#include <iostream>
#include <string>
#include <vector>
#include <queue>

using namespace std;

int solution(vector<int> scoville, int K) {
    int answer = 0;
    priority_queue<int,vector<int>,greater<int>>pq;
    for(int i = 0 ; i < scoville.size() ; i++){
		pq.push(scoville[i]);
	}
	while(pq.top() < K ){	
		int first,second;
		if(pq.size() < 2) return -1;
		first = pq.top();
		pq.pop();
		second = pq.top();
		pq.pop();
		pq.push(first + second*2);
		answer++;
	}
    return answer;
}

int main(void){
	vector<int> s{1,2,3,9,10,12};
	int K = 7;
	cout<<solution(s,K)<<endl;
}
