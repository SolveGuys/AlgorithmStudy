#include <iostream>

using namespace std;

int n;
int dp[32];

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;
	dp[2] = 3;

	for (int i = 4; i <= n; i += 2)
	{
		dp[i] = dp[2] * dp[i - 2] + 2;

		for (int j = 4; j <= i - 2; j += 2)
		{
			dp[i] += 2 * dp[i - j];
		}
	}

	cout << dp[n] << '\n';
}
