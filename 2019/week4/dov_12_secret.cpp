#include <iostream>
#include <string.h>
using namespace std;
char alph[8][7] = {"000000","001111","010011","011100","100110","101001","110101","111010"};
int diffSize(char *e1, char *e2){
	int size = 0;
	if(strcmp(e1,e2) == 0) return 0;
	for(int i = 0 ; i < 6 ; i++){
		if(e1[i] != e2[i]) size++;
	}
	return size;
}

int main(void)
{
	int size;
	cin>>size;
	char num[7];
	num[6] = '\0';
	char exp[100];
	cin>>exp;
	char ans[10];
	ans[size]='\0';
	memset(ans,0,10);
	for(int i = 0 ; i < size ; i++){
		strncpy(num,exp+i*6,6);
		for(int j = 0 ; j < 8 ; j++){
			int d = diffSize(num,alph[j]);
			if(d == 0){ans[i] = 'A'+j; continue;}
			else if(d == 1){ans[i] = 'A'+j; continue;}
		}
		if(ans[i] == 0) {cout<<i+1;goto END;}
	}
	printf("%s\n",ans);
	END:
	return 0;
}


