#include <iostream>
#include <string.h>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

struct trie{
	bool isend;
	struct trie * next[10];
	trie(){
		isend = false;
		memset(next,0,sizeof(next));
	}
	bool insert(char *key){
		if(isend == true){
			return false;
		}
		if(*key == '\0'){
			isend = true;
			return true;
		}
			
		else{
			int cur = *key - '0';
			if(next[cur] == NULL)
				next[cur] = new trie();
			return next[cur]->insert(key+1);
		}
	}
};



bool solution(vector<string> phone_book) {
    bool answer = true;
    sort(phone_book.begin(),phone_book.end());
    trie * root = new trie();
    for(int i = 0 ; i < phone_book.size() ; i++){
		char str[20];
		memset(str,0,sizeof(str));
		strcpy(str,phone_book[i].c_str());
		if(root->insert(str) == false){
			answer = false;
		}
	}
    return answer;
}


int compare(string A, string B){
	return A.length() < B.length();
}

int main(void){
	vector<string> p;
	p.push_back("123");
	p.push_back("456");
	p.push_back("789");
	if(solution(p)) cout<<"true";
	else cout<<"false";
}
