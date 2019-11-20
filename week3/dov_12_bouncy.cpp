#include <iostream>
#include <string.h>
using namespace std;



void judge(char * str,int start,int flag){
	int i;
	for(i = start ; i < strlen(str) - 1; i++){
		if(flag == 1 && str[i] > str[i+1]) {cout<<"bouncy"<<endl; break;}
		else if(flag == -1 && str[i] < str[i+1]) {cout<<"bouncy"<<endl; break;}
	}
	if(i == strlen(str) - 1) {cout<<"no bouncy"<<endl;}
}
int main(void)
{
	char str[10];
	int flag = 0; //1이면 증가 -1이면 감소,
	while(1){
		cin>>str;
		if(strcmp(str,"0") == 0) break;
		int i;
		for(i = 0 ; i < strlen(str) -1 ; i++){
			if(str[i] > str[i+1]) {flag = -1; break;}
			else if(str[i] < str[i+1]) {flag = 1; break;}
			else continue;
		}
		if(i == strlen(str) - 1) {cout<<"no bouncy"<<endl; continue;}
		judge(str,i,flag);
		memset(str,0,sizeof(str));		
	}
}
