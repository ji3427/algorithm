#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main(void){
	int size;
	cin>>size;
	int k,temp;
	priority_queue<int> pq;
	for(int i = 0 ; i < size ; i ++){
		cin>>temp;
		pq.push(temp);
	}
	cin>>k;
}

/*
// 우선 순위 큐로 꿀빨라고 했는데 실패
int main(void)
{
	int size;
	cin>>size;
	int k,temp;
	int time = 0;
	priority_queue<int> pq;
	for(int i = 0 ; i < size ; i ++){
		cin>>temp;
		pq.push(temp);
	}
	cin>>k;
	while(pq.top() > time){
		int t = pq.top();
		pq.pop();
		t = t - k + 1;
		time++;
		pq.push(t);
	}
	cout<<time<<endl;
}

*/



/*
답:
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
const int mx = 100005;

int n, k, a[mx];

bool judge(int time)
{
	int cnt = 0;
	for (int i = 0; i < n; ++i)
	{
		if (a[i] > time) cnt += ceil((double)(a[i] - time) / k);
		if (cnt > time) return false;
	}
	return true;
}

int main()
{
	scanf("%d", &n);
	int l = 0, r = 0, m;
	for (int i = 0; i < n; ++i)  scanf("%d", &a[i]), r = max(r, a[i]);
	scanf("%d", &k);
	if (k == 1) return printf("%d", r), 0; ///要特判k为1的情况！！
	--k;
	while (l + 1 < r) judge(m = (l + r) >> 1) ? r = m : l = m;
	printf("%d", l + 1);
	return 0;
}

*/
