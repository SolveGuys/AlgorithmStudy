#include <iostream>
#include <algorithm>

using namespace std;

// BB
// BB

// BB WW BW WB WW WW  WW BB WB BW
// BB WW WW WW BW WB  BB WW WB BW

// WB WB
// BB BW

// BW BW
// BB WB

// BB [BW]
// WB [WB]

// BB [WB]
// BW [BW]

const int MOD = 1e9 + 7;

int n, m;
char board[2'002][2'002];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
long long pow2[4'000'002];

long long Pow(long long num, long long expo);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	int cnt = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			int sameCnt = 4;

			for (int dir = 0; dir < 4; ++dir)
			{
				int ni = i + dx[dir];
				int nj = j + dy[dir];

				if ((ni < 0) || (ni >= n) || (nj < 0) || (nj >= m))
				{
					continue;
				}

				if ((board[i][j] != board[ni][nj]))
				{
					--sameCnt;
				}
			}

			if (sameCnt == 4)
			{
				++cnt;
			}
		}
	}

	fill(pow2, pow2 + 4'000'002, -1);
	cout << Pow(2, cnt) << '\n';
}

long long Pow(long long num, long long expo)
{
	if (expo == 1)
	{
		pow2[expo] = 2;
	}
	else if (pow2[expo] == -1)
	{
		long long half = Pow(num, expo / 2);

		pow2[expo] = (half * half) % MOD;

		if (expo % 2 == 1)
		{
			pow2[expo] = (2 * pow2[expo]) % MOD;
		}
	}

	return pow2[expo];
}
