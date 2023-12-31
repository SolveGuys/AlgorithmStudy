#include <iostream>
#include <queue>
#include <utility>
#include <cstring>

using namespace std;

int n;
int board[102][102];

bool isVisited[102][102];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS(int sx, int sy, int h);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	int maxHeight = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
			maxHeight = max(maxHeight, board[i][j]);
		}
	}

	int answer = 0;

	for (int h = 0; h < maxHeight; ++h)
	{
		int cnt = 0;

		for (int i = 1; i <= n; ++i)
		{
			memset(isVisited[i], 0, sizeof(bool) * (n + 1));
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int j = 1; j <= n; ++j)
			{
				if ((board[i][j] <= h) || (isVisited[i][j]))
				{
					continue;
				}

				BFS(i, j, h);
				++cnt;
			}
		}

		answer = max(answer, cnt);
	}

	cout << answer << '\n';
}

void BFS(int sx, int sy, int h)
{
	queue<pair<int, int>> q;

	isVisited[sx][sy] = true;
	q.emplace(sx, sy);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx < 1) || (nx > n) || (ny < 1) || (ny > n) || (board[nx][ny] <= h) || (isVisited[nx][ny]))
			{
				continue;
			}

			isVisited[nx][ny] = true;
			q.emplace(nx, ny);
		}
	}
}
