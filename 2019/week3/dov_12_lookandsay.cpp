#include <iostream>
#include <string.h>
using namespace std;

char str[10000];
int main(void)
{
	cin>>str;
	int num = str[0] - '0';
	int count = 1;
	for(int i = 1 ; i < strlen(str) ; i++){
		if(num == str[i] - '0'){
			count++;
		}
		else{
			cout<<count<<num;
			num = str[i] - '0';
			count = 1;
		}
	}
	cout<<count<<num;
}
