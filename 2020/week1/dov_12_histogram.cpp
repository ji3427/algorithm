#include <iostream>
#include <string.h>

using namespace std;

int count[26];

int main(void)
{
	char str[80];
	int max = 0;
	for(int i = 0 ; i < 4 ; i++){
		memset(str,0,sizeof(str));
		cin.getline(str,72);
		//cout<<str<<endl;
		for(int i = 0 ; i < strlen(str) ; i++){
			if(str[i] >'Z' || str[i] < 'A') continue;
			count[str[i] - 'A']++;
			if(count[str[i] - 'A'] > max) max = count[str[i] - 'A'];
		}
	}
	for(int i = max ; i > 0 ; i--){
		for(int j = 0 ; j < 25 ; j++){
			if(count[j] >= i) cout<<"*"<<" ";
			else cout<<" "<<" ";
		}
		if(count[25] >= i) cout<<"*";
		else cout<<" ";
		cout<<endl;
	}
	for(int i = 0 ; i < 25 ; i++) printf("%c ",'A'+i);
	printf("Z");
}
