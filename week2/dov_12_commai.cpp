#include <iostream>
#include <string.h>

using namespace std;

char num[100];
char ans[200];
int main(void)
{
	cin>>num;
	int index = 0;
	if(strlen(num) < 4) {cout<<num; return 0;}
	for(int i = strlen(num) -1 ; i >= 0 ; ){
		for(int j = 0 ; j < 3 ; j++){
			if(i < 0) break;
			ans[index++] = num[i--];
		}
		ans[index++] = ',';
	}
	for(int i = index -2 ; i >= 0 ; i--){
		cout<<ans[i];
	}
}
