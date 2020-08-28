#include <iostream>

using namespace std;

int cents[4] = {25,10,5,1};
int ans[4] = {0,};
int main(void)
{
	int C;
	cin>>C;
	while(C > 0){
		if(C >= cents[0]) {ans[0]++; C -= cents[0];}
		else if(C >= cents[1]) {ans[1]++; C -= cents[1];}
		else if(C >= cents[2]) {ans[2]++; C -= cents[2];}
		else if(C >= cents[3]) {ans[3]++; C -= cents[3];}
	}
	cout<<ans[0]<<" QUARTER(S), "<<ans[1]<<" DIME(S), "<<ans[2]<<" NICKEL(S), "<<ans[3]<<" PENNY(S)"<<endl;
	
}
