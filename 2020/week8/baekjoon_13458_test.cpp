#include <iostream>
#include <vector>
#include <deque>
#include <string.h>
#include <algorithm>
#include <utility>
#define ll long long
using namespace std;
ll ans;
int main(void){
	int N;
	vector<int> cl;
	int B,C;
	cin>>N;
	ans = N;
	for(int i = 0 ; i < N ; i++){
		int temp;
		cin>>temp;
		cl.push_back(temp);
	}
	cin>>B>>C;
	for(auto &i : cl) i -= B;
	for(auto i : cl){
		if(i <= 0) continue;
		ans = ans + (((i-1) / C) + 1);
	} 
	cout<<ans<<endl;
}
