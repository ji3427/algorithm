#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;


int compare(int A,int B){
	return A > B;
}


int main(void)
{
	int M,S,C;
	cin>>M>>S>>C;
	int barn[200];
	int ans[200];
	memset(ans,0,sizeof(ans));
	for(int i = 0 ; i < C ; i++){
		cin>>barn[i];
	}
	sort(barn,barn+C);
	int answer = barn[C-1] - barn[0] + 1;
	for(int i = 1 ; i < C ; i++){
		ans[i-1] = (barn[i] - barn[i-1] - 1);
	}
	sort(ans,ans+C,compare);
	int index = 0;
	for( ; index < M-1 && index < C - 1 ; index++) answer -= ans[index];
	cout<<answer<<endl;
}

