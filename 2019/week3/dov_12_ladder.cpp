#include <iostream>
#include <list>
using namespace std;

struct node{
	int num1;
	int num2;
};

int main(void)
{
	int N,size;
	cin>>N>>size;
	list<struct node> li;
	for(int i = 0 ; i < size ; i++){
		struct node temp;
		cin>>temp.num1;
		if(temp.num1 + 1 > N)
			temp.num2 = temp.num1 - 1;
		else
			temp.num2 = temp.num1 + 1;
		li.push_back(temp);
	}
	for(int i = 1 ; i <= N ; i++){
		int cur = i;
		list<struct node>::iterator it = li.begin();
		for(;it != li.end() ; it++){
			if(cur == (*it).num1) cur = (*it).num2;
			else if(cur == (*it).num2) cur = (*it).num1;
		}
		printf("%d %c\n",i,cur - 1 + 'A');
	}
}
