#include <iostream>

using namespace std;

struct person{
	char name[20];
	int first;
	int end;
};

int main(void)
{
	int size;
	cin>>size;
	for(int i = 0 ; i < size ; i++){
		struct person temp;
		cin>>temp.name;
		temp.first = 0;
		temp.end = 0;
	}
}
