#include <iostream>

using namespace std;

int t, w;
int fall[1'001];
int dp[31][1'001]; // dp[i][j]: j초에 최대 i번(i <= j)까지 이동해서 받을 수 있는 자두의 최대 개수

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> t >> w;

    for (int i = 1; i <= t; ++i)
    {
        cin >> fall[i];
    }

    // 0, 2, 4, ... 짝수일 때는 1번 나무 밑
    // 1, 3, 5, ... 홀수일 때는 2번 나무 밑
    for (int i = 0; i <= w; ++i)
    {
        for (int j = 1; j <= t; ++j)
        {
            dp[i][j] = dp[i][j - 1] + ((i + 1) % 2 == fall[j] % 2);

            if (i > 0)
            {
                dp[i][j] = max(dp[i][j], dp[i - 1][j]);
            }
        }
    }

    cout << dp[w][t] << '\n';
}
