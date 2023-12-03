#include <iostream>
#include <vector>
#include <utility>

using namespace std;

const int INF = 0x3fffffff;

int n;
int board[102][102];
vector<vector<pair<int, int>>> delta[5] =
{
	// 조각1
	{
		// 0도
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 0, 3 } },
		
		// 90도
		{ { 0, 0 }, { 1, 0 }, { 2, 0 }, { 3, 0 } }
	},

	// 조각2
	{
		// 0도
		{ { 0, 0 }, { 0, 1 }, { 1, 1 }, { 1, 2 } },

		// 90도
		{ { 0, 1 }, { 1, 1 }, { 1, 0 }, { 2, 0 } },
	},

	// 조각3
	{
		// 0도
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 2 } },

		// 90도
		{ { 0, 1 }, { 1, 1 }, { 2, 1 }, { 2, 0 } },

		// 180도
		{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },

		// 270도
		{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 2, 0 } }
	},

	// 조각4
	{
		// 0도
		{ { 0, 0 }, { 0, 1 }, { 0, 2 }, { 1, 1 } },

		// 90도
		{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 2, 1 } },

		// 180도
		{ { 0, 1 }, { 1, 0 }, { 1, 1 }, { 1, 2 } },

		// 270도
		{ { 0, 0 }, { 1, 0 }, { 1, 1 }, { 2, 0 } }
	},

	// 조각5
	{
		// 0도
		{ { 0, 0 }, { 0, 1 }, { 1, 0 }, { 1, 1 } }
	}
};

int Simulate(int sx, int sy, int pieceNum, int rot);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1;

	while (true)
	{
		cin >> n;

		if (n == 0)
		{
			break;
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				cin >> board[i][j];
			}
		}

		int answer = -INF;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				for (int p = 0; p < 5; ++p)
				{
					for (int rot = 0; rot < delta[p].size(); ++rot)
					{
						answer = max(answer, Simulate(i, j, p, rot));
					}
				}
			}
		}

		cout << t++ << ". " << answer << '\n';
	}
}

int Simulate(int sx, int sy, int pieceNum, int rot)
{
	int ret = 0;

	for (int i = 0; i < 4; ++i)
	{
		int x = sx + delta[pieceNum][rot][i].first;
		int y = sy + delta[pieceNum][rot][i].second;

		if ((x >= n) || (y >= n))
		{
			return -INF;
		}

		ret += board[x][y];
	}

	return ret;
}
