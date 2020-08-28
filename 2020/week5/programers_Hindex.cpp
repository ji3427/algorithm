#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int compare(int A,int B){
	return A > B;
}

int solution(vector<int> citations) {
    int answer = 0;
    sort(citations.begin(),citations.end(),compare);
    int max = citations.size();
    int min = 0;
    int mid;
    while(min <= max){
		mid = (max + min)/2;
		if(mid + 1>= citations[mid]) return mid +1;
		else min = mid + 1;
	}
	answer = mid;
    return mid;
}

int main(void)
{
	
}
