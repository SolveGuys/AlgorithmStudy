#include <iostream>
#include <vector>

using namespace std;

const int MOD = 1e9 + 7;

bool isPuddle[102][102];
int dp[102][102];

int solution(int m, int n, vector<vector<int>> puddles)
{
    int answer = 0;
    
    for (const vector<int>& p : puddles)
    {
        isPuddle[p[1]][p[0]] = true;
    }
    
    dp[1][1] = 1;
    
    for (int i = 1; i <= m; ++i)
    {
        for (int j = 1; j <= n; ++j)
        {
            if (((i == 1) && (j == 1)) || (isPuddle[i][j]))
            {
                continue;
            }
            
            int fromUp = (isPuddle[i - 1][j]) ? 0 : dp[i - 1][j];
            int fromLeft = (isPuddle[i][j - 1]) ? 0 : dp[i][j - 1];
            
            dp[i][j] = (fromUp + fromLeft) % MOD;
        }
    }
    
//     for (int i = 1; i <= m; ++i)
//     {
//         for (int j = 1; j <= n; ++j)
//         {
//             cout << dp[i][j] << ' ';
//         }
        
//         cout << '\n';
//     }
    
    answer = dp[m][n];
    
    return answer;
}
