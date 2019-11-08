#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int f_num[100000];
int p_num[100000];


int facto(int N){
	if(f_num[N] != 0) return f_num[N];
	else{
		f_num[N] = facto(N-1) * N;
	}
	return f_num[N];
}
 
int sol(int min,int max,int a)
{
	int mid = (min + max)/2;
	if(min == max) return mid;
	if(facto(mid) < (long)pow((double)a,(double)mid)){
		return sol(mid +1 , max,a);
	}
	else{
		return sol(min , mid, a);
	}
}

int main(void)
{
	memset(f_num,0,sizeof(f_num));
	memset(p_num,0,sizeof(f_num));
	f_num[1] = 1;
	f_num[2] = 2;
	int size;
	cin>>size;
	for(int i = 0 ; i < size ; i++){
		int a;
		cin>>a;
		cout<<sol(1,30,a)<<endl;
	}
	
}
