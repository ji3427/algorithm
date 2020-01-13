#include <iostream>
#include <string.h>

using namespace std;

int main(void)
{
	int A = 0;
	int B = 0;
	char num1[4];
	char num2[4];
	cin>>num1>>num2;
	for(int i = 0 ; i < 4 ; i++){
		for(int j = 0 ; j < 4 ; j++){
			if(num1[i] - num2[j] == 0){
				if(i == j) A++;
				else B++;
			}
		}
	}
	cout<<A<<"A"<<B<<"B"<<endl;
}
