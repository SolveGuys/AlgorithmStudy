#include <iostream>
#include <algorithm>
#include <vector>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> nums(n);
	std::vector<std::vector<int>> dp(2,std::vector<int>(n,1));

	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}

	for (int i = 0; i < n; i++)
	for (int j = 0; j < i; j++)
	{
		if (nums[j] < nums[i])
			dp[0][i] = std::max(dp[0][i], dp[0][j] + 1);
	}
	for (int i = n - 1; i >= 0; i--) 
	for (int j = n-1; j > i; j--)
	{
		if (nums[i] > nums[j])
			dp[1][i] = std::max(dp[1][i], dp[1][j] + 1);
	}

	int ans = 0;
	for (int i = 0; i < n; i++)
	{
		ans = std::max(ans,dp[0][i] + dp[1][i]-1);
	}

	std::cout << ans;
	return 0;
}