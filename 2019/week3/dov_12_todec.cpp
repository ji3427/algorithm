#include <iostream>
#include <string.h>
#include <math.h>

using namespace std;

char str[30];
int main(void){
	int ans = 0;
	cin>>str;
	for(int i = 0 ; i < strlen(str) ; i++){
		ans += (str[i] - '0') * pow(2.0,strlen(str) - i - 1);
	}
	cout<<ans;
}
