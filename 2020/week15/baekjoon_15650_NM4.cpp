#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;

vector<int> ans;

void getarray(int size, int start,int total){
	if(ans.size() == size){
		for(auto i : ans) cout<<i<<" ";
		cout<<endl;
		return;
	}
	for(int i = start ; i < total ; i++){
			ans.push_back(i+1);
			getarray(size,i,total);
			ans.pop_back();
	}
}



int main(void){
	int size,num;
	cin>>size>>num;
	getarray(num,0,size);
}
