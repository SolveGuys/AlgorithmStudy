#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m, islandCnt;
int board[12][12];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<pair<int, int>> islandArea[8];
vector<tuple<int, int, int>> edges; // <cost, u, v>

void BFS(int sx, int sy);
void GetEdges(int st);
int Kruskal();
int GetRoot(int v, int* parents);
void SetUnion(int root1, int root2, int* parents);

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

			// 섬에 번호를 붙이기 위해서 우선은 -1로 설정 해둔다.
			if (board[i][j] == 1)
			{
				board[i][j] = -1;
			}
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			if (board[i][j] == -1)
			{
				++islandCnt;
				BFS(i, j);
			}
		}
	}

	for (int i = 1; i <= islandCnt; ++i)
	{
		GetEdges(i);
	}

	cout << Kruskal() << '\n';
}

void BFS(int sx, int sy)
{
	queue<pair<int, int>> q;

	board[sx][sy] = islandCnt;
	q.emplace(sx, sy);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		islandArea[islandCnt].emplace_back(x, y);

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m) || (board[nx][ny] != -1))
			{
				continue;
			}

			board[nx][ny] = islandCnt;
			q.emplace(nx, ny);
		}
	}
}

void GetEdges(int st)
{
	for (int i = 0; i < islandArea[st].size(); ++i)
	{
		int x = islandArea[st][i].first;
		int y = islandArea[st][i].second;
		int len = 0;

		for (int j = 0; j < 4; ++j)
		{
			int nx = x;
			int ny = y;
			int len = 0;
			bool isConnected = true;

			while (true)
			{
				nx += dx[j];
				ny += dy[j];

				if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m) || (board[nx][ny] == st))
				{
					isConnected = false;
					break;
				}
				else if (board[nx][ny] != 0)
				{
					break;
				}

				++len;
			}

			if ((isConnected) && (len >= 2))
			{
				edges.emplace_back(len, st, board[nx][ny]);
			}
		}
	}
}

int Kruskal()
{
	int minCost = 0;
	int parents[8] = {};

	for (int i = 1; i <= islandCnt; ++i)
	{
		parents[i] = i;
	}

	sort(edges.begin(), edges.end());

	int cnt = 0;

	for (const auto& e : edges)
	{
		int cost = get<0>(e);
		int root1 = GetRoot(get<1>(e), parents);
		int root2 = GetRoot(get<2>(e), parents);

		if (root1 != root2)
		{
			SetUnion(root1, root2, parents);
			minCost += cost;
			++cnt;

			if (cnt == islandCnt - 1)
			{
				break;
			}
		}
	}

	return (cnt == islandCnt - 1) ? minCost : -1;
}

int GetRoot(int v, int* parents)
{
	if (v == parents[v])
	{
		return v;
	}

	return parents[v] = GetRoot(parents[v], parents);
}

void SetUnion(int root1, int root2, int* parents)
{
	if (root1 <= root2)
	{
		parents[root2] = root1;
	}
	else
	{
		parents[root1] = root2;
	}
}
