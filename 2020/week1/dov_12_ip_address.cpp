#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

char str[35];
int bitodsc(char * pos);
int main(void)
{
	cin>>str;
	char * pos = str;
	for(int i = 0 ; i < 3 ; i++){
		cout<<bitodsc(pos);
		cout<<".";
		pos+=8;
	}
	cout<<bitodsc(pos);
}

int bitodsc(char * pos){
	int num = 0;
	for(int i = 0 ; i < 8 ; i++){
		int temp = (*pos) - '0';
		temp = temp * pow(2.0,(double)(7-i));
		num += temp;
		pos++;
	}
	return num;
}
