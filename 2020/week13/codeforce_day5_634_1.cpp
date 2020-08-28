#include <iostream>
#include <vector>
#include <queue>
using namespace std;


int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		int N;
		cin>>N;
		if(N  % 2 == 0){
			cout<<N/2 - 1<<endl;
		}
		else{
			cout<<N/2<<endl;
		}
	}
}
