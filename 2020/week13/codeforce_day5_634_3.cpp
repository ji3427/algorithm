#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>
#include <map>
#include <math.h>

using namespace std;

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		int size;
		cin>>size;
		map<int,int> m;
		for(int i = 0 ; i < size ; i++){
			int num;
			cin>>num;
			if(m.find(num) == m.end()) m.insert(make_pair(num,1));
			else m[num]++;
		}
		map<int,int> ::iterator it = m.begin();
		int max_N = 0;
		for(; it != m.end() ; it++){
			if(it->second > max_N) max_N = it->second;
		}
		if(max_N == (int)m.size()){
			cout<<m.size() - 1<<endl;
		}
		else if(max_N > (int)m.size()){
			cout<<m.size()<<endl;
		}
		else{
			cout<<max_N<<endl;
		}
	}
}
