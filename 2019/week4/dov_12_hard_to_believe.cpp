#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;
char exp[50];
vector<char> n1;
vector<char> n2;
vector<char> res;
int main(void)
{
	cin>>exp;
	int i = 0;
	while(1){
		if(exp[i] == '+') break;
		n1.push_back(exp[i]);
		i++;
	}
	i++;
	while(1){
		if(exp[i] == '=') break;
		n2.push_back(exp[i]);
		i++;
	}
	i++;
	while(1){
		if(i == strlen(exp)) break;
		res.push_back(exp[i]);
		i++;
	}
	reverse(n1.begin(),n1.end());
	reverse(n2.begin(),n2.end());
	reverse(res.begin(),res.end());
	int a = atoi(reinterpret_cast<char*>(n1.data()));
	int b = atoi(reinterpret_cast<char*>(n2.data()));
	int c = atoi(reinterpret_cast<char*>(res.data()));
	if(a + b == c) cout<<"True"<<endl;
	else cout<<"False"<<endl;
	
}
