#include <iostream>
#include <string.h>
using namespace std;

struct number{
	int num;
	int judge; //low -1, high 1, right on 0
};

int main(void)
{
	int n;
	char str[10];
	struct number array[10];
	int index = 0;
	while(1){
		memset(str,0,10);
		cin>>n;
		cin.ignore();
		cin.getline(str,10);
		array[index].num = n;
		if(strcmp(str,"too high") == 0){
			array[index].judge = 1;
		}
		else if(strcmp(str,"too low") == 0){
			array[index].judge = -1;
		}
		else{
			array[index].judge = 0;
			break;
		}
		index++;
	}
	int pivot = array[index].num;
	int i = index;
	for(int j = i -1 ; j >= 0 ; j--){
		if(pivot > array[j].num){
			if(array[j].judge != -1){
				cout<<"Stan is dishonest"<<endl;
				return 0;
			}
		}
		else if(pivot < array[j].num){
			if(array[j].judge != 1){
				cout<<"Stan is dishonest"<<endl;
				return 0;
			}
		}
		else{
			if(array[j].judge != 0){
				cout<<"Stan is dishonest"<<endl;
				return 0;
			}			
		}
	}
	cout<<"Stan may be honest"<<endl;
	return 0;
}
