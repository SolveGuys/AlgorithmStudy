#include <iostream>
#include <vector>
#include <algorithm>
#define endl '\n'
std::vector<int> m;
std::vector<int> c;
std::vector<std::vector<int>> dp;

int main()
{    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    // input
    int N, M; //1 ≤ N ≤ 100, 1 ≤ M ≤ 10,000,000
    std::cin >> N >> M;

    m.resize(N + 1);
    for (int i = 1; i < N + 1; ++i)
    {
        std::cin >> m[i];
    }
    c.resize(N + 1);
    int totalCost{};
    for (int i = 1; i < N + 1; ++i)
    {
        std::cin >> c[i];
        totalCost += c[i];
    }

    dp.resize(N + 1, std::vector<int>(totalCost + 1, 0));
    
    // 초깃값 설정
    for (int i = 0; i < totalCost + 1; ++i)
    {
        if (c[1] <= i)
            dp[1][i] = m[1];
    }

    // dp 계산
    for (int i = 1; i < N + 1; ++i)
    {
        for (int j = 0; j < totalCost + 1; ++j)
        {
            if (j - c[i] >= 0)
                dp[i][j] = std::max(dp[i - 1][j], dp[i - 1][j - c[i]] + m[i]);
            else
                dp[i][j] = dp[i - 1][j];       

            //std::cout << dp[i][j] << " ";
        }
        //std::cout << endl;
    }
    // 최소값 탐색
    for(int i = 1; i < totalCost + 1; ++i)
    {
        if (dp[N][i] >= M)
        {
            std::cout << i;
            break;
        }
    }

    return 0;
}