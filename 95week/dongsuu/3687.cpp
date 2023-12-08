#include <iostream>
#include <algorithm>
#include <limits.h>

using namespace std;

int T;
long long dp[105];
int num[8];

int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    std::fill(dp, dp+105, LONG_LONG_MAX / 100);
    
    dp[2] = 1;
    dp[3] = 7;
    dp[4] = 4;
    dp[5] = 2;
    dp[6] = 6;
    dp[7] = 8;
    
    num[2] = 1;
    num[3] = 7;
    num[4] = 4;
    num[5] = 2;
    num[6] = 0;
    num[7] = 8;
    
    // 작은 수 구하기
    for(int i=8; i<=100; i++){
        for(int j=2; j<=7; j++){
            dp[i] = std::min(dp[i], dp[i-j]*10 + num[j]);
        }
    }
    
    
    cin >> T;
    
    // 큰 수 구하기
    for(int i=0; i<T; i++){
        string max_value;
        
        cin >> n;
        
        // 짝수면 1을 가장 많이 사용해서 자릿수 늘리는게 가장 큰 수가 됨.
        if(n%2 == 0){
            int len = n / 2;
            for(int i=0; i<len; i++)
                max_value.push_back('1');
        } else { // 홀수면 첫 자리는 7로, 나머지는 1로 사용해서 자릿수 늘리는게 가장 큰 수가 됨.
            int len = n / 2 - 1;
            max_value.push_back('7');
            for(int i=0; i<len; i++){
                max_value.push_back('1');
            }
        }
        
        if(n == 6) dp[n] = 6; // 예외 처리
        cout << dp[n] << " " << max_value << '\n';
        
    }
    
    
    return 0;
}
