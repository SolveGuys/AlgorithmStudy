#include <iostream>

using namespace std;

int n;
int board[22][22];

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

	int answer = 0x3fffffff;

	for (int brute = 1; brute < (1 << n); ++brute)
	{
		int tmp = brute;
		bool isStartTeam[22] = {};

		for (int i = 1; i <= n; ++i)
		{
			if (tmp & 1)
			{
				isStartTeam[i] = true;
			}

			tmp >>= 1;
		}

		int start = 0, link = 0;

		for (int i = 1; i <= n; ++i)
		{
			for (int j = i + 1; j <= n; ++j)
			{
				if (isStartTeam[i] == isStartTeam[j])
				{
					if (isStartTeam[i])
					{
						start += (board[i][j] + board[j][i]);
					}
					else
					{
						link += (board[i][j] + board[j][i]);
					}
				}
			}
		}

		int diff = abs(start - link);

		if (diff == 0)
		{
			answer = diff;
			break;
		}

		answer = min(answer, diff);
	}

	cout << answer << '\n';
}
