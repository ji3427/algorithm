#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

bool compareL(int A,int B){
	return A < B;
}
bool compareB(int A,int B){
	return A > B;
}

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		int N,K;
		int answer = 0;
		cin>>N>>K;
		vector<int> a;
		vector<int> b;
		for(int i = 0 ;  i < N ; i++){
			int temp;
			cin>>temp;
			a.push_back(temp);
		}
		for(int i = 0 ;  i < N ; i++){
			int temp;
			cin>>temp;
			b.push_back(temp);
		}
		sort(a.begin(),a.end(),compareL);
		sort(b.begin(),b.end(),compareB);
		int index = 0;
		for( ; index< K ; index++){
			if(a[index] >= b[index]) break;
			answer += b[index];
		}
		for(;index < N ; index++) answer += a[index];
		cout<<answer<<endl;
	}
}
