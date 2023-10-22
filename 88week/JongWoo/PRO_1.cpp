#include <iostream>
#include <vector>

using namespace std;

// i = 0, money[0] = 1
// 1원은 0원을 거슬러 줄 수 있는 방법에 1원을 더해주면 되므로 dp[1] = (dp[1] + dp[0]) % MOD
// 2원은 1원을 거슬러 줄 수 있는 방법에 1원을 더해주면 되므로 dp[2] = (dp[2] + dp[1]) % MOD
// ...
// dp[1] = (dp[1] + dp[0]) % MOD = (0 + 1) % MOD = 1
// dp[2] = (dp[2] + dp[1]) % MOD = (0 + 1) % MOD = 1
// dp[3] = (dp[3] + dp[2]) % MOD = (0 + 1) % MOD = 1
// dp[4] = (dp[4] + dp[3]) % MOD = (0 + 1) % MOD = 1
// dp[5] = (dp[5] + dp[4]) % MOD = (0 + 1) % MOD = 1

// i = 1, money[1] = 2
// 2원은 0원을 거슬러 줄 수 있는 방법에 2원을 더해주면 되므로 dp[2] = (dp[2] + dp[0]) % MOD
// 3원은 1원을 거슬러 줄 수 있는 방법에 2원을 더해주면 되므로 dp[3] = (dp[3] + dp[1]) % MOD
// ...
// dp[2] = (dp[2] + dp[0]) % MOD = (1 + 1) % MOD = 2
// dp[3] = (dp[3] + dp[1]) % MOD = (1 + 1) % MDO = 2
// dp[4] = (dp[4] + dp[2]) % MOD = (1 + 2) % MOD = 3
// dp[5] = (dp[5] + dp[3]) % MOD = (1 + 2) % MOD = 3

// i = 2, money[2] = 5
// 5원은 0원을 거슬러 줄 수 있는 방법에 5원을 더해주면 되므로 dp[5] = (dp[5] + dp[0]) % MOD
// dp[5] = (dp[5] + dp[0]) % MOD = (3 + 1) % MOD = 4

// => 순서가 중요하다.

const int MOD = 1e9 + 7;

int dp[100'002]; // dp[i]: money에 있는 동전들로 i원을 거슬러 주는 방법의 수

int solution(int n, vector<int> money)
{
    int answer = 0;
    
    // 0원을 거슬러 주는 방법의 수는 아무 동전도 선택하지 않으면 되므로 1가지이다.
    dp[0] = 1;
    
    for (int i = 0; i < money.size(); ++i)
    {
        for (int j = money[i]; j <= n; ++j)
        {
            // dp[j - money[i]]: money[i]원짜리 동전을 포함했을 때 남은 금액을 채울 방법의 수
            dp[j] = (dp[j] + dp[j - money[i]]) % MOD;
        }
    }
    
    answer = dp[n];
    
    return answer;
}
