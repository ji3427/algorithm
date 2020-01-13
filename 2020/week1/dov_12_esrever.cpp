#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	char str[30];
	while((cin>>str)){
		for(int i = strlen(str)-1 ; i >= 0 ; i--){
			cout<<str[i];
		}
		cout<<" ";
	}
}
