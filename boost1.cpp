#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>
#include <vector>
#include <set>
#include <unordered_set>

using namespace std;



int rd(){
	return rand();
}





vector<int> del_duplicate(vector<int> array){
	vector<int> newarray;
	for(int i = 0 ; i < array.size() ; i++){
		if(binary_search(newarray.begin(),newarray.end(),array[i]) == false) newarray.push_back(array[i]);
		//if(find(newarray.begin(),newarray.end(),array[i]) == newarray.end()) newarray.push_back(array[i]);
	}
	return newarray;
}

vector<int> sum(vector<int> base,vector<int> other){
	for(int i = 0 ; i < other.size() ; i++){
		base.push_back(other[i]);
	}
	return del_duplicate(base);
}

vector<int> complement(const vector<int>& base, const vector<int>& other) {
    vector<int> result;
    for (auto e : base) {
        if (find(other.begin(), other.end(), e) == other.end())
            result.push_back(e);
    }

    return result;
}

vector<int> intersect(const vector<int>& base, const vector<int>& other) {
    vector<int> result;
    for (auto e : base) {
        if (find(other.begin(), other.end(), e) != other.end())
       // if (binary_search(other.begin(), other.end(), e) == true)
            result.push_back(e);
    }
    return result;

}



int main(void){
	clock_t start,end;
	unordered_set<int> result;
	vector<int> A(1000000);
	vector<int> B(1000000);
	generate(A.begin(),A.end(),rd);
	generate(B.begin(),B.end(),rd);
	start = clock();
	cout<<start<<"\n";
	unordered_set<int> newA(A.begin(),A.end());
	unordered_set<int> newB(B.begin(),B.end());
	//sum(newA,newB);
	unordered_set<int>::iterator it;
	for(auto i : newB) result.insert(i);
	for(auto i : newA) result.insert(i);
	cout<<"sum A"<<clock()<<endl;
	for(auto i : newB){
		if((it = newA.find(i)) != newA.end()) result.insert(*it);
	}
	//set_difference(A.begin(),A.end(),B.begin(),B.end(),result.begin());
	//complement(newA,newB);
	cout<<"complement"<<clock()<<endl;
	result.clear();
//	set_intersection(A.begin(),A.end(),B.begin(),B.end(),result.begin());
	for (auto e : newA) {
        if ((it = newB.find(e)) != newB.end())
            result.insert(e);
    }
	cout<<"intersect"<<clock()<<endl;
	end = clock();
	cout<<end<<"\n";
}
