#include <iostream>
#include <deque>
#include <algorithm>
using namespace std;

struct tree{
	int row;
	int col;
	int age;
};
int board[11][11];
int food[11][11];
deque<tree> tr;
deque<tree> dead;


bool compare(tree A,tree B){
	if(A.age == B.age){
		if(A.row == B.row) return A.col<B.col;
		else return A.row < B.row;
	}
	else{
		return A.age < B.age;
	}
}


int main(void){
	int N,M,K;
	cin>>N>>M>>K;
	for(int i = 0 ; i < N ;i++){
		for(int j = 0 ; j < N ; j++){
			cin>>food[i][j];
			board[i][j] = 5;
		}
	}
	for(int i = 0 ; i < M ; i++){
		int row,col,age;
		cin>>col>>row>>age;
		tree temp = {row-1,col-1,age};
		tr.push_back(temp);
	}
	sort(tr.begin(),tr.end(),compare);
	while(K != 0 && !tr.empty()){
		for(tree &i : tr){
			if((board[i.row][i.col] -= i.age) < 0){
				board[i.row][i.col] = 0;
				tree temp = {i.row,i.col,(i.age)+1};
				dead.push_back(temp);
				i.age = -8;
			}
			i.age = i.age + 1;
		}
		for(tree i : dead){
			board[i.row][i.col] += (i.age/2);
		}
		dead.clear();
		deque<tree> temp;
		for(tree i : tr){
			if(i.age < 0) continue;
			if(i.age % 5 == 0){
				if(i.row - 1 >= 0){
					if(i.col -1 >= 0 ) {tree a = {i.row -1 , i.col -1,1};temp.push_back(a);}
					if(i.col + 1 < N ) {tree a = {i.row -1 , i.col +1,1};temp.push_back(a);}
					{tree a = {i.row -1 , i.col,1}; temp.push_back(a);}
				}
				if(i.row + 1 < N){
					if(i.col -1 >= 0 ) {tree a = {i.row + 1 , i.col -1,1}; temp.push_back(a);}
					if(i.col + 1 < N ) {tree a = {i.row + 1 , i.col +1,1}; temp.push_back(a);}
					{tree a = {i.row + 1 , i.col,1}; temp.push_back(a);}
				}
				if(i.col -1 >= 0 ) {tree a = {i.row  , i.col -1,1}; temp.push_back(a);}
				if(i.col + 1 < N ) {tree a = {i.row  , i.col +1,1}; temp.push_back(a);}
			}
		}
		tr.insert(tr.end(),temp.begin(),temp.end());
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++) 
			board[i][j] += food[i][j];
		}
		K--;
		sort(tr.begin(),tr.end(),compare);
		while(tr.front().age < 0) tr.pop_front();
	}
	cout<<tr.size()<<endl;
	return 0;
}


