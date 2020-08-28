#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> answers) {
    vector<int> answer;
    int p1[5] = {1,2,3,4,5};
    int p2[8] = {2,1,2,3,2,4,2,5};
    int p3[10] = {3,3,1,1,2,2,4,4,5,5};
    int p1_ans = 0;
    int p2_ans = 0;
    int p3_ans = 0;
    for(int = 0 ; i < answers.size() ; i++){
		if(answers[i] == p1[i%5]) p1_ans++;
		if(answers[i] == p2[i%8]) p2_ans++;
		if(answers[i] == p3[i%10]) p3_ans++;
	}
	int mx = max({p1_ans,p2_ans,p3_ans});
	if(mx == p1_ans) answer.push(1);
	if(mx == p2_ans) answer.push(2);
	if(mx == p3_ans) answer.push(3);
    return answer;
}
