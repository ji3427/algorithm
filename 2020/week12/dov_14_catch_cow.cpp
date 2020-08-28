#include <iostream>
#include <queue>
#include <utility>
using namespace std;
 typedef pair<int,int> node;
 
bool isvisit[100001];
queue<node> q;
 
int main(void)
{
    int s,e;
    cin>>s>>e;
    if(e<s){
        cout<< s-e<<endl;
        return 0;
    }
    node start = make_pair(0,s);
    q.push(start);
    isvisit[s] = true;
    while(!q.empty())
    {
        node next = q.front();
        q.pop();
        if(next.second == e){
            cout<<next.first;
            break;
        }
        int n = next.first;
        int v = next.second;
        node temp = make_pair(n+1,v);
        if(v+1 < 100000&&isvisit[v+1] == false){
            q.push(temp);
            isvisit[v+1] = true;
        }
        if(v-1 > 0 &&isvisit[v-1] == false){
            temp = make_pair(n+1,v-1);
            q.push(temp);
            isvisit[v-1] = true;
        }
        if(v*2 < 100000&&isvisit[v*2] == false){
            temp = make_pair(n+1,v*2);
            q.push(temp);
            isvisit[v*2] = true;
        }
    }
}
