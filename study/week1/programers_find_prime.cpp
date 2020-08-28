#include <string>
#include <vector>
#include <algorithm>
#include <set>

using namespace std;

bool isPrime(int num) {
    if(num == 1) return false;
    if(num == 2) return true;
    
    for(int i=2; i<=sqrt(num); i++) {
        if(num % i == 0) return false;
    }
    return true;
}

int solution(string numbers) {
    int answer = 0;
    string s = numbers;
    sort(s.begin(), s.end(), greater<char>());
    vector<bool> prime(stoi(s) + 1);
    
    prime[0] = false;
    for(long long i=1; i<prime.size(); i++) {
        prime[i] = isPrime(i);
    }
    
    sort(numbers.begin(), numbers.end());
    set<int> ans;
    
    do{
        for(int i=1; i<=numbers.size(); i++) {
            string tmp = numbers.substr(0, i);
            if(prime[stoi(tmp)]) {
                ans.insert(stoi(tmp));
            }
        }
    } while(next_permutation(numbers.begin(), numbers.end()));
    
    return ans.size();;
}
