#include <iostream>
#include <vector>
using namespace std;

vector<pair<int,int>> home;
vector<pair<int,int>> chome;
int ans = 100000;
int size,M;


vector<pair<int,int>> c;

void dfs(int idx){
	if(c.size() == M){
		int cd = 0;
		for(int i = 0 ; i < home.size(); i++){
			int minN = 100000;
			for(int j = 0 ; j < c.size() ; j++){
				int d = abs(c[j].first - home[i].first) + abs(c[j].second - home[i].second);
				if(d < minN ) minN = d;
			}
			cd += minN;
		}
		if(cd < ans) ans = cd;
		return;
	}
	for(int i = idx ; i < chome.size() ; i++){
			c.push_back(chome[i]);
			dfs(i+1);
			c.pop_back();
		}
}

int main(void){
	int temp;
	cin>>size>>M;
	for(int i = 0 ; i < size ; i++){
		for(int j = 0 ; j < size ; j++){
			cin>>temp; 
			if(temp == 2) chome.push_back(make_pair(i,j));
			else if(temp == 1) home.push_back(make_pair(i,j));
		}
	}
	dfs(0);
	cout<<ans;
}
