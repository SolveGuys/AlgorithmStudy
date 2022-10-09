#include <bits/stdc++.h>

int main()
{
	std::cin.tie(nullptr)->sync_with_stdio(false);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;
	std::vector<int> nums(n);
	for (int i = 0; i < n; i++)
	{
		std::cin >> nums[i];
	}

	std::vector<int> dp(n);
	dp[0] = nums[0];
	dp[1] = nums[1] + nums[0];
	dp[2] = std::max(nums[0] + nums[1], nums[0] + nums[2] );
	dp[2] = std::max(dp[2],nums[1] + nums[2]);
	for (int i = 3; i < n; i++) 
	{
		dp[i] = std::max( dp[i-2] + nums[i], dp[i-3] + nums[i] + nums[i-1]);
		dp[i] = std::max( dp[i],dp[i-1]);
	}
	
	std::cout << dp[n-1];
	
	return 0;
}