#include <iostream>
#include <string>
#include <vector>
#include <deque>
using namespace std;

int q_sum(deque<int> q){
    int sum = 0;
    for(int n = 0 ; n < q.size() ; n++){
        sum += q[n];
    }
    return sum;
}


int solution(int bridge_length, int weight, vector<int> truck_weights) {
    int answer = 0;
    deque<int> b;
    int index = 0;
    do{
        answer++;
        if(q_sum(b) + truck_weights[index] <= weight) {b.push_back(truck_weights[index]); index++;}
        else if(index < truck_weights.size()) b.push_back(0);
        if(b.size() >= bridge_length) b.pop_front();
        if(index == truck_weights.size()){
			return answer + bridge_length;
		}
    }while(!b.empty());
}


int main(void){
	vector<int> t{10,10,10,10,10,10,10,10,10,10};
	cout<<solution(100,100,t);
}
