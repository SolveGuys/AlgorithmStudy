#include <iostream>
#include <vector>

struct RGB 
{
	int R, G, B;
};

const int big = 1e9;

int main()
{
	int n;
	std::cin >> n;
	std::vector<RGB> cost(n);
	std::vector<RGB> dp(n, { big,big,big });

	for (int i = 0; i < n; i++) 
	{
		std::cin >> cost[i].R >> cost[i].G >> cost[i].B;
	}

	dp[0] = { cost[0].R,cost[0].G,cost[0].B };

	for (int i = 1; i < n; i++) 
	{
		dp[i].R = std::min(dp[i].R, std::min(cost[i].R + dp[i - 1].G, cost[i].R + dp[i - 1].B));
		dp[i].G = std::min(dp[i].G, std::min(cost[i].G + dp[i - 1].R, cost[i].G + dp[i - 1].B));
		dp[i].B = std::min(dp[i].B, std::min(cost[i].B + dp[i - 1].G, cost[i].B + dp[i - 1].R));
	}

	std::cout << std::min(dp[n - 1].R, std::min(dp[n - 1].G, dp[n - 1].B));

	return 0;
}