#include <iostream>
#include <algorithm>

using namespace std;

const int MAX = 0x3fffffff;

int n;
int arr[1'002];
int dp[1'002];

int DFS(int cur);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	fill(dp, dp + n, -1);
	cout << DFS(0) << '\n';
}

int DFS(int cur)
{
	if (cur == n)
	{
		return 0;
	}
	else if (dp[cur] == -1)
	{
		int low = MAX, high = -1;

		for (int i = cur; i < n; ++i)
		{
			low = min(low, arr[i]);
			high = max(high, arr[i]);
			dp[cur] = max(dp[cur], (high - low) + DFS(i + 1));
		}
	}

	return dp[cur];
}
