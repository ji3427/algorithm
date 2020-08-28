#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

vector<pair<int,int>> way;
bool room[200];
int ans = 0;
int main(void){
	int size;
	cin>>size;
	for(int i = 0 ; i < size ; i++){
		int start,fin;
		cin>>start>>fin;
		if(start % 2 == 0) start -= 1;
		if(fin % 2 == 0) fin -= 1;
		way.push_back(make_pair(min(start / 2,fin / 2),max(start / 2,fin / 2)));
	}
	sort(way.begin(),way.end());
	for(int i = 0 ; i < way.size() ; i++){
		if(room[i] == false){
			room[i] = true;
			int e = way[i].second;
			for(int j = i ; j < way.size()-1 ;j++){
				if(room[j+1] == false && e < way[j+1].first){
					room[j+1] = true;
					e = way[j+1].second;
				}
			}
			ans++;
		}
	}
	cout<<ans*10<<endl;
}
