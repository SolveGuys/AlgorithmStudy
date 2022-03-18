#include <vector>

// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.
int solution(int n, int m, std::vector<std::vector<int>> edge_list, int k, std::vector<int> gps_log) {
    const int INF = 987654321;
    int answer = 0;
    
    std::vector<std::vector<int>> adj_list = std::vector(n+1,std::vector<int>());
    
    for(int i = 0; i < m; i++)
    {
        int start = edge_list[i][0];
        int end = edge_list[i][1];
        
        adj_list[start].push_back(end);
        adj_list[end].push_back(start);
    }
    
    std::vector<std::vector<int>> dp = std::vector(k,std::vector<int>(n+1,INF));
    
    dp[0][gps_log[0]] = 0;
        
    for(int i = 1; i < k; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            dp[i][j] = std::min(dp[i][j],dp[i-1][j]);
            
            for(int l = 0; l < adj_list[j].size(); l++)
                dp[i][j] = std::min(dp[i][j],dp[i-1][adj_list[j][l]]);

            
            if(j != gps_log[i])
                dp[i][j]++;
        }
    }
        
    if(dp[k-1][gps_log[k-1]] < INF)
        answer = dp[k-1][gps_log[k-1]];
    else answer = -1;
        
    return answer;
}