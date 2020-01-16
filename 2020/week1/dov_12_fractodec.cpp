#include <iostream>
#include <string.h>
#include <iomanip>
#include <cstdlib>
#include <vector>
using namespace std;

int numeric[1000000];
int ind[1000000];
vector<int> esv;

bool isfinitedeci(int n){
	while(n > 1){
		if(n % 2 == 0){
			n /= 2;
		}
		else if(n % 5 == 0){
			n /= 5;
		}
		else return false;
	}
	return true;
}



int main(void)
{
	int cn,pn;
	cin>>cn>>pn;
	int i = 0;
	int es = cn / pn;
	if(es > 0){
		cn -= es * pn;
	}
	int temp = es;
	while(temp != 0){
		esv.push_back(temp % 10);
		temp = temp / 10;
	}
	fill_n(ind,1000000,-1);
	int start,end;
	if(isfinitedeci(pn) || cn == 0){
		if(cn == 0) cout<<es<<".0";
		else{
			cout<<es<<".";
			cn *= 10;
			while(cn % pn != 0){
				if(cn < pn){
					cout<<"0";
					cn *= 10;
				}
				else{
					cout<<cn/pn;
					cn %= pn;
				}
			}
			cout<<cn/pn;
		}
		return 0;
	}
	else{
		ind[cn] = i++;
		while(1){
				numeric[i] = (cn * 10) / pn;
				if(ind[(cn * 10) % pn] != -1){
					start = ind[(cn * 10) % pn]; 
					end = i;
					break;
				} 
				else{
					ind[(cn * 10) % pn] = i;
				}
				cn = cn * 10 - pn * numeric[i];
				i++;
		}
	}
	cout<<es<<".";
	int count = 1 + esv.size();
	if(env.size() == 0) count++;
	for(int j = 1 ; j<= end ; j++){
		if(j == start+1) {cout<<"("; count++;}
		cout<<numeric[j];
		count++;
		if(count % 76 == 0) cout<<endl;
	}
	cout<<")";
}
