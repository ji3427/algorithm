#include <iostream>
#include <string>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

struct node{
	int stime;
	int usetime;
};

struct comp{
	bool operator()(node A, node B){
		return A.usetime > B.usetime;
	}
};

int compare(vector<int> A,vector<int> B){
	if(A[0] == B[0]){
		return A[1] < B[1];
	}
	else
		return A[0] < B[0];
}

int solution(vector<vector<int>> jobs) {
    int answer = 0;
    priority_queue<node,vector<node>,comp> pq;
    int index = 0;
    int ctime = 0;
    sort(jobs.begin(),jobs.end());
    while(1){
		if(index == jobs.size() && pq.empty()) break;
		while(index < jobs.size()&&jobs[index][0] <= ctime){
			struct node n;
			n.stime = jobs[index][0];
			n.usetime = jobs[index][1];
			pq.push(n);
			index++;
		}
		if(pq.empty()){
			ctime = jobs[index][0] + jobs[index][1];
			answer += (ctime - jobs[index][0]);
			index++;
		}
		else{
			node n = pq.top();
			ctime += n.usetime;
			answer += (ctime - n.stime);
			pq.pop();
		}
	}
	answer /= jobs.size();
    return answer;
}

int main(void)
{
	vector<vector<int>> j = {{24, 10}, {18, 39}, {34, 20}, {37, 5}, {47, 22}, {20, 47}, {15, 2}, {15, 34}, {35, 43}, {26, 1}};
	cout<<solution(j);
}
