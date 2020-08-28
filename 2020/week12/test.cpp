#include <iostream>
#include <string>
#include <vector>

using namespace std;
 
 int T,N,answer;
 int map[100][100];
 int visit[100][100];
 int dx[4] = {-1,0,1,0};
 int dy[4] = {0,1,0,-1};
 int nodeN ;
 int dist[100][100];
 
 void dfs(int x,int y,int t){
	 nodeN++;
	if(x == N-1 && y == N - 1){
		if(answer == 0) answer = t;
		else if(answer > t) answer = t;
		return;
	}
	if(answer > 0 && answer < t) return;
	if(dist[x][y] == 0) dist[x][y] = t;
	else if(dist[x][y] > t) dist[x][y] = t;
	else return;
	for(int i = 0 ; i < 4 ; i++){
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(nx >= 0 && ny < N && ny >= 0 && nx < N && !visit[nx][ny]){
			visit[nx][ny] = true;
			dfs(nx,ny,t+map[nx][ny]);
			visit[nx][ny] = false;
		}
	}
 }
 
 
 
int main()
{
	cin>>T;
	for(int t = 1 ;  t <= T ; t++){
		cin>>N;
		answer = 0;
		nodeN = 0;
		for(int i = 0 ; i < N ; i++){
			for(int j = 0 ; j < N ; j++){
				scanf("%1d",&map[i][j]);
				visit[i][j] = false;
				dist[i][j] = 0;
			}
		}
		visit[0][0] = true;
		dfs(0,0,0);
		printf("#%d %d\n",t,answer);
		printf("visit nodeN  %d\n",nodeN);
	}
}
