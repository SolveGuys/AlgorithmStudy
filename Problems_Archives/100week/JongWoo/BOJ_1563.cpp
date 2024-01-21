#include <iostream>

using namespace std;

const int MOD = 1'000'000;

int n;
int dp[1'002][2][3]; // dp[i][j][k]: i일차에 지각을 j번, 연속 결석을 k번 했을 때, 개근상을 받을 수 있는 경우의 수 (j + k <= i)

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	// 1일차
	//	1. dp[1][0][0]: 지각X, 결석X
	//	2. dp[1][0][1]: 지각X, 결석O
	//	3. dp[1][1][0]: 지각O, 결석X
	dp[1][0][0] = dp[1][0][1] = dp[1][1][0] = 1;

	// 2 ~ n일차
	for (int i = 2; i <= n; ++i)
	{
		// i번째까지 지각 0번, 연속 결석이 0번인 경우(i - 1번째까지 연속 결석 횟수에 상관 없이 i번째에 출석하는 경우(연속 결석 초기화))
		dp[i][0][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2]) % MOD;

		// i번째까지 지각 0번, 연속 결석이 1번인 경우(i - 1번째까지 연속 결석을 0번하다가 i번째에 결석하여 연속 결석이 1번이 되는 경우)
		dp[i][0][1] = dp[i - 1][0][0];

		// i번째까지 지각 0번, 연속 결석이 2번인 경우(i - 1번째까지 연속 결석을 1번하다가 i번째에 결석하여 연속 결석이 2번이 되는 경우)
		dp[i][0][2] = dp[i - 1][0][1];

		// i번째까지 지각 1번, 연속 결석이 0번인 경우(i - 1번째까지 연속 결석 횟수에 상관 없이 i번째에 지각 하는 경우(연속 결석 초기화))
		dp[i][1][0] = (dp[i - 1][0][0] + dp[i - 1][0][1] + dp[i - 1][0][2] + dp[i - 1][1][0] + dp[i - 1][1][1] + dp[i - 1][1][2]) % MOD;
		
		// i번째까지 지각 1번, 연속 결석이 1번인 경우(i - 1번째까지 지각을 1번하고, 연속 결석을 0번하다가 i번째에 결석하여 연속 결석이 1번이 되는 경우)
		dp[i][1][1] = dp[i - 1][1][0];
		
		// i번째까지 지각 1번, 연속 결석이 2번인 경우(i - 1번째까지 지각을 1번하고, 연속 결석을 1번하다가 i번째에 결석하여 연속 결석이 2번이 되는 경우)
		dp[i][1][2] = dp[i - 1][1][1];
	}

	// n일차에 될 수 있는 모든 경우의 합
	cout << (dp[n][0][0] + dp[n][0][1] + dp[n][0][2] + dp[n][1][0] + dp[n][1][1] + dp[n][1][2]) % MOD << '\n';
}