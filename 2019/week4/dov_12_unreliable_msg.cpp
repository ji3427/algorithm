#include <iostream>
#include <deque>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;

int main(void)
{
	char command[10];
	cin>>command;
	deque<char> cl;
	cin.ignore();
	while(1){
		char temp = cin.get();
		if(temp == '\n') break;
		cl.push_back(temp);
	}
	int start = 0;
	for(int i = strlen(command) - 1 ; i >= 0 ; i-- ){
		if(command[i] == 'J'){
			 cl.push_front(cl.back());
			 cl.pop_back();
		}
		else if(command[i] == 'C'){
			cl.push_back(cl.front());
			cl.pop_front();
		}
		else if(command[i] == 'E')
		{
			int start = 0;
			int fix = ceil(cl.size()/2.0);
			for(int i = 0 ; i < fix ; i++){
				if(i+fix == cl.size()) break;
				char temp = cl[i];
				cl[i] = cl[i+fix];
				cl[i+fix] = temp;
			}
		}
		else if(command[i] == 'A'){
			reverse(cl.begin(),cl.end());
		}
		else if(command[i] == 'P'){
			for(int i = 0 ; i < cl.size() ; i++){
				if(cl[i] <= '9' && cl[i] >= '0'){
					cl[i]--;
					if(cl[i] < '0') cl[i] = '9';
				}
			}
		}
		else if(command[i] == 'M'){
			for(int i = 0 ; i < cl.size() ; i++){
				if(cl[i] <= '9' && cl[i] >= '0'){
					cl[i]++;
					if(cl[i] > '9') cl[i] = '0';
				}
			}
		}

	}
	for(int i = 0 ; i < cl.size() ; i++)
		cout<<cl[i];
}
