#include <iostream>
#include <queue>
using namespace std;

struct node{
	int Ldata;
	int Rdata;
	int Lindex;
	int Rindex;
};

int main(void){
	int N;
	cin>>N;
	for(int i = 0 ; i < N ; i++){
		int L,R;
		cin>>L>>R;
		queue<node> q;
		node t = {1,1,0,0};
		q.push(t);
		if(L == 1){cout<<"Scenario #"<<i+1<<":"<<endl;cout<<"0 "<<R-1<<endl; continue;}
		if(R == 1){cout<<"Scenario #"<<i+1<<":"<<endl;cout<<L-1<<" 0"<<endl; continue;}
		while(!q.empty()){
			t= q.front();
			//cout<<t.Ldata<<" "<<t.Rdata<<" "<<endl;
			q.pop();
			if(t.Ldata ==L && t.Rdata == R){
				cout<<"Scenario #"<<i+1<<":"<<endl;
				cout<<t.Lindex<<" "<<t.Rindex<<endl;
				break;
			}
			node LN = {t.Ldata+t.Rdata,t.Rdata,t.Lindex + 1,t.Rindex};
			node RN = {t.Ldata, t.Ldata + t.Rdata,t.Lindex,t.Rindex+1};
			q.push(LN);
			q.push(RN);
		}	
	}

}
