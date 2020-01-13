#include <iostream>
#include <string.h>
using namespace std;

char str[1000];
int main(void){
	cin.getline(str,1000);
	for(int i = strlen(str)-1 ; i >= 0 ; i--){
		if(str[i] == ' ' ) continue;
		cout<<str[i];
	}
	cout<<endl;
}
