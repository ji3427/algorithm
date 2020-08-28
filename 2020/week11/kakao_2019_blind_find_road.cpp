#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
#include <set>
#include <deque>
#include <algorithm>

using namespace std;
struct node{
    int index;
    int row;
    int col;
    node * left;
    node * right;
};

struct data{
	int row;
	int col;
	int index;
};

bool compare(data A,data B){
	if(A.row == B.row){
		return A.col < B.col;
	}
	return A.row > B.row;
}
vector<vector<int>> answer;
void insert(node * cur,int row,int col,int index){
	if(cur->index == 0) {cur->index = index;cur->row = row; cur->col = col; return;}
	if(cur->row < row){
		int t_row = cur -> row;
		int t_col = cur -> col;
		int t_index = cur -> index;
		cur->row = row;
		cur->col = col;
		cur->index = index;
		insert(cur,t_row,t_col,t_index);
	}
	else{
		if(cur->col > col){
			if(cur->left == NULL){ cur->left = (node*)malloc(sizeof(node)); cur->left->index = 0; cur->left->left = NULL;cur->left->right = NULL;}
			insert(cur->left,row,col,index);
		}
		else if(cur->col < col){
			if(cur->right == NULL){ cur->right = (node*)malloc(sizeof(node)); cur->right->index = 0;cur->right->left = NULL;cur->right->right = NULL;}
			insert(cur->right,row,col,index);
		}
	}
}

void visit(node * cur){
	answer[0].push_back(cur->index);
	if(cur->left == 0 && cur->right == 0){answer[1].push_back(cur->index); return;}
	if(cur -> left != 0) visit(cur->left);
	if(cur -> right != 0) visit(cur->right);
	answer[1].push_back(cur->index);
}


vector<vector<int>> solution(vector<vector<int>> nodeinfo) {
	vector<int> dummy;
	vector<data> n;
	answer.push_back(dummy);
	answer.push_back(dummy);
    node * head = (node*)malloc(sizeof(node));
    head->index = 0;
    head->right = NULL;
    head->left = NULL;
    for(int i = 0 ; i < nodeinfo.size() ; i++){
		data temp = {nodeinfo[i][1],nodeinfo[i][0],i+1};
		n.push_back(temp);
	}
	sort(n.begin(),n.end(),compare);
	for(int i = 0 ; i < n.size() ;i++){
		insert(head,n[i].row,n[i].col,n[i].index);
	}
	visit(head);
    return answer;
}

int main(void){
	vector<vector<int>> nf = {{5,3},{11,5},{13,3},{3,5},{6,1},{1,3},{8,6},{7,2},{2,2}};
	nf = solution(nf);
	for(int i = 0 ; i < nf.size() ; i++){
		for(auto j : nf[i]) cout<<j<<" ";
		cout<<endl;
	}
}
