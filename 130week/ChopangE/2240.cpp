#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<tuple>
#include<map>

using namespace std;

int T, W;

int dp[3][31] = {-100000};
int main() {
	ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
	cin >> T >> W;
	vector<int> jadu(T);
	for ( int i = 0; i < T; i++ )
	{
		cin >> jadu[i];
	}
	if ( jadu[0] == 1 )
	{
		dp[1][0] = 1;
		dp[2][1] = 0;
	}
	else
	{
		dp[1][0] = 0;
		dp[2][1] = 1;
	}
	for ( int i = 1; i < T; i++ )
	{
		if ( jadu[i] == 1 )
		{
			for ( int j = 30; j >= 1; j-- )
			{
				dp[1][j] = max(dp[2][j - 1], dp[1][j]) + 1;

			}
			dp[1][0] += 1;

		}
		else
		{
			for ( int j = 30; j >= 1; j-- )
			{
				dp[2][j] = max(dp[2][j], dp[1][j - 1]) + 1;

			}

		}
	}
	int res = 0;
	for ( int i = 0; i <= W; i++ )
	{
		res = max(res, dp[1][i]);
		res = max(res, dp[2][i]);
	}
	cout << res << endl;
	return 0;

}