#include <iostream>
#include <array>
#include <algorithm>
#define endl '\n'
const int INF = 987'654'321;
struct Matrix {
    int row;
    int col;
};
int main()
{    //입출력 성능향상을 위한 설정
    std::ios_base::sync_with_stdio(false);
    std::cout.tie(NULL);
    std::cin.tie(NULL);

    int N; // 행렬의 개수 N(1 ≤ N ≤ 500)
    std::cin >> N;
    std::array<Matrix, 500> matArr;
    std::array<std::array<int, 501>, 501> dp{ };
    for (auto& row : dp)
    {
        row.fill(INF);
    }

    for (int i = 0; i < N; ++i)
    {
        std::cin >> matArr[i].row >> matArr[i].col;
    }

    //dp[1][i]: i위치에서 1개 행렬을 선택할 경우 곱셈수: 항상 0
    for (int i = 0; i < N + 1; ++i)
    {
        dp[1][i] = 0;
    }

    //dp[n][p]: p위치에서 n개일때 최솟값
    for (int n = 2; n < N + 1; n++)
    {
        for (int p = 0; p + n < N + 1; p++)
        {
            for (int k = 1; k < n; ++k)
            {
                int a = dp[k][p] + dp[n - k][p + k] + (matArr[p].row * matArr[p+k].row * matArr[p + n - 1].col);
                dp[n][p] = std::min(dp[n][p], a);
            }
        }
    }
    std::cout << dp[N][0];
    return 0;
}