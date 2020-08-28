#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int main(void){
	int tc;
	cin>>tc;
	for(int t = 0 ; t < tc ; t++){
		int l, a, b;
		cin>>l>>a>>b;
		string str;
		string ans;
		for(int i = 0 ; i < b ; i++){
			char c = 'a' + i;
			str.push_back(c);
		}
		for(int i = 0 ; i < l / b ; i++){
			ans += str;
		}
		ans += str.substr(0,l%b);
		cout<<ans<<endl;
	}
}
