#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>
#include <memory.h>

using namespace std;

struct Shark
{
	int x;
	int y;
	int size;
	int cnt;
};

int n;
int board[22][22];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS(Shark& shark);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	Shark shark = { 0, 0, 2, 0 };

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];

			if (board[i][j] == 9)
			{
				board[i][j] = 0;
				shark.x = i;
				shark.y = j;
			}
		}
	}

	int answer = 0;

	while (true)
	{
		int dist = BFS(shark);

		if (dist == 0)
		{
			break;
		}

		answer += dist;
	}

	cout << answer << '\n';
}

int BFS(Shark& shark)
{
	int ret = 0;
	int dist[22][22] = {};
	queue<pair<int, int>> q;

	for (int i = 1; i <= n; ++i)
	{
		memset(dist[i] + 1, -1, sizeof(int) * n);
	}

	dist[shark.x][shark.y] = 0;
	q.emplace(shark.x, shark.y);

	bool isFound = false;

	while (!q.empty())
	{
		isFound = false;

		int qSize = static_cast<int>(q.size());

		for (int i = 0; i < qSize; ++i)
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			for (int j = 0; j < 4; ++j)
			{
				int nx = x + dx[j];
				int ny = y + dy[j];

				if ((nx < 1) || (nx > n) || (ny < 1) || (ny > n) || (board[nx][ny] > shark.size) || (dist[nx][ny] != -1))
				{
					continue;
				}

				dist[nx][ny] = dist[x][y] + 1;
				q.emplace(nx, ny);

				if ((0 < board[nx][ny]) && (board[nx][ny] < shark.size))
				{
					isFound = true;
				}
			}
		}

		if (isFound)
		{
			break;
		}
	}

	if (isFound)
	{
		pair<int, int> target = {};

		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();

			if ((0 < board[x][y]) && (board[x][y] < shark.size))
			{
				if (((target.first == 0) && (target.second == 0)) ||
					 (x < target.first) ||
					((x == target.first) && (y < target.second)))
				{
					target.first = x;
					target.second = y;
				}
			}
		}

		board[target.first][target.second] = 0;
		shark.x = target.first;
		shark.y = target.second;
		++shark.cnt;

		if (shark.cnt == shark.size)
		{
			++shark.size;
			shark.cnt = 0;
		}

		ret = dist[target.first][target.second];
	}

	return ret;
}
