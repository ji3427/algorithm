#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define ll long long

struct node{
	ll num;
	int p;
	int m;
	int s;
	int d;
	int index;
};

int main(void){
	int size;
	cin>>size;
	vector<int> nums;
	queue<node> q;
	for(int i = 0 ; i < size ;i++){
		int t;
		cin>>t;
		nums.push_back(t);
	}
	ll min = 1000000000;
	ll max = -1000000000;
	int p,s,d,m;
	cin>>p>>s>>m>>d;
	node n;
	n.num = nums[0];
	n.p = 0; n.m = 0; n.s = 0; n.d = 0; n.index = 0;
	q.push(n);
	while(!q.empty()){
		n = q.front();
	//	cout<<n.num<<" "<<n.p<<" "<<n.s<<" "<<n.m<<" "<<n.d<<endl;
		if(n.index == nums.size() - 1&& min > n.num) min = n.num;
		if(n.index == nums.size() - 1 && max < n.num) max = n.num;
		n.index++;
		if(n.p < p){
			n.num += nums[n.index];
			n.p++;
			q.push(n);
		}
		n = q.front();
		n.index++;
		if(n.m < m){
			n.num *= nums[n.index];
			n.m++;
			q.push(n);
		}
		n = q.front();
		n.index++;
		if(n.s < s){
			n.num -= nums[n.index];
			n.s++;
			q.push(n);
		}
		n = q.front();
		n.index++;
		if(n.d < d){
			n.num /= nums[n.index];
			n.d++;
			q.push(n);
		}
		q.pop();
	}
	cout<<max<<endl;
	cout<<min<<endl;
		
}
