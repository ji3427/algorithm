#include <iostream>
#include <vector>
#include <string.h>
using namespace std;

int board[50][50];
struct node{
    int row;
    int col;
    int num;
};
vector<vector<node>> com;
int com_size;
bool visited[50][50];
int N,L,R;
void dfs(int cur,int row,int col){
    if(visited[row][col] == true) return;
    visited[row][col] = true;
    vector<node> temp;
    if(cur == 0) com.push_back(temp);
    node n = {row,col,board[row][col]};
    com[com_size].push_back(n);
    if(col+1 < N&&abs(board[row][col] - board[row][col+1]) >= L && abs(board[row][col] - board[row][col+1]) <= R) dfs(cur+1,row,col+1);
    if(row+1 < N &&abs(board[row][col] - board[row+1][col]) >= L && abs(board[row][col] - board[row+1][col]) <= R) dfs(cur+1,row+1,col);
    if(col - 1 >= 0 &&abs(board[row][col] - board[row][col-1]) >= L && abs(board[row][col] - board[row][col-1]) <= R) dfs(cur+1,row,col-1);
    if(row - 1 >= 0 &&abs(board[row][col] - board[row-1][col]) >= L && abs(board[row][col] - board[row-1][col]) <= R) dfs(cur+1,row-1,col);
    if(com[com_size].size() != 0 && cur == 0) com_size++;
}


int main(void){
    cin>>N>>L>>R;
    for(int i = 0 ; i < N ; i++){
        for(int j = 0 ; j < N ; j++){
            cin>>board[i][j];
        }
    }
    int ans = 0;
    while(com.size() != N*N){
        com_size = 0;
        com.clear();
        memset(visited,0,sizeof(visited));
        for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++){
                dfs(0,i,j);
            }
        }
        for(int i = 0 ; i < com.size(); i++){
            int sum = 0;
            for(auto j : com[i]) sum+= j.num;
            sum /= com[i].size();
            for(auto j : com[i]) board[j.row][j.col] = sum; 
        }
        /*for(int i = 0 ; i < N ; i++){
            for(int j = 0 ; j < N ; j++)
                cout<<board[i][j]<<" ";
            cout<<endl;
        }*/
        ans++;
    }
    cout<<ans-1<<endl;
}

