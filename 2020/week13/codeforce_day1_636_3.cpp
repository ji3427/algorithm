#include <iostream>
#include <vector>
#include <queue>
using namespace std;

long long board[100000];

struct data{
    int value;
    int index;
};


struct node{
    data d;
    int sum;
    int length;
};

vector<data> pos;
vector<data> neg;

int getNextPos(data A){
    int i = 0;
    while(i < pos.size() && pos[i].index < A.index) i++;
    if(pos[i].index != 0 && i < pos.size()) return i;
    return -1;
}

int getNextNeg(data A){
    int i = 0;
    while(i < neg.size() && neg[i].index < A.index) i++;
    if(neg[i].index != 0 && i < neg.size()) return i;
    return -1;
}



int main(void){
    int tc;
    cin>>tc;
    queue<node> q;
    for(int te = 0 ; te < tc ; te++){
        int n;
        cin>>n;
        data temp;
        pos.clear();
        neg.clear();
        for(int i = 0 ; i < n ; i++){
            cin>>temp.value;
            temp.index = i;
            if(temp.value < 0) neg.push_back(temp);
            else pos.push_back(temp);
            board[i] = -1000000000;
        }
        int max_len = 0;
        node t = {temp,0,0};
        if(neg.size() > 0 ){t.d = neg[0]; t.sum = t.d.value; q.push(t); board[0] = t.sum;}
        if(pos.size() > 0 ){t.d = pos[0]; t.sum = t.d.value; q.push(t); board[0] = t.sum;}
        while(!q.empty()){
            t = q.front();
            cout<<t.d.index<<endl;
            q.pop();
            int next = -1;
            if(max_len < t.length) max_len = t.length;
            if(t.d.value < 0){
                next = getNextPos(t.d);
                if(next < 0) continue;
                t.d = pos[next];
                t.length++;
                t.sum += t.d.value;
                cout<<"nextP "<<next<<"sum "<<t.sum<<"length "<<t.length<<endl;
                if(board[t.length] < t.sum) board[t.length] = t.sum;
                q.push(t);
            }
            else if(t.d.value > 0){
                next = getNextNeg(t.d);
                if(next < 0) continue;
                t.d = neg[next];
                t.length++;
                t.sum += t.d.value;
                 cout<<"nextN "<<next<<"sum "<<t.sum<<"length "<<t.length<<endl;
                if(board[t.length] < t.sum) board[t.length] = t.sum;
                q.push(t);
            }
        }
        //while(max_len > 0 && board[max_len] != -1000000000) max_len--;
        for(int i = 0 ; i < n ; i++){
			cout<<board[i]<<" ";
		}
        cout<<endl;
       // cout<<max_len<<endl;
    }
}
