#include <iostream>

using namespace std;

int array[1000];
int ans;
void p(int size){
	for(int i = 0 ; i < size ; i++){
		cout<<array[i];
	}
	cout<<endl;
}
void swap(int * num1, int * num2){
	int temp;
	temp = *num1;
	*num1 = *num2;
	*num2 = temp;
	ans+=1;
	//p(50);
}



void sol(int low,int start_num,int size){
	int last;
	if(start_num == 3 || low >= size) return;
	if(array[low] != start_num){
		int i = low +1;
		while(i < size){
			if(array[i] == start_num){
				last = i;
			}
			i++;
		}
		swap(&array[last],&array[low]);	
	}
	int i = low + 1;
	while(array[i] == start_num) i++;
	int j = size;
	for(; j > i ; j--){
		if(array[j] == start_num){
			swap(&array[i],&array[j]);
			while(array[i] == start_num) i++;
		}
	}
	sol(i,start_num +1,size);

}


int main(void)
{
	ans = 0;
	int size;
	cin>>size;
	for(int i = 0 ; i < size ; i++)
	{
		cin>>array[i];
	}
	sol(0,1,size);
	cout<<ans;
	
}
