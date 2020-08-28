#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <map>
using namespace std;

struct data{
	int type;
	string uid;
};


vector<string> solution(vector<string> record) {
    vector<string> answer;
    map<string,string> m;
    vector<data> d;
    for(int i = 0 ; i < record.size() ; i++){
		stringstream ss(record[i]);
		vector<string> in;
		string temp;
		while(getline(ss,temp,' ')){
			in.push_back(temp);
		}
		if(in[0][0] == 'C'){
			m[in[1]] = in[2]; 
		}
		else{
			data a;
			a.uid = in[1];
			if(in[0][0] == 'E'){
				a.type = 0;
				if(m.find(in[1]) == m.end()) m.insert(make_pair(in[1],in[2]));
				else m[in[1]] = in[2];
			} 
			else if(in[0][0] == 'L') a.type = 1;
			d.push_back(a);

		}
	}
	for(int i = 0 ; i < d.size() ; i++){
		string msg;
		msg += m[d[i].uid];
		if(d[i].type == 0) msg+= "님이 들어왔습니다.";
		else if(d[i].type == 1) msg+= "님이 나갔습니다.";
		answer.push_back(msg);
	}
    return answer;
    
}

int main(void){
	vector<string> r = {"Enter uid1234 Muzi", "Enter uid4567 Prodo","Leave uid1234","Enter uid1234 Prodo","Change uid4567 Ryan"};
	vector<string> a = solution(r);
	for(string i : a){
		cout<<i<<endl;
	}
}
