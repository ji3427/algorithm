#include <iostream>
#include <string.h>
using namespace std;

bool n[11];
char num[11];
int main(void)
{
	cin>>num;
	for(int i = 0 ; i < strlen(num) ; i++){
		n[num[i] - '0'] = true;
	}
	for(int i = 1 ; i <= strlen(num) ; i++){
		if(n[i] == false){
			cout<<"no";
			return 0;
		}
	}
	cout<<"yes";
	return 0;
}
