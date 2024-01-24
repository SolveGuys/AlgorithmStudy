#include <iostream>
#include <cstring>

using namespace std;

int dp[10'002]; // dp[i]: i원을 만들 수 있는 경우의 수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;
	
	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		int n = 0, m = 0;
		int coins[22] = {};

		cin >> n;

		for (int j = 0; j < n; ++j)
		{
			cin >> coins[j];
		}

		cin >> m;
		dp[0] = 1;

		for (int j = 0; j < n; ++j)
		{
			for (int k = coins[j]; k <= m; ++k)
			{
				dp[k] = dp[k] + dp[k - coins[j]];
			}
		}

		cout << dp[m] << '\n';
		memset(dp, 0, sizeof(dp));
	}
}
