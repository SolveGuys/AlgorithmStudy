#include <iostream>
#include <queue>
#include <vector>
#include <utility>

using namespace std;

int n, m;
vector<pair<int, int>> switches[101][101];
bool isVisited[101][101];
bool isLight[101][101];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 0; i < m; ++i)
	{
		int x = 0, y = 0, a = 0, b = 0;

		cin >> x >> y >> a >> b;
		switches[x][y].emplace_back(a, b);
	}

	BFS();

	int answer = 0;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			answer += isLight[i][j];
		}
	}

	cout << answer << '\n';
}

void BFS()
{
	queue<pair<int, int>> q;

	isLight[1][1] = true;
	q.emplace(1, 1);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();

		// 해당 위치에 있는 스위치를 켠다.
		for (const auto& p : switches[x][y])
		{
			if (!isLight[p.first][p.second])
			{
				isLight[p.first][p.second] = true;

				// BFS의 방문 순서로 인해 스위치가 나중에 켜져서 이동하지 못했던 곳이라면 큐에 추가한다.
				// 불이 켜지는 위치의 인접칸(상, 하, 좌, 우)를 이미 방문했었다면 이 위치 또한 갈 수 있는 곳이라 판단할 수 있다.
				for (int i = 0; i < 4; ++i)
				{
					int nx = p.first + dx[i];
					int ny = p.second + dy[i];

					if ((nx < 1) || (nx > n) || (ny < 1) || (ny > n) || (!isVisited[nx][ny]))
					{
						continue;
					}

					isVisited[p.first][p.second] = true;
					q.emplace(p.first, p.second);
				}
			}
		}

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx < 1) || (nx > n) || (ny < 1) || (ny > n) || (isVisited[nx][ny]) || (!isLight[nx][ny]))
			{
				continue;
			}

			isVisited[nx][ny] = true;
			q.emplace(nx, ny);
		}
	}
}
