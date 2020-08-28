#include <iostream>
#include <vector>

using namespace std;

int main(void){
	int tc;
	cin>>tc;
	int n;
	for(int t = 0 ; t < tc ; t++){
		cin>>n;
		if((n/2) % 2 != 0) {cout<<"NO"<<endl; continue;}
		else{
			cout<<"YES"<<endl;
			for(int i = 1 ; i <= n / 2 ; i++){
				cout<<i * 2<<" ";
			}
			for(int i = 0 ; i < n / 2 - 1 ; i++){
				cout<<i*2+1<<" ";
			}
			cout<< n + (n/2) - 1<<endl; 
		}
	}
}
