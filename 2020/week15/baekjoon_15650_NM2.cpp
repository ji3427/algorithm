#include <iostream>
#include <string>
#include <vector>
#include <map>
#include <algorithm>

using namespace std;


int main(void){
	int size,num;
	cin>>size>>num;
	vector<int> data(size,0);
	vector<int> index(size,1);
	for(int i = 0 ; i < data.size() ; i++) data[i] = i+1;
	for(int i = 0 ; i < num ; i++) index[i] = 0;
	sort(index.begin(),index.end());
	do{
		for(int i = 0 ; i < index.size() ; i++){
			if(index[i] == 0) cout<<data[i]<<" ";
		}
		cout<<endl;
	}while(next_permutation(index.begin(),index.end()));
}
