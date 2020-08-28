#include <iostream>
#include <vector>
#include <string>
using namespace std;


int solution(string s) {
    int answer = 1000000;
    if(s.length() == 1) return 1;
    for(int i = 1 ; i <= s.length() / 2 ; i++){
		string before = s.substr(0,i);
		string cur;
		int index = 1;
		string ans;
		int size = 0;
		while(index*i < s.length()){
			cur = s.substr(index*i,i);
			if(cur != before){
				if(size != 0) ans+=to_string(size+1);
				ans+=before;
				before = cur;
				size = 0;
			}
			else{
				size++;
			}
			index++;
		}
		if(size == 0) ans+= before;
		else ans+= to_string(size+1)+before;
		//cout<<i<<" "<<ans<<endl;
		if(answer > ans.length()) {answer = ans.length();}
	}
    return answer;
}


int main(void){
	string a = "a";
	cout<<solution(a);
}
