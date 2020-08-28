#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

struct height{
	int row;
	int col;
	int hg;
};
int mt[101][101];
int ans = 1;
int mx_row,mx_col;

int compare(height A, height B){
	return A.hg > B.hg;
}


int getlength(int row,int col,int length){
	if(ans < length) ans = length;
	if(row - 1 >= 0 && mt[row][col] > mt[row - 1][col]) return getlength(row-1,col,length+1);
	if(row + 1 < mx_row && mt[row][col] > mt[row + 1][col]) return getlength(row+1,col,length+1);
	if(col - 1 >= 0 && mt[row][col] > mt[row][col - 1]) return getlength(row,col-1,length+1);
	if(col + 1 < mx_col && mt[row][col] > mt[row ][col + 1]) return getlength(row,col+1,length+1);
}

int main(void){
	cin >>mx_row >>mx_col;
	vector<height> hv;
	memset(mt,0,sizeof(mt));
	for(int i = 0 ; i < mx_row ; i++){
		for(int j = 0 ; j < mx_col ;j++){
			int temp;
			struct height t;
			cin>>temp;
			mt[i][j] = temp;
			t.row = i;
			t.col = j;
			t.hg = temp;
			hv.push_back(t);
		}
	}
	sort(hv.begin(),hv.end(),compare);
	for(int i = 0 ; i < hv.size() ; i++){
		if(ans > hv[i].hg) break;
		getlength(hv[i].row,hv[i].col,1);
	}
	cout<<ans;
}
