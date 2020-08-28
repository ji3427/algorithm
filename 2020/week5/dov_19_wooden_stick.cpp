#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct tree{
	int length;
	int weight;
};

int compare(tree A,tree B){
	return (A.weight <= B.weight && A.length <= B.length);
}

int main(void)
{
	int size;
	cin>>size;
	int ans = 1;
	vector<vector<tree>> t;
	for(int i = 0 ; i < size ; i++){
		tree temp;
		cin>>temp.length;
		cin>>temp.weight;
		for(vector<tree> i : t){
			if((i.back().length <= temp.length && i.back().weight <= temp.weight) || i.size() == 0){
				i.push_back(temp);
			}
			sort(i.begin(),i.end(),compare);
		}
	}
	cout<<t.size()<<endl;
}
