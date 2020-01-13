#include <iostream>
#include <string.h>
using namespace std;

int main(void)
{
	char str[256];
	while(1){
		char * offset;
		memset(str,0,sizeof(str));
		cin.getline(str,100);
		if(cin.eof() == true){
			break;
		}
		while((offset = strstr(str,"FOO")) != NULL){
			offset[0] = 'O';
			offset[1] = 'O';
			offset[2] = 'F';
		}
		cout<<str<<endl;
	}
}
