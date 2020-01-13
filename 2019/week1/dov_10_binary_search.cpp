#include <iostream>

using namespace std;

void sol(int min,int max,int N){
	if(N < 0 ) return;
	if(min == 0 && N ==0){ cout<<"max" << max<<endl;}
	sol(2*min - max -2 , max,N-1);
	sol(2*min - max -3 , max,N-1);
	sol(min,max*2 - min + 2,N-1);
	sol(min,max*2 - min + 1,N-1);
}

int main(void)
{
	int k,L;
	cin>>k>>L;
	for(int i = 1 ; i <= k ; i++){
		sol(k-i,k+1,L);
	}
}


