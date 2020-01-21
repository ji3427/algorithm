#include <iostream>
#include <cstdio>
#include <fstream>
#include <set>
#include <string>
using namespace std;
void sol(string,int,string);
char keymap[10][3] = {{0,0,0},{0,0,0},{'A','B','C'},{'D','E','F'},{'G','H','I'},{'J','K','L'},{'M','N','O'},{'P','R','S'},{'T','U','V'},{'W','X','Y'}};
set<string> dict;
int size = 0;
set<string>::iterator it;
int main(void)
{
	ifstream readFile;
	readFile.open("dict.txt");
	if(readFile.is_open()){
		while(!readFile.eof()){
			string str;
			getline(readFile,str);
			dict.insert(str);
		}
	}
	readFile.close();
	string serial;
	cin>>serial;
	string key;
	sol(serial,0,key);
	if(size == 0) cout<<"NONE"<<endl;
}

void sol(string serial,int index,string key){
	key.capacity();
	if(key.length() == serial.length()){
		if((it = dict.find(key)) != dict.end()) {cout<<key<<endl;size++;}
		return;
	}
	int mapindex = serial.at(index) - '0';
	for(int i = 0 ; i < 3 ; i++){
		key.push_back(keymap[mapindex][i]);
		sol(serial,index+1,key);
		key.pop_back();
	}
}
