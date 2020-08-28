#include <iostream>
#include <deque>
#include <vector>
#include <string.h>
#include <algorithm>

using namespace std;

deque<int> alph[26];
vector<char> palette;


int deleteindex(){
	int max = -1;
	int maxindex = 0;
	for(int i = 0 ; i < 3 ; i++){
		if(alph[palette[i] - 'A'].size() == 0) return i;
		else{
			if(alph[palette[i] - 'A'][0] > max){
				max = alph[palette[i] - 'A'][0];
				maxindex = i;
				} 
		}
	}
	return maxindex;
}

bool isin(char A){
	for(auto i : palette) if(i==A) return true;
	return false;
}



int main(void)
{
	char str[100];
	 int size;
	 int ans = 0;
	 cin>>size;
	 cin>>str;
	 for(int i = 0 ; i < size ; i++){
		 alph[str[i]-'A'].push_back(i);
	 }
	 for(int i = 0 ; i < 26 ; i++){
		 sort(alph[i].begin(),alph[i].end());
	 }
	 
	for(int i = 0 ; i < strlen(str); i++){
		 if(isin(str[i])) {
			 if(alph[str[i] - 'A'].size() > 0 ) alph[str[i] - 'A'].pop_front();
			continue; 
		 }
		 if(palette.size() < 3) {
			palette.push_back(str[i]);
			if(alph[str[i] - 'A'].size() > 0 ) alph[str[i] - 'A'].pop_front(); 
		 }
		 else{
			palette[deleteindex()] = str[i];
			 ans++;
			 if(alph[str[i] - 'A'].size() > 0 ) alph[str[i] - 'A'].pop_front();
		 }
	 }
	 cout<<ans<<endl;
}


