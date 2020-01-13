#include <iostream>

using namespace std;

char team[100];
int score;
int main(void)
{
	int T,N;
	int sum = 0;
	cin>>T>>N;
	for(int i = 0 ; i < T ; i++){
		cin>>team;
		cin>>score;
		sum += score;
	}
	cout<<3*N - sum <<endl;
}
