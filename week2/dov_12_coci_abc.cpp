#include <iostream>
#include <algorithm>


using namespace std;

int compare(const void *a, const void *b)
{
    return *(int *)a - *(int *)b;   
}


int main(void)
{
	int num[4];
	for(int i = 0 ; i < 3 ; i++) cin>>num[i];
	qsort(num,3,sizeof(int),compare);
	char temp[3];
	cin>>temp;
	for(int i = 0 ; i < 3; i++){
		cout<<num[temp[i] - 'A']<<" ";
	}
	
}
