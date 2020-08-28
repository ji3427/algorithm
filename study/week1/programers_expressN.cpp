#include <string> 
#include <vector> 
#include <iostream>
#include <queue>
using namespace std; 

struct node{
	int cnt;
	int count;
	int next;
};


int solution(int N, int number) {
    int answer = 0;
    queue<node> q;
	node temp = {0,-1,N};
	q.push(temp);
	while(!q.empty()){
		node front = q.front();
		q.pop();
		if(temp.count > 8) return -1;
		if(temp.cnt == number) return temp.count;
		front.count++;
        //더하기
		temp = front;
		temp.cnt += temp.next;
		temp.next = N;
		if(temp.cnt > 0) q.push(temp);
        //빼기
		temp = front;
		temp.cnt -= temp.next;
		temp.next = N;
		if(temp.cnt > 0) q.push(temp);
        //곱하기
		temp = front;
		temp.cnt *= temp.next;
		temp.next = N;
		if(temp.cnt > 0) q.push(temp);
        //나누기
		temp = front;
        if(temp.next != 0){
			temp.cnt /= temp.next;
			temp.next = N;
            if(temp.cnt > 0) q.push(temp);
		}
        //NN 인경우
		temp = front;
		temp.next = temp.next * 10 + N;
		q.push(temp);
		//(N/N)인 경우
        temp = front;
		temp.next /= N;
		q.push(temp);
        //(N*N) 인경우
		temp = front;
		temp.next *= N;
		q.push(temp);
	}
    return answer;
}

int main(void){
	cout<<solution(5,26);
}
