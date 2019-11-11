#include <iostream>
#include <list>
#include <string>

using namespace std;

int main(void)
{
	string num1,num2;
	cin>>num1>>num2;
	list<int> nl1;
	list<int> nl2;
	list<int> ans;
	int pos = num1.length();
	while(pos >= 0){
			nl1.push_back(atoi(num1.substr(pos,1).c_str()));
			pos--;
	}
	pos = num2.length();
	while(pos >= 0){
			nl2.push_back(atoi(num2.substr(pos,1).c_str()));
			pos--;
	}
	list<int>::iterator big_s;
	list<int>::iterator big_e;
	list<int>::iterator small_s;
	list<int>::iterator small_e;
	if(nl1.size() > nl2.size())
	{
		big_s = nl1.begin();
		big_e = nl1.end();
		small_s = nl2.begin();
		small_e = nl2.end();
	}
	else if(nl1.size() < nl2.size())
	{
		big_s = nl2.begin();
		big_e = nl2.end();
		small_s = nl1.begin();
		small_e = nl1.end();
		cout<<"-";
	}
	else{
		for (list<int>::iterator iter1 = nl1.end(); iter1 != nl1.begin(); --iter1){
			list<int>::iterator iter2 = nl2.end();
			if(*iter1 > *iter2){
				big_s = nl1.begin();
				big_e = nl1.end();
				small_s = nl2.begin();
				small_e = nl2.end();
				break;
			}
			else if(*iter1 < *iter2){
				big_s = nl2.begin();
				big_e = nl2.end();
				small_s = nl1.begin();
				small_e = nl1.end();
				cout<<"-";
				break;
			}
			else{
				iter2--;
				continue;
			}
		}
	}
	
	for(;big_s != big_e ; ++big_s){
		int small;
		if(small_s == small_e){
			small = 0;
		}
		else{
			small = *small_s;
			small_s++;
		}
		 
		int num = *big_s - small;
	//	cout<<*big_s <<" - "<<small<<" = "<<num<<endl;
		if(num < 0) {
			num = 10000 + num;
			*(big_s++) --;
			big_s--;
		}
		ans.push_front(num);
	}
	list<int>::iterator it = ans.begin();
	printf("%d",*it++);
	for(;it != ans.end() ; ++it){
		printf("%d",*it);
	}
}
