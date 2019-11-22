#include <iostream>
#include <string.h>
#include <stdlib.h>

using namespace std;
char str1[500];
int main(void)
{
	int size;
	cin>>size;
	cin.ignore();
	for(int i = 0 ; i < size ; i ++){
		long long sum = 0;
		cin.getline(str1,500);
		char * ptr = strtok(str1, " ");
		while(ptr != NULL){
		//	printf("%s\n",ptr);
			sum += atoll(ptr);
			ptr = strtok(NULL," ");
		}
		cout<<sum<<endl;
	}
}
