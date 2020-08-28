#include <iostream>
#include <map>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> board;
vector<int> dummy;

bool compare(pair<int,int> A, pair<int,int> B){
	if(A.second == B.second) return A.first < B.first;
	return A.second < B.second;
}
int r_size;
int c_size;
int main(void){
	int r,c,k;
	cin>>r>>c>>k;
	r-=1;
	c-=1;
	r_size = 3;
	c_size = 3;
	for(int i = 0 ; i < 3 ; i++){
		board.push_back(dummy);
		for(int j = 0 ; j < 3 ; j++){
			int temp;
			cin>>temp;
			board[i].push_back(temp);
		}
	}
	int ans = 0;
	while(1){
		if(r <= r_size && c <= c_size && board[r][c] == k) break;
		ans++;
		if(ans > 100){
			ans = -1;
			break;
		}
		if(r_size >= c_size){
			for(int i = 0 ; i < r_size ; i++){
				map<int,int> m;
				map<int,int>::iterator it;
				vector<pair<int,int>> sortA;
				for(int j = 0 ; j < board[i].size() ; j++){
					if(m.find(board[i][j]) == m.end()) m.insert(make_pair(board[i][j],1));
					else m[board[i][j]]++;
				}
				for(it = m.begin(); it != m.end() ; it++){
					if(it->first == 0) continue;
					sortA.push_back(make_pair(it->first,it->second));
				}
				if(c_size < sortA.size() * 2) c_size = sortA.size() *2;
				sort(sortA.begin(),sortA.end(),compare);
				board[i].assign(c_size,0);
				int index = 0;
				for(auto k : sortA){
					board[i][index++] = k.first;
					board[i][index++] = k.second;
				}
			}
			for(int i = 0 ; i < r_size ; i++) board[i].resize(c_size);
		}
		else{
			for(int i = 0 ; i < c_size ; i++){
				map<int,int> m;
				map<int,int>::iterator it;
				vector<pair<int,int>> sortA;
				for(int j = 0 ; j < r_size ; j++){
					if(m.find(board[j][i]) == m.end()) m.insert(make_pair(board[j][i],1));
					else m[board[j][i]]++;
				}
				for(it = m.begin() ; it != m.end() ; it++){
					if(it->first == 0) continue;
					sortA.push_back(make_pair(it->first,it->second));
				}
				if(r_size < sortA.size() * 2) r_size = sortA.size()*2;
				sort(sortA.begin(),sortA.end(),compare);
				for(int k = board.size() ; k < r_size ; k++){
					board.push_back(dummy);
					board[k].resize(c_size);
				}
				int index = 0;
				for(auto k : sortA){
					board[index++][i] = k.first;
					board[index++][i] = k.second;
				}
				for(;index < board.size() ; index++) board[index][i] = 0;
			}
		}
	}
	cout<<ans<<endl;
}
