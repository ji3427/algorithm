#include <iostream>
#include <string.h>

using namespace std;
char src[30];

int main(void){
	cin>>src;
	for(int i = 0 ; i < strlen(src) ; i++){
		if(src[i] == 'q' || src[i] == 'Q') cout<<src<<endl;
		if(src[i] == 'h' || src[i] == 'H') cout<<"Hello, world!"<<endl;
		else if(src[i] == '9')cout<<"99 Bottles of Beer on the Wall"<<endl;
	}
}
