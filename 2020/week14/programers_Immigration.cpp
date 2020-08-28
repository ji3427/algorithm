#include <iostream>
#include <string>
#include <vector>
#include <math.h>
using namespace std;


long long getnum(vector<int> times, int N){
	long long ans = 0;
	for(auto i : times){
		ans += (N / i);
	}
	return ans;
}

long long solution(int n, vector<int> times) {
    long long answer = 1000000000;
    long long minN = 0;
    long long maxN = 1000000000;
    long long mid = 0;
    while(minN <= maxN){
		mid = (minN + maxN )/ 2;
//		cout<<"min "<<minN<<" max "<<maxN<<" ans "<<getnum(times,mid)<<endl;
		if(getnum(times,mid) < n){
			minN = mid + 1;
		}
		else{
			answer = min(mid,answer);
			maxN = mid - 1;
		}
	}
    return answer;
}









int main(void){
	vector<int> t = {7,10};
	cout<<solution(6,t)<<endl;
}
