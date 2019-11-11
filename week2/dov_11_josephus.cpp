#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct _node{
	int num;
	_node * next;
}node;
node * current;

int except(int length){
	int ans;
	for(int i = 0 ; i < length -1; i++){
		current = current -> next;
	}
	ans = current -> next -> num;
	current->next = current->next->next;
	return ans;
}


int main(void)
{
	int size;
	cin>>size;
	node * head = (node*)malloc(sizeof(node));
	current = head;
	head -> num = 1;
	for(int i = 1 ; i < size ; i ++){
		current -> next = (node*)malloc(sizeof(node));
		current->next->num = i + 1;
		current = current->next;
	}
	current->next = head;
	current = head;
	int pivot,length;
	cin>>pivot>>length;
	if(size == 1) {cout<<"<1>"<<endl; return 0;}
	while(current -> next->num != pivot) current = current->next;
	current->next = current ->next->next;
	cout<<pivot<<" ";
	while(current -> next != current){
		cout<<except(length)<<" ";
	}
	cout<<current->num<<endl;
}

