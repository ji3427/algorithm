#include <iostream>
#include <string.h>

using namespace std;

bool cup[3];
char str[100];
int main(void)
{
	cup[0] = true;
	cup[1] = false;
	cup[2] = false;
	cin>>str;
	for(int i = 0 ; i < strlen(str) ; i++){
		if(str[i] == 'A' && (cup[0] == true || cup[1] == true )) {cup[0] ^= true;cup[1] ^= true;}
		else if(str[i] == 'B' && (cup[1] == true || cup[2] == true )){cup[1] ^= true;cup[2] ^= true;}
		else if(str[i] == 'C' &&(cup[0] == true || cup[2] == true )){cup[0] ^= true;cup[2] ^= true;}
	}
	if(cup[0]) cout<<1;
	if(cup[1]) cout<<2;
	if(cup[2]) cout<<3;
}
