#include <iostream>
#include <queue>

using namespace std;

struct Node
{
	int x;
	int y;
	int dist;
	bool isRemoved;
};

int n, m;
char board[1'001][1'001];

int answer;
bool isVisited[2][1'001][1'001];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int BFS();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= m; ++j)
		{
			cin >> board[i][j];
		}
	}

	cout << BFS() << '\n';
}

int BFS()
{
	int dist = -1;
	queue<Node> q;

	isVisited[0][1][1] = isVisited[1][1][1] = true;
	q.push({ 1, 1, 1, false });

	while (!q.empty())
	{
		Node cur = q.front();

		q.pop();

		if ((cur.x == n) && (cur.y == m))
		{
			dist = cur.dist;
			break;
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = cur.x + dx[i];
			int ny = cur.y + dy[i];

			// 범위를 벗어난 경우
			if ((nx < 1) || (nx > n) || (ny < 1) || (ny > m))
			{
				continue;
			}

			// 이전에 벽을 부순 적이 있다면, 방문하지 않았으면서 이동할 수 있는 곳(0)으로만 이동해야 한다.
			if (cur.isRemoved)
			{
				switch (board[nx][ny])
				{
				case '0': // 이동할 수 있는 곳
					if (!isVisited[1][nx][ny])
					{
						isVisited[1][nx][ny] = true;
						q.push({ nx, ny, cur.dist + 1, cur.isRemoved });
					}
					break;
				}
			}
			// 이전에 벽을 부순 적이 없다면, 방문하지 않았으면서 이동할 수 있는 곳(0)과 벽(1)으로 모두 이동이 가능하다.
			else
			{
				switch (board[nx][ny])
				{
				case '0': // 이동할 수 있는 곳
					if (!isVisited[0][nx][ny])
					{
						isVisited[0][nx][ny] = true;
						q.push({ nx, ny, cur.dist + 1, cur.isRemoved });
					}
					break;
				case '1': // 벽
					if (!isVisited[1][nx][ny])
					{
						isVisited[1][nx][ny] = true;
						q.push({ nx, ny, cur.dist + 1, !cur.isRemoved });
					}
					break;
				}
			}
		}
	}

	return dist;
}
