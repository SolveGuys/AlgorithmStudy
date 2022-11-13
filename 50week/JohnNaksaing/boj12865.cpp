#include <bits/stdc++.h>

int main() 
{
	int n, k;
	std::cin >> n >> k;

	std::vector<int> weight(n), value(n), dp(k+1);

	for (int i = 0; i < n; i++) 
	{
		std::cin >> weight[i] >> value[i];
	}

	for (int i = 0; i < n; i++) 
	{
		for (int j = k; j >= weight[i]; j--)
		{
			dp[j] = std::max(dp[j], dp[j - weight[i]] + value[i]);
		}
	}

	int answer = dp.back();
	return std::cout << answer, 0;
}