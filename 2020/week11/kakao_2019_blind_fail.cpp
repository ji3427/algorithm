#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <algorithm>
using namespace std;

multiset<int> s;

struct node{
	int index;
	double fail;
};

bool compare(node A,node B){
	if(A.fail == B.fail) return A.index < B.index;
	return A.fail > B.fail;
}

vector<int> solution(int N, vector<int> stages) {
    vector<int> answer;
    vector<node> ans;
    int total = stages.size();
    for(int i = 0 ; i < stages.size() ;i++){
		s.insert(stages[i]);
	}
	for(int i = 1 ; i <= N ; i++){
		node temp = {i,0};
		if(total != 0 )temp.fail =s.count(i) / (double)total;
		ans.push_back(temp);
		total -= s.count(i);
	}
	sort(ans.begin(),ans.end(),compare);
	for(int i = 0 ; i < ans.size() ; i++){
		cout<<ans[i].index<<" "<<ans[i].fail<<endl;
		answer.push_back(ans[i].index);
	}
    return answer;
}

int main(void){
	vector<int> s1 = {2, 1, 2, 6, 2, 4, 3, 3};
	vector<int> s2 = {4,4,4,4,4};
	vector<int> r1 = solution(5,s1);
	s.clear();
	vector<int> r2 = solution(4,s2);
	for(auto i : r1) cout<<i<<" ";
	cout<<endl;
	for(auto i : r2) cout<<i<<" ";
	cout<<endl;
	
}
