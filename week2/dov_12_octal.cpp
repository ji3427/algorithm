#include <iostream>
#include <string.h>

using namespace std;

char cmp(char * target){
	if(strcmp(target,"000") == 0) return '0';
	else if(strcmp(target,"001") == 0) return '1';
	else if(strcmp(target,"010") == 0) return '2';
	else if(strcmp(target,"011") == 0) return '3';
	else if(strcmp(target,"100") == 0) return '4';
	else if(strcmp(target,"101") == 0) return '5';
	else if(strcmp(target,"110") == 0) return '6';
	else if(strcmp(target,"111") == 0) return '7';
}


int main(void)
{
	 char num[102];
	 cin>>num;
	 char target[4];
	 target[3] = '\0';
	 memset(target,0,sizeof(target));
	 char ans[50];
	 int index = 0;
	 int ans_index = 0;
	 if(strlen(num) % 3 == 1){
		 target[0] = '0';
		 target[1] = '0';
		 target[2] = num[index++];
		 ans[ans_index++] = cmp(target);
	 }
	 else if(strlen(num) % 3 == 2){
		 target[0] = '0';
		 target[1] = num[index++];
		 target[2] = num[index++];
		 ans[ans_index++] = cmp(target);
	 }
	 while(index < strlen(num)){
		 for(int i = 0 ; i < 3 ; i++){
			 target[i] = num[index++];
		 }
		 ans[ans_index++] = cmp(target);
	 }
	 ans[ans_index] = '\0';
	 cout<<ans<<endl;
}


