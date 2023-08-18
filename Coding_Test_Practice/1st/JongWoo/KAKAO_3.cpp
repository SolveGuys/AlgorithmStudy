#include <string>
#include <vector>
#include <iostream>

#define INF 0x7f7f7f7f

using namespace std;

int dp[151][151]; // dp[i][j]: 알고력이 i, 코딩력이 j일 때의 최단 시간

int solution(int alp, int cop, vector<vector<int>> problems)
{
    int answer = 0;
    int maxAlp = 0, maxCop = 0;
    
    for (const auto& problem : problems)
    {
        if (problem[0] > maxAlp)
        {
            maxAlp = problem[0];
        }
        
        if (problem[1] > maxCop)
        {
            maxCop = problem[1];
        }
    }

    if ((alp >= maxAlp) && (cop >= maxCop))
    {
        return 0;
    }
    
    // 최댓값을 초과할 시 크기 조정
    if (alp > maxAlp)
    {
        alp = maxAlp;
    }
    
    if (cop > maxCop)
    {
        cop = maxCop;
    }
    
    for (int i = alp; i <= maxAlp; ++i)
    {
        for (int j = cop; j <= maxCop; ++j)
        {
            dp[i][j] = INF;
        }
    }
    
    dp[alp][cop] = 0;
    
    for (int i = alp; i <= maxAlp; ++i)
    {
        for (int j = cop; j <= maxCop; ++j)
        {  
            if (i + 1 <= maxAlp)
            {
                dp[i + 1][j] = min(dp[i + 1][j], dp[i][j] + 1); 
            }
            
            if (j + 1 <= maxCop)
            {
                dp[i][j + 1] = min(dp[i][j + 1], dp[i][j] + 1);                
            }
            
            for (const auto& problem : problems)
            {
                if ((i >= problem[0]) && (j >= problem[1]))
                {
                    int ni = (i + problem[2] > maxAlp) ? maxAlp : i + problem[2];
                    int nj = (j + problem[3] > maxCop) ? maxCop : j + problem[3];
                    
                    dp[ni][nj] = min(dp[ni][nj], dp[i][j] + problem[4]);
                }
            }
        }
    }
    
    answer = dp[maxAlp][maxCop];
    
    return answer;
}
