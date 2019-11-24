#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

struct student{
	char name[10];
	int size;
};

int main(void)
{
	vector<struct student> sl;
	int num;
	cin>>num;
	int sum = 0;
	for(int i = 0 ; i < num ; i++){
		struct student temp;
		int r,c,h;
		cin>>r>>c>>h;
		temp.size = r * c * h;
		sum+=temp.size;
		cin>>temp.name;
		sl.push_back(temp);
	}
	sum /= num;
	char bad[10];
	char fool[10];
	vector<struct student>::iterator it = sl.begin();
	for(; it != sl.end() ; it++){
		if((*it).size < sum) strcpy(fool,(*it).name);
		else if((*it).size > sum) strcpy(bad,(*it).name);
	}
	cout<<bad<<" took clay from "<<fool<<"."<<endl;
}
