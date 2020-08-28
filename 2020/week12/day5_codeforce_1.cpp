#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		long long N,M;
		cin>>N>>M;
		if(N <= 1) cout<<0<<endl; 
		else if(N <= 2) cout<<M<<endl;
		else if(N > 2) cout<<M *2<<endl;
	}
}
