#include <string>
#include <algorithm>
#include <vector>
#include <math.h>
#include <iostream>

using namespace std;

vector<int> dec_to_binary(int n){
    vector<int> binary;
    while(n != 0){
        binary.push_back(n%2);
        n /= 2;
    }
    binary.push_back(0);
    reverse(binary.begin(),binary.end());
    return binary;
}

int binary_to_dec(vector<int> binary){
    int sum = 0;
    int next = 1;
    reverse(binary.begin(),binary.end());
    for(int i = 0 ; i < binary.size() ; i++){
        if(binary[i] == 0){
             next *= 2;
            continue;
        } 
        sum += (next * binary[i]);
        next*=2;
    }
    return sum;
}

int solution(int n) {
    int answer = 0;
    vector<int> b1 = dec_to_binary(n);
    int before = n;
    next_permutation(b1.begin(),b1.end());
    answer = binary_to_dec(b1);
    return answer;
}

int main(void){
	cout<<solution(15);
}
