#include <iostream>
#include <string.h>
#include <cstdio>
char str[100];
char alph[27];

//대문자 소문자 차이 32

using namespace std;

int main(void)
{
	cin.getline(alph,27);
	//cin.ignore();
	cin.getline(str,100);
	for(int i = 0 ; i < strlen(str) ; i++){
		if(str[i] >= 'A' && str[i] <='Z'){
			str[i] += 32;
			str[i] = alph[str[i] - 'a'] - 32;
		}
		else if( str[i] >= 'a' && str[i] <= 'z'){
			str[i] = alph[str[i] - 'a'];
		}
		else{
			continue;
		}
	}
	cout<<str<<endl;
}
