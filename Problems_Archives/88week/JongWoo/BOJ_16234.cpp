#include <iostream>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

int n, l, r;
int board[52][52];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
bool isVisited[52][52];

bool BFS(int sx, int sy);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> l >> r;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> board[i][j];
		}
	}

	int answer = 0;

	while (true)
	{
		bool isMovable = false;

		// 방문여부 초기화
		for (int i = 0; i < n; ++i)
		{
			fill(isVisited[i], isVisited[i] + n, false);
		}

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < n; ++j)
			{
				if (!isVisited[i][j])
				{
					isMovable |= BFS(i, j);
				}
			}
		}

		if (!isMovable)
		{
			break;
		}

		++answer;
	}

	cout << answer << '\n';
}

bool BFS(int sx, int sy)
{
	bool isMovable = false;
	int tot = 0;

	queue<pair<int, int>> q;
	vector<pair<int, int>> coords;

	isVisited[sx][sy] = true;
	q.emplace(sx, sy);

	while (!q.empty())
	{
		int x = q.front().first;
		int y = q.front().second;

		q.pop();
		coords.emplace_back(x, y);
		tot += board[x][y];

		for (int i = 0; i < 4; ++i)
		{
			int nx = x + dx[i];
			int ny = y + dy[i];

			if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= n) || (isVisited[nx][ny]))
			{
				continue;
			}

			// 두 나라의 인구 차이
			int diff = abs(board[nx][ny] - board[x][y]);

			if ((l <= diff) && (diff <= r))
			{
				isVisited[nx][ny] = true;
				q.emplace(nx, ny);
			}
		}
	}

	// 두 나라의 인구 차이가 l명 이상, r명 이하여서 국경선을 열 수 있는 경우
	if (coords.size() >= 2)
	{
		isMovable = true;
		tot /= coords.size();

		for (const auto& c : coords)
		{
			int x = c.first;
			int y = c.second;

			board[x][y] = tot;
		}
	}

	return isMovable;
}
