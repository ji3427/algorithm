#include <iostream>
#include <list>
#include <string.h>
#include <math.h>

using namespace std;


long long p(int n,int m){
	long long ans = 1;
	for(int i = 0 ; i < m ; i++){
		ans*=n;
	}
	return ans;
}


int main(void){
	int n,k;
	list<int> l;
	char num[64];
	cin>>num;
	cin>>n>>k;
	int r;
	long long ans = 0;
	for(int i = 0 ; i < strlen(num) ; i++){
		if(num[i] == '-' ) cout<<"-";
		if(num[i] >= '0' && num[i] <= '9')
			ans += (num[i] - '0') * p(n,strlen(num) - i - 1);
		else if(num[i] >= 'A' && num[i] <= 'Z')
			ans += (num[i] - 'A' + 10) * p(n,strlen(num) - i - 1);
	}
	while(ans >= k){
		r = ans % k;
		ans = ans / k;
		l.push_front(r);
	}
	l.push_front(ans);
	list<int>::iterator it = l.begin();
	char a;
	for(;it!= l.end() ; it++){
		if(*it > 9){
			a = *it - 10 + 'A';
			cout<<a;
			continue;
		}
		cout<<*it;
	}
}
