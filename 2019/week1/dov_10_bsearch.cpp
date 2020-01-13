#include <iostream>

using namespace std;

int numbers[500000];
int bisearch(int low,int high,int target)
{
	int ans;
	if(low>high) return 0;
	int mid = (high + low)/2;
	if(target < numbers[mid]){
		ans = bisearch(low,mid - 1 , target);
	}
	else if(target > numbers[mid]){
		ans = bisearch(mid+1,high , target);
	}
	else{
		ans = mid;
	}
	return ans;
}

int main(void)
{
	int size,target;
	cin>>size;
	for(int i = 0 ; i < size; i ++){
		cin>>numbers[i];
	}
	cin>>target;
	int ans = bisearch(0,size-1,target);
	ans == 0 ? cout<<"not found"<<endl : cout<<ans+1<<endl;
}

