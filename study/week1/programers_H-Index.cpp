#include <string>
#include <vector>
#include <iostream>
#include <algorithm>
#include <set>

using namespace std;
int mid;
int solution(vector<int> citations) {
    int answer = 0;
    int min = 0;
    int max = 10000;
    while(min <= max){
		mid = (min + max) / 2;
		int undersize = count_if(citations.begin(),citations.end(),[](int elem){return elem < mid;});
		if(undersize <= mid && mid <= citations.size() - undersize){
			answer = mid;
			min = mid + 1;
		}
		else max = mid - 1;
	}
    return answer;
}

int main(void){
	vector<int> c = {5,5,5,5};
	cout<<solution(c)<<endl;
}
