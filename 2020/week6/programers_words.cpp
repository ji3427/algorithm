#include <iostream>
#include <string>
#include <vector>
#include <string.h>
using namespace std;



int dfs(string cur, string target, vector<string> words,int index,bool visit[50]){
    int ans = 9999;
    int min = 500;
    if(cur == target) return index;
    for(int i = 0 ; i < words.size() ; i++){
        if(visit[i] == false){
            int sameletter = 0;
            for(int k = 0 ; k < target.size() ; k++){
                if(cur[k] == words[i][k]) sameletter++;
            }
            if(sameletter == target.size() - 1){
                visit[i] = true;
                ans = dfs(words[i],target,words,index+1,visit);
                visit[i] = false;
            }
            if(ans < min) min = ans;
        }
    }
    return min;
}

int solution(string begin, string target, vector<string> words) {
    int answer = 0;
    bool visit[50];
    memset(visit,0,50);
    answer = dfs(begin,target,words,0,visit);
    if(answer == 500) return 0;
    return answer;
}


int main(void){
	vector<string> w{"cool","coal","doag","coag"};
	cout<<solution("kool","doag",w);

}
