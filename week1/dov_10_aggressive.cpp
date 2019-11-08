#include <iostream>
#include <algorithm>

using namespace std;

int stall[100000];
int N,C;

bool check(int length){
	int current,cow;
		current = stall[0];
		cow = 1;
		for(int j =  1 ; j < N ;j++){
			if(stall[j] - current < length) continue;
			else {
				cow++;
				current = stall[j];
			}
		}
		if(cow < C) return false;
	return true;
}

int main(void)
{
	int ans = 0;
	cin >>N>>C;
	for(int i = 0 ; i < N ; i++){
		cin>>stall[i];
	}
	sort(stall,stall + N);
	int max,min,mid;
	min = 1;
	max = stall[N - 1];
	while(min <= max){
		mid = (min + max) / 2;
		if(check(mid)){ 
			min = mid + 1;
			ans = mid;
		}
		else{
			max = mid - 1;
		}
	}
	cout<<ans;
}
