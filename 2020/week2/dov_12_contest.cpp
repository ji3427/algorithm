#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;

struct p{
	int nsumbit;
	int elapse;
};
struct t{
	char name[20];
	struct p prob[4];
	int solved;
	int penalty;
};

int compare(struct t t1,struct t t2){
	if(t1.solved == t2.solved){
		return t1.penalty < t2.penalty;
	}
	else{
		return t1.solved > t2.solved;
	}
}


int main(void)
{
	int size;
	cin>>size;
	struct t teamarray[10];
	memset(teamarray,0,sizeof(struct t) * 10);
	for(int i = 0 ; i <size ; i++){
		cin>>teamarray[i].name;
		for(int j = 0 ; j < 4 ; j++){
			int count,ptime;
			cin>>count>>ptime;
			
			if(ptime > 0) {
				teamarray[i].penalty += (20 * (count-1));
				teamarray[i].penalty += ptime; teamarray[i].solved++;
			}
		}
	}
	sort(teamarray,teamarray+10,compare);
	cout<<teamarray[0].name<<" "<<teamarray[0].solved<<" "<<teamarray[0].penalty<<endl;
}

