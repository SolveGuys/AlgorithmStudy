#include <iostream>
#include <deque>
#include <utility>

using namespace std;

int n, m;
int board[52][52];
int dx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int dy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
		}
	}

	deque<pair<int, int>> deq;

	deq.emplace_back(n - 1, 1);
	deq.emplace_back(n - 1, 2);
	deq.emplace_back(n, 1);
	deq.emplace_back(n, 2);

	for (int i = 0; i < m; ++i)
	{
		int d = 0, s = 0;

		cin >> d >> s;

		int delta[52][52] = {};
		bool check[52][52] = {};
		int deqSize = static_cast<int>(deq.size());

		for (int j = 0; j < deqSize; ++j)
		{
			int x = deq.front().first;
			int y = deq.front().second;
			int nx = x + dx[d] * (s % n);
			int ny = y + dy[d] * (s % n);

			deq.pop_front();

			if (nx < 1)
			{
				nx = n + nx;
			}
			else if (nx > n)
			{
				nx = nx - n;
			}

			if (ny < 1)
			{
				ny = n + ny;
			}
			else if (ny > n)
			{
				ny = ny - n;
			}

			++board[nx][ny];
			check[nx][ny] = true;
			deq.emplace_back(nx, ny);
		}

		deqSize = static_cast<int>(deq.size());

		for (int j = 0; j < deqSize; ++j)
		{
			int cnt = 0;

			for (int dir : { 2, 4, 6, 8 })
			{
				int nx = deq[j].first + dx[dir];
				int ny = deq[j].second + dy[dir];

				if ((nx < 1) || (nx > n) || (ny < 1) || (ny > n) || (board[nx][ny] == 0))
				{
					continue;
				}

				++cnt;
			}

			delta[deq[j].first][deq[j].second] += cnt;
		}
	
		deq.clear();

		for (int r = 1; r <= n; ++r)
		{
			for (int c = 1; c <= n; ++c)
			{
				board[r][c] += delta[r][c];

				if ((!check[r][c]) && (board[r][c] >= 2))
				{
					board[r][c] -= 2;
					deq.emplace_back(r, c);
				}

			}
		}
	}

	int answer = 0;

	for (int r = 1; r <= n; ++r)
	{
		for (int c = 1; c <= n; ++c)
		{
			answer += board[r][c];
		}
	}

	cout << answer << '\n';
}
