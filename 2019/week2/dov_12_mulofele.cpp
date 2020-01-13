#include <iostream>
#include <string.h>
using namespace std;

char num[320];

int main(void)
{
	cin>>num;
	int even = 0;
	int odd = 0;
	for(int i = 0 ; i < strlen(num) ; i++){
		if(i%2 == 0) even += (num[i] - '0');
		else odd += (num[i] - '0');
	}
	abs(odd - even) % 11 ==0 ? cout<<"yes" : cout<<"no";
}
