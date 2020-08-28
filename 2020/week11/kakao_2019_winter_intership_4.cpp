#include <string>
#include <vector>
#include <iostream>
#include <unordered_map>
 
using namespace std;
 
unordered_map<long long, long long> m;
vector<long long> answer;
 
long long find_num(long long n){
    if(m[n] == 0){
        m[n] = n + 1;
        answer.emplace_back(n);
        return n;
    }
    return m[n] = find_num(m[n]);
}
 
vector<long long> solution(long long k, vector<long long> room_number) {
    m.reserve(200002);
    answer.reserve(200002);
    
    for(int i = 0; i < room_number.size(); i++){
        long long n = room_number[i];
        if(m[n] == 0){
            answer.emplace_back(n);
            m[n] = n + 1;
        }else 
           find_num(n);
    }
    
    return answer;
}
