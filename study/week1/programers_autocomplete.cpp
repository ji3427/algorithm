#include <iostream>
#include <algorithm>
#include <vector>
#include <deque>
#include <string>
#include <memory.h>

using namespace std;

struct node{
	bool end;
	node* next[26];
};

void insert(node * head,string str){
	node * cur = head;
	for(char c : str){
		if(cur->next[c-'a'] == 0) cur->next[c-'a'] = (node*)malloc(sizeof(node));
		memset(cur->next[c-'a'],0,sizeof(cur->next));
		cur = cur->next[c-'a'];
	}
	cur->end = true;
}

int solution(vector<string> words) {
    int answer = 0;
    node head;
    node * cur = &head;
    for(string str : words) insert(&head,str);
    for(string str : words){
		for(int i = 0 ; i < str.length() ; i++){
			char c = str[i];
			cur = cur->next[c-'a'];
			int count = 0;
			for(int j = 0 ; j < 26 ;j++){
				if(cur->next[j] != 0) count++;
				if(count > 1 ) break;
			}
			if(cur->end == false && count < 1) answer += i;
		}
	}
	
    return answer;
}


int main(void){
	
}
