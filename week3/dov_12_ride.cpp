#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	char str1[10];
	char str2[10];
	cin>>str1>>str2;
	int num1 = 1;
	int num2 = 1;
	for(int i = 0 ; i < strlen(str1) ; i++){
		num1 *= (str1[i] - 'A' + 1);
	}
	for(int i = 0 ; i < strlen(str2) ; i++){
		num2 *= (str2[i] - 'A' + 1);
	}
	num1 %= 47;
	num2 %= 47;
	if(num1 == num2) cout<<"GO";
	else cout<<"STAY";	
}
