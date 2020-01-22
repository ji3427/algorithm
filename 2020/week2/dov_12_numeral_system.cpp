#include <iostream>
#include <string.h>
#include <map>
using namespace std;

map<char,int> m;


int systodeci(char * sys){
	int sn = -1;
	int res = 0;
	for(int i = 0 ; i < strlen(sys);i++){
		if(sys[i] >= '0' && sys[i] <= '9') sn = sys[i] - '0';
		else{
			if(sn == -1){
				res += 1 * m[sys[i]];
			}
			else{
				res += sn * m[sys[i]];
				sn = -1;
			}
		}
	}
	return res;
}

void decitosys(int deci){
	if(deci / 1000 > 1){
		cout<<deci/1000<<"m";
	}
	else if(deci / 1000 == 1) cout<<"m";
	deci %= 1000;
	if(deci / 100 > 1){
		cout<<deci/100<<"c";
	}
	else if(deci / 100 == 1) cout<<"c";
	deci %= 100;
	if(deci / 10 > 1){
		cout<<deci/10<<"x";
	}
	else if(deci / 10 == 1) cout<<"x";
	deci %= 10;
	if(deci % 10 > 1){
		cout<<deci%10<<"i";
	}
	else if(deci % 10 == 1) cout<<"i";
	cout<<endl;
}

int main(void)
{
	m.insert(make_pair('m',1000));
	m.insert(make_pair('c',100));
	m.insert(make_pair('x',10));
	m.insert(make_pair('i',1));
	int tc;
	cin>>tc;
	for(int i = 0 ; i < tc ; i++){
		char str1[10],str2[10];
		cin>>str1>>str2;
		int res = systodeci(str1) + systodeci(str2);
		decitosys(res);
	}
}
