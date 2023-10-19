#include <string>
#include <vector>
#include <algorithm>
#include <iostream>

using namespace std;

int dp[100005]; // i원을 만들 수 있는 경우의 수
int solution(int n, vector<int> money) {
    int answer = 0;

    dp[0] = 1; // 자기자신으로 만들 수 있는 경우는 1개
    
    for(int i=0; i<money.size(); i++){
        int cur = money[i]; // 현재 동전을 포함해서 만들 수 있는 경우의 수를 구한다.
        
        for(int j=cur; j<=n; j++){ // 현재 동전부터 n원까지 cur을 포함해 만들 수 있는 경우의 수를 구한다.
            
            // cur원을 포함해야 하므로 [j-cur]의 경우의수를 더해주면 된다. (j-cur + cur = j)
            dp[j] += dp[j-cur] % 1000000007;
        }
    }
    
    answer = dp[n] % 1000000007;
    return answer;
}
