#include <iostream>

using namespace std;
int numbers[100001];
int sums[100001];
int N,S;

int bisearch(int min,int max){
	int num = sums[max];
	int a;
	int mid;
	while(min <= max){
		mid = (min + max) / 2;
		if(num - sums[mid] >= S){
			min = mid + 1;
			a = mid;
		}
		else if (num - sums[mid] < S){
			max = mid - 1;
		}
	}
	return a;
}

int main(void){
	cin>>N>>S;
	int ans = 9999999;
	int i = 0;
	for(i = 0 ; i < N ; i++){
		cin>>numbers[i];
		if(i>0) sums[i] = sums[i-1] + numbers[i];
		else sums[i] = numbers[i];
	}
	i = 0;
	while(sums[i] < S && i < N) i++;
	for(; i < N ; i++){
		int j = bisearch(0,i);
	//	cout<<i<<" "<<j<<endl;
		if(i - j  < ans ) ans = i - j ;
	}
	if(ans == 9999999) cout<<0<<endl;
	else cout<<ans<<endl;
}


	/*
	for(i = 0 ; i < N ; i++){
		for(int j = i + 1 ; j < N ; j++){
			sum += numbers[j];
			if(sum > S){
				if(j - i + 1 < ans) ans = j - i + 1;
			}
		}
	}
	*/
	
	/*	for(i = 0 ; i < N ; i++){
		for(int j = i + 1 ; j < N ; j++){
			if(sums[j] - sums[i] >= S){
				if(j - i + 1 < ans) ans = j - i ;
			}
		}
	}*/




