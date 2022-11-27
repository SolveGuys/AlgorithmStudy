#include<bits/stdc++.h>
//	4156	92
int main()
{
    std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);
    
	int t;
	std::cin >> t;
	while (t--) 
	{
		int n;
		std::cin >> n;

		std::vector<std::vector<int>> stik(2, std::vector<int>(n));

		for (int i = 0; i < n; i++)
			std::cin >> stik[0][i];
		for (int i = 0; i < n; i++)
			std::cin >> stik[1][i];

		std::vector<std::vector<int>> dp(2, std::vector<int>(n));


		dp[0][0] = stik[0][0];
		dp[1][0] = stik[1][0];
		
		dp[0][1] = stik[0][1] + stik[1][0];
		dp[1][1] = stik[1][1] + stik[0][0];
		
		for (int i = 2; i < n; i++)
		{
			dp[0][i] = stik[0][i] + std::max(dp[1][i - 1], dp[1][i - 2]);
			dp[1][i] = stik[1][i] + std::max(dp[0][i - 1], dp[0][i - 2]);
		}

		std::cout << std::max(dp[0][n-1],dp[1][n-1]) << '\n';
	}

	return 0;
}