#include <bits/stdc++.h>

int grade[6];
int teer[128];
std::vector<int> months;
std::vector<int> dp;

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cout.tie(nullptr);
	std::cin.tie(nullptr);

	for (int i = 0; i < 5; i++) 
		teer["BSGPD"[i]] = i;

	int n;
	std::cin >> n;
	std::cin >> grade[1] >> grade[2] >> grade[3] >> grade[4];
	grade[5] = 1e9;
	dp.resize(n+2);
	months.resize(n+2);
	for (int i = 0; i < n; i++)
	{
		char mon;
		std::cin >> mon;
		months[i] = teer[mon];
	}
	months[n] = 4;
	dp[0] = std::min(grade[4], grade[months[0] + 1] - 1);

	for (int i = 1; i < n; i++)
		dp[i] = std::min({ grade[months[i] + 1] - 1 - dp[i - 1], grade[months[i + 1] + 1] - 1, grade[4] });

	int ans = 0;
	std::cout << std::accumulate(dp.begin(), dp.end(), ans);

	return 0;
}