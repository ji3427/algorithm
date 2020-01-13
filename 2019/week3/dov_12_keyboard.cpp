#include <iostream>
#include <string.h>

using namespace std;

int times[1000];
int main(void)
{
	char temp;
	int s,e;
	int max = -1;
	int size;
	memset(times,0,sizeof(times));
	cin>>size;
	for(int i = 0 ; i < size ; i ++){
		cin>>temp>>s>>e;
		for(int j = s ; j < e ; j++) times[j]++;
		if(max < e) max = e;
	}
	for(int i = 0 ; i < max ; i++){
		if(times[i] > 0) printf("%c",times[i] + 'A' - 1);
	}
}
