#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int r, c, t;
int board[52][52];
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
vector<pair<int, int>> air;

void Spread();
void Blow();

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> r >> c >> t;

	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			cin >> board[i][j];

			// 공기 청정기의 위치
			if (board[i][j] == -1)
			{
				air.emplace_back(i, j);
			}
		}
	}

	for (int i = 0; i < t; ++i)
	{
		// 미세먼지의 확산
		Spread();

		// 공기청정기의 작동
		Blow();
	}

	int answer = 0;

	for (int i = 1; i <= r; ++i)
	{
		for (int j = 1; j <= c; ++j)
		{
			if (board[i][j] == -1)
			{
				continue;
			}

			answer += board[i][j];
		}
	}

	cout << answer << '\n';
}

void Spread()
{
	int delta[52][52] = {};

	for (int x = 1; x <= r; ++x)
	{
		for (int y = 1; y <= c; ++y)
		{
			// 먼지의 양이 5이상일 때만 확산이 일어난다.
			if (board[x][y] < 5)
			{
				continue;
			}

			int amount = board[x][y] / 5;
			int cnt = 0;

			for (int i = 0; i < 4; ++i)
			{
				int nx = x + dx[i];
				int ny = y + dy[i];

				if ((nx < 1) || (nx > r) || (ny < 1) || (ny > c) || (board[nx][ny] == -1))
				{
					continue;
				}

				delta[nx][ny] += amount;
				++cnt;
			}

			delta[x][y] -= amount * cnt;
		}
	}

	for (int x = 1; x <= r; ++x)
	{
		for (int y = 1; y <= c; ++y)
		{
			board[x][y] += delta[x][y];
		}
	}
}

void Blow()
{
	// 공기청정기의 상단 순환(반시계 방향) 
	for (int x = air[0].first - 1; x > 1; --x)
	{
		board[x][1] = board[x - 1][1];
	}

	for (int y = 1; y < c; ++y)
	{
		board[1][y] = board[1][y + 1];
	}

	for (int x = 1; x < air[0].first; ++x)
	{
		board[x][c] = board[x + 1][c];
	}

	for (int y = c; y > 2; --y)
	{
		board[air[0].first][y] = board[air[0].first][y - 1];
	}

	board[air[0].first][2] = 0;

	// 공기청정기의 하단 순환(시계 방향)
	for (int x = air[1].first + 1; x < r; ++x)
	{
		board[x][1] = board[x + 1][1];
	}

	for (int y = 1; y < c; ++y)
	{
		board[r][y] = board[r][y + 1];
	}

	for (int x = r; x > air[1].first; --x)
	{
		board[x][c] = board[x - 1][c];
	}

	for (int y = c; y > 2; --y)
	{
		board[air[1].first][y] = board[air[1].first][y - 1];
	}

	board[air[1].first][2] = 0;
}
