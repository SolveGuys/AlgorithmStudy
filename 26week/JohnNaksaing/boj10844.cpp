#include <cstdio>

int main() 
{
	long n;
	scanf("%d",&n);
	
	long dp[100][9] = 
	{
		{1, 1, 1, 1, 1, 1, 1, 1, 1}, 
		{2, 2, 2, 2, 2, 2, 2, 2, 1}, 

	};

	constexpr int by_mod = 1'000'000'000;
	
	for (int i = 2; i < n; i++) 
	{
        //앞 자리수가 1
		dp[i][0] = (dp[i-2][0] + dp[i-1][1]) % by_mod;
        //나머지
		for (int j = 1; j < 8; j++) 
		{
			dp[i][j] = (dp[i - 1][j - 1] + dp[i - 1][j + 1]) % by_mod;
		}
        //앞 자리수가 9
		dp[i][8] = dp[i-1][7];
	}
	
	long result{};

	for (int i = 0; i < 9; i++)
		result += dp[n - 1][i];

	printf("%d", result % by_mod);

	return 0;
}
