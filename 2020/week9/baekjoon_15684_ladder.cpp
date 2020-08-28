#include <iostream>

using namespace std;

int main(void){
	int col,row,size;
	cin>>col>>size>>row;
	for(int i = 0 ; i < size; i++){
		int id,h;
		cin>>id>>h;
		ladder[id-1].insert(h);
	}
	
}
