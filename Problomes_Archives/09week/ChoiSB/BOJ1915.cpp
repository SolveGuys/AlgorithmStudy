#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

int main()
{
    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int n, m; //  n, m(1 ≤ n, m ≤ 1,000)
    std::cin >> n >> m;
    std::vector<std::vector<int>> dp(n, std::vector<int>(m,0));
    for (int r = 0; r < n; ++r)
    {
        std::string str;
        std::cin >> str;
        for (int c = 0; c < m; ++c)
        {
            dp[r][c] = (int)(str[c] - '0');
        }
    }

    // dp[r][c]: r,c 위치에서 만들어지는 정사각형의 한 변의 길이
    for (int r = 1; r < n; r++)
    {
        for (int c = 1; c < m; c++)
        {
            if (dp[r][c] != 0)
            {
                dp[r][c] += std::min({ dp[r - 1][c], dp[r][c - 1], dp[r - 1][c - 1] });
            }
        }
    }

    int answer{};

    for (int r = 0; r < n; r++)
        for (int c = 0; c < m; c++)
            answer = std::max(answer, dp[r][c]);

    answer *= answer;
    std::cout << answer << std::endl;
    return 0;
}