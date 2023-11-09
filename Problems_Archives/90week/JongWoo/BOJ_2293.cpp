#include <iostream>
#include <algorithm>

using namespace std;

int n, k;
int values[102];
int dp[10'002]; // dp[i]: i원을 만들 수 있는 경우의 수

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> k;

	for (int i = 1; i <= n; ++i)
	{
		cin >> values[i];
	}

	// 0원을 만드는 경우의 수는 아무 동전도 선택하지 않는 1개의 경우가 있다.
	dp[0] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = values[i]; j <= k; ++j)
		{
			dp[j] += dp[j - values[i]];
		}
	}

	cout << dp[k] << '\n';
}
