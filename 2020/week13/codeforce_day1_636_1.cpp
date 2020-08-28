#include <iostream>
#include <vector>
#include <math.h>
using namespace std;

long long arr[32];

int main(void){
	int tc;
	cin>>tc;
	arr[0] = 1;
	for(int i = 1 ; i < 32 ; i++){
		arr[i] = arr[i-1] + pow(2,i);
	}
	for(int t = 0 ; t < tc ; t++){
		long long n;
		cin>>n;
		int index = 1;
		while(n > arr[index]){
			if(n % arr[index] == 0) break;
			index++;
		}
		cout<<n / arr[index]<<endl;
	}
}
