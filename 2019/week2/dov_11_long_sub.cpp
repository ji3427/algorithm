#include <iostream>
#include <list>
#include <string.h>
#include <cstdlib>
using namespace std;

char num1[101];
char num2[101];
list<char*> nl1;
list<char*> nl2;
list<int> ans;
char * temp;
bool minu;
int main(void)
{
	minu = false;
	int index;
	cin>>num1>>num2;
	if(strlen(num1) <10 && strlen(num2) < 10){
		cout<<atoi(num1)-atoi(num2)<<endl;
		return 0;
	}
	int idx = strlen(num1) - 8;
	while(1){
		if(idx > 0){
		temp = (char*)malloc(sizeof(char) * 9);
		strncpy(temp,num1+idx,8);
		temp[8] = '\0';
		idx -=  8;
		nl1.push_back(temp);
	}
		if(idx < 0){
			temp = temp = (char*)malloc(sizeof(char) * 9);
			strncpy(temp,num1,8 + idx);
			temp[8+idx] = '\0';
			nl1.push_back(temp);
			break;
		}
	}
	idx = strlen(num2) - 8;
	while(1){
		if(idx>0){
		temp = (char*)malloc(sizeof(char) * 9);
		strncpy(temp,num2+idx,8);
		temp[8] = '\0';
		idx -=  8;
		nl2.push_back(temp);
	}
		if(idx < 0){
			temp = temp = (char*)malloc(sizeof(char) * 9);
			strncpy(temp,num2,8 + idx);
			temp[8+idx] = '\0';
			nl2.push_back(temp);
			break;
		}
	}
	if(nl1.size() < nl2.size()){
		minu = true;
	}
	else if((nl1.size() == nl2.size()) && atoi(nl1.back())< atoi(nl2.back())) minu = true;
	list<char*>::iterator big_s;
	list<char*>::iterator big_e;
	list<char*>::iterator small_s;
	list<char*>::iterator small_e;
	if(minu == true){
		big_s = nl2.begin();
		big_e = nl2.end();
		small_s = nl1.begin();
		small_e = nl1.end();
	}
	else{
		big_s = nl1.begin();
		big_e = nl1.end();
		small_s = nl2.begin();
		small_e = nl2.end();
	}
	int num;
	while(1){
		if(big_s == big_e || small_s == small_e) break;
		num = atoi(*big_s) - atoi(*small_s);
		if(num < 0){
			big_s++;
			*big_s -=1;
			big_s--;
			num = 100000000 + num;
		}
		ans.push_front(num);
		big_s++;
		small_s++;
	}
	while(big_s != big_e){ans.push_front(atoi(*big_s)); big_s++;}
	while(small_s != small_e){ans.push_front(atoi(*small_s)); small_s++;}
	if(minu){
		cout<<"-";
	}
	cout<<ans.front();
	list<int>::iterator ai = ans.begin();
	ai++;
	for(; ai != ans.end(); ai++){
		printf("%08d",*ai);
	}
	return 0;
}
