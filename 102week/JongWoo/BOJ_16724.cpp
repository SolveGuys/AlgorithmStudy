#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int n, m;
char board[1'002][1'002];
bool isVisited[1'002][1'002];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS(int sx, int sy);

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

	int answer = 0;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (isVisited[i][j])
			{
				continue;
			}

			answer += BFS(i, j);
		}
	}

	cout << answer << '\n';
}

int BFS(int sx, int sy)
{
	queue<pair<int, int>> q;
	vector<pair<int, int>> track;

	isVisited[sx][sy] = true;
	q.emplace(sx, sy);
	track.emplace_back(sx, sy);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		int dir = -1;

		switch (board[x][y])
		{
		case 'U': dir = 0; break;
		case 'D': dir = 1; break;
		case 'L': dir = 2; break;
		case 'R': dir = 3; break;
		}

		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (isVisited[nx][ny])
		{
			bool isFound = false;

			for (const auto& pos : track)
			{
				if ((nx == pos.first) && (ny == pos.second))
				{
					isFound = true;
					break;
				}
			}

			if (isFound)
			{
				break;
			}
			else
			{
				return 0;
			}
		}

		isVisited[nx][ny] = true;
		q.emplace(nx, ny);
		track.emplace_back(nx, ny);
	}
	
	return 1;
}
