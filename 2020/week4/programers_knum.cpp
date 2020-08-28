#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int compare(int A, int B){
	return A < B;
}

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
    vector<int> answer;
    vector<int> subarray;
    for(int i = 0 ; i < commands.size() ; i++){
		subarray.clear();
		int s,e,k;
		s = commands[i][0];
		e = commands[i][1];
		k = commands[i][2];
		subarray.assign(array.begin()+s - 1,array.begin()+e);
		sort(subarray.begin(),subarray.end(),compare);
		answer.push_back(subarray[k-1]);
	}
    return answer;
}


int main(void){
	vector<int> a{1,5,2,6,3,7,4};
	vector<vector<int>> c{{2,5,3},{4,4,1},{1,7,3}};
	vector<int> ans = solution(a,c);
	for(auto i : ans)
		cout<<i<<" ";
	cout<<endl;
}
