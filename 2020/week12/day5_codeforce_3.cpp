#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		long long N;
		cin>>N;
		long long answer = 0;
		long long index = 1;
		N = N*N -1;
		while(N > 0){
			N -= (index*8);
			answer += (index * index*8);
			index++;
		}
		cout<<answer<<endl;
	}
}
