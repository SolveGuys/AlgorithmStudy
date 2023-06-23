#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;

int N;
int prime_number[4000001]; // 1: true , -1: false
vector<int> prime;
int ans;

// "에라토스테네스의 체" 를 활용해 소수 구하기
void setPrimeNumber(int n){
    int c = n;
    while(n <= N){
        if(prime_number[n] != 1)
            prime_number[n] = -1; // 소수가 아닌 수 check
        n += c; // n의 배수
    }
}

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    // Input
    cin >> N;
    
    // Set Prime Number Array
    for(int i=2; i<= N; i++){
        if(prime_number[i] == 0) {
            prime_number[i] = 1;
            prime.push_back(i);
        }
        setPrimeNumber(i);
    }
    
    
    int st = 0;
    int en = 0;
    int sum = 0;
    
    if(N == 1){ // 예외 케이스
        cout << 0;
        return 0;
    }
    
    while(1){
        // sum < N인 경우 st를 옮겨서 값을 줄여줘야함.
        if(sum < N){
            if(en == prime.size() && st == prime.size() - 1) break; // 종료 조건
            sum += prime[en];
            en++;
            
        } else if(sum > N){ // sum > N인 경우 en을 옮겨 값을 키워줘야함.
            sum -= prime[st];
            st++;
        } else { // sum == N인 경우 st를 움직이면 값이 줄어들기 때문에 어차피 N에 도달하지 못함 -> en을 움직여 값을 키워줘야함. (정답 count)
            ans++;
            if(en == prime.size() && st == prime.size() - 1) break; // 종료 조건
            sum += prime[en];
            en++;
        }
    }
    
    cout << ans;
    
    
    return 0;
}
