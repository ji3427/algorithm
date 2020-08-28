#include <iostream>
#include <string>
#include <vector>
#include <stack>
using namespace std;

int solution(string arrangement) {
    int answer = 0;
    stack<char> st;
    for(int i = 0 ; i < arrangement.length() ; i++){
		if(i+1 < arrangement.length() && arrangement[i] == '('){
			if(arrangement[i+1] == ')'){
				answer += st.size();
				i++;
			}
			else{
				st.push('(');
			}
		}
		else{
			st.pop();
			answer++;
		}
	}
    return answer;
    
}


int main(void)
{
		string str = "()(((()())(())()))(())";
		cout<<solution(str);
}
