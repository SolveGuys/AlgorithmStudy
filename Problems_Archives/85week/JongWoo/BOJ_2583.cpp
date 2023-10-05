#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, m, k;

int board[102][102];
bool isVisited[102][102];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS(int sx, int sy);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> m >> n >> k;

	for (int i = 0; i < k; ++i)
	{
		int ldx = 0, ldy = 0, rux = 0, ruy = 0;

		// 0 <= ldx < rux <= m
		// 0 <= ldy < rdy <= n
		cin >> ldy >> ldx >> ruy >> rux;

		for (int x = m - rux; x < m - ldx; ++x)
		{
			for (int y = ldy; y < ruy; ++y)
			{
				board[x][y] = 1;
			}
		}
	}

	vector<int> answer;

	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if ((board[i][j] == 0) && (!isVisited[i][j]))
			{
				int siz = BFS(i, j);

				answer.push_back(siz);
			}
		}
	}

	sort(answer.begin(), answer.end());
	cout << answer.size() << '\n';

	for (int siz : answer)
	{
		cout << siz << ' ';
	}
}

int BFS(int sx, int sy)
{
	queue<pair<int, int>> q;
	int siz = 0;

	isVisited[sx][sy] = true;
	q.emplace(sx, sy);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		++siz;

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx < 0) || (nx >= m) || (ny < 0) || (ny >= n) || (board[nx][ny] != 0) || (isVisited[nx][ny]))
			{
				continue;
			}

			isVisited[nx][ny] = true;
			q.emplace(nx, ny);
		}
	}

	return siz;
}
