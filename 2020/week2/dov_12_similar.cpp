#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;

char alph[26];
int main(void)
{
	char firstword[10];
	int size;
	cin>>size;
	cin>>firstword;
	int ans = 0;
	memset(alph,0,sizeof(alph));
	for(int i = 0 ; i < strlen(firstword) ; i++){
		alph[firstword[i] -'A']++;
	}
	for(int i = 0 ; i < size - 1 ; i++){
		char word[11];
		char alphcopy[26];
		int wrong = 0;
		memcpy(alphcopy,alph,sizeof(alph));
		cin>>word;
		for(int i = 0 ; i < strlen(word) ; i++){
			alphcopy[word[i] -'A']--;
			if(alphcopy[word[i] -'A'] < 0) wrong++;
		}
		int diff = strlen(firstword) - strlen(word);
		if(diff > 0)wrong += abs(diff);
		if(wrong < 2) ans++;
	}
	cout<<ans;
}
