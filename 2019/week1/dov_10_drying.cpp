#include <iostream>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

vector<int> laundry;
int k;

bool check(int time){
	int cnt = 0;
	for(int i = 0 ; i < laundry.size() ; i++){
		if(laundry[i] > time) {
			cnt += ceil((double)(laundry[i] - time) / k);
		}
		if(cnt > time) return false;
	}
	return true;
}


int main(void){
	int size;
	cin>>size;
	int temp;
	int min = 1;
	int max = -1;
	for(int i = 0 ; i < size ; i ++){
		cin>>temp;
		if(temp >= max)  max = temp;
		laundry.push_back(temp);
	}
	cin>>k;
	if(k == 1) {cout<< max;return 0;}
	k--;
	int mid;
	int ans;
	while(min <= max){
		mid = (min + max) / 2;
		if(check(mid)){
			max = mid - 1;
			ans = mid;
		}
		else{
			min = mid + 1;
		}
	}
	cout<<ans<<endl;
}

