#include <iostream>

//dp[i][j] : i번째 j로 시작하는 수
int dp[1001][10];

int main()
{
    int n;
    std::cin >> n;
    for (int j = 0; j < 10; j++)
        dp[1][j] = 1;
    for (int i = 2; i <= n; i++) 
    for (int j = 0; j < 10; j++)
    for (int k = 0; k <= j; k++)
    {
        dp[i][j] += dp[i - 1][k];
        dp[i][j] %= 10007;
    }

    int a = 0;
    for (int j = 0; j < 10; j++)
    {
        a += dp[n][j];
        a %= 10007;
    }

    std::cout << a;
    return 0;
}