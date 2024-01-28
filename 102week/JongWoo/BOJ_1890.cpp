#include <iostream>

using namespace std;

int n;
int board[102][102];
long long dp[102][102];
int dx[] = { 1, 0 };
int dy[] = { 0, 1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
		}
	}

	dp[1][1] = 1;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			if (board[i][j] > 0)
			{
				for (int dir = 0; dir < 2; ++dir)
				{
					int nx = i + board[i][j] * dx[dir];
					int ny = j + board[i][j] * dy[dir];

					if ((nx > n) || (ny > n))
					{
						continue;
					}

					dp[nx][ny] += dp[i][j];
				}
			}
		}
	}

	//for (int i = 1; i <= n; ++i)
	//{
	//	for (int j = 1; j <= n; ++j)
	//	{
	//		cout << dp[i][j] << ' ';
	//	}

	//	cout << '\n';
	//}

	cout << dp[n][n] << '\n';
}
