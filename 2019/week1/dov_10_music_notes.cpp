#include <iostream>

using namespace std;
bool flag = false;
int times[50000];
int target;

int bisearch(int low,int high){
	int ans;
	flag = false;
	while(low <= high){
		int mid = (low + high)/2;
		if(times[mid] < target){
			ans = mid;
			low = mid + 1;
		}
		else if(times[mid] > target){
			high = mid -1;
		}
		else{
			flag = true;
			ans = mid;
			break;
		}
	}
	return ans;
}

int main(void)
{
	int sum = -1;
	int size_N,size_Q;
	cin>>size_N>>size_Q;
	times[0] = 0;
	for(int i = 1 ; i <= size_N ; i++){
		int temp;
		cin>>temp;
		sum = sum + temp;
		times[i] = sum;
	}
	for(int i = 0 ; i < size_Q ; i++){
		cin>>target;
		//cout<< target<<"   ";
		if(target == 0) {cout<<1<<endl; continue;}
		int ans = bisearch(0,size_N);
		if(flag) cout<<ans<<endl;
		else cout<<ans+1<<endl;
	}
}



/*
문제 이해는 했는데 코딩을 더럽게 함

#include<stdio.h>
 
int Arr[50000];
int N, Q;
 
int bi_search(int start, int end, int num)
{
    const int mid = (start + end)/2;
    if(start == end || Arr[mid] == num) return mid;
    else
    {
        if(num < Arr[mid]) bi_search(start, mid, num);
        else if(Arr[mid] < num) bi_search(mid+1, end, num);
    }
}
 
int main(void)
{
    int i, count=0, tmp;
    scanf("%d %d", &N, &Q);
 
    for(i=0; i<N; i++)
    {
        scanf("%d", &tmp);
        count += tmp;
        if(i==0) count--;
        Arr[i] = count;
    }
 
    for(i=0; i<Q; i++)
    {
        scanf("%d", &tmp);
        printf("%d\n", (bi_search(0, N, tmp)+1));
    }
 
    return 0;
}


*/
