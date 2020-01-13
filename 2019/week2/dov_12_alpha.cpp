#include <iostream>

using namespace std;

int main(void){
	char str[3];
	for(char i = 'A' ; i <= 'Z' ; i++){
		str[0] = i;
		for(char j = 'A' ; j <= 'Z' ; j++){
			str[1] = j;
			for(char k = 'A' ; k <= 'Z' ; k++){
				str[2] = k;
				cout<<str<<" ";
			}
		}
	}
}
