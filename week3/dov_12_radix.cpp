#include <iostream>
#include <list>
using namespace std;

int main(void){
	int d,r;
	int num;
	cin>>d>>r;
	list<int> ans;
	while(d >= r){
		num = d % r;
		d = d / r;
		ans.push_front(num);
	}
	ans.push_front(d);
	list<int>::iterator it = ans.begin();
	char n;
	for(;it!= ans.end() ; it++){
		if(*it > 9){
			n = *it - 10 + 'A';
			cout<<n;
			continue;
		}
		cout<<*it;
	}
}
