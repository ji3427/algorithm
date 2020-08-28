#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
#include <string.h>
#include <sstream>
#include <set>

using namespace std;

bool check(vector<int> stones,int k){
	for(int i = 0 ; i < stones.size() ; i++){
		if(stones[i] == 0){
			int size = 0;
			while(stones[i] == 0){
				cout<<i<<" ";
				size++;
				i++;
			}
			cout<<endl;
			if(size >= k) return false;  
		}
	}
	return true;
}


int solution(vector<int> stones, int k) {
    int answer = 0;
    int start ,end;
    start = 0;
    end = 6;
    int mid;
    while(start <= end){
		mid = (start + end) / 2;
		vector<int> s = stones;
		for(int i = 0 ; i < s.size() ; i++){
			s[i] -= mid;
			if(s[i] < 0) s[i] = 0;
		}
		cout<<"before : "<<start<<" "<<mid<<" "<<end<<endl;
		if(check(s,k)) {
			start = mid + 1;
			answer = mid;
		}
		else end = mid - 1;
		cout<<"after : "<<start<<" "<<mid<<" "<<end<<endl; 
	}
    return answer+1;
}

int main(void){
	vector<int> st = {2, 4, 5, 3, 2, 1, 4, 2, 5, 1};
	cout<<solution(st,3);
	
}
