#include <bits/stdc++.h>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	int n;
	std::cin >> n;

    const int max = 17;
	int times[max] = {0,};
	int pays[max] = {0,};
	for (int i = 1; i <= n; i++) 
	{
		int time, pay;
		std::cin >> time >> pay;

		times[i] = time;
		pays[i] = pay;
	}

	int dp[max] = {0,};
	for (int i = n; i > 0; i--) 
	{
		int deadline = i + times[i];

		if (deadline > n+1) 
		{
			dp[i] = dp[i+1];
		}
		else 
		{
			dp[i] = std::max(dp[i+1],dp[deadline] + pays[i]);
		}
	}
	std::cout << dp[1];
	return 0;
}