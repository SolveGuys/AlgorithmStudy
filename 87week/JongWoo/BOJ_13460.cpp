#include <iostream>

using namespace std;

int answer = 0x7f7f7f7f;
int n, m;
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };
char board[12][12];

void DFS(int cnt);
void Tip(int x, int y, int dir, char color);

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

	DFS(0);
	cout << ((answer == 0x7f7f7f7f) ? -1 : answer) << '\n';
}

void DFS(int cnt)
{
	char tmpBoard[12][12] = {};
	int rx = -1, ry = -1;
	int bx = -1, by = -1;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			switch (board[i][j])
			{
			case 'R':
				rx = i, ry = j;
				break;
			case 'B':
				bx = i, by = j;
				break;
			}

			tmpBoard[i][j] = board[i][j];
		}
	}

	// 현재 보드에 빨간 구슬은 없고, 파란 구슬만 있는 경우
	if ((rx + ry == -2) && (bx + by != -2))
	{
		answer = min(answer, cnt);
		return;
	}

	// 파란 구슬이 없거나, 10번 움직인 경우
	if ((bx + by == -2) || (cnt == 10))
	{
		return;
	}

	// 상(0), 하(1), 좌(2), 우(2)
	for (int dir = 0; dir < 4; ++dir)
	{
		switch (dir)
		{
		case 0: // 상
			if (rx - bx < 0)
			{
				Tip(rx, ry, dir, 'R');
				Tip(bx, by, dir, 'B');
			}
			else
			{
				Tip(bx, by, dir, 'B');
				Tip(rx, ry, dir, 'R');
			}
			break;
		case 1: // 하
			if (rx - bx < 0)
			{
				Tip(bx, by, dir, 'B');
				Tip(rx, ry, dir, 'R');
			}
			else
			{
				Tip(rx, ry, dir, 'R');
				Tip(bx, by, dir, 'B');
			}
			break;
		case 2: // 좌
			if (ry - by < 0)
			{
				Tip(rx, ry, dir, 'R');
				Tip(bx, by, dir, 'B');
			}
			else
			{
				Tip(bx, by, dir, 'B');
				Tip(rx, ry, dir, 'R');
			}
			break;
		case 3: // 우
			if (ry - by < 0)
			{
				Tip(bx, by, dir, 'B');
				Tip(rx, ry, dir, 'R');
			}
			else
			{
				Tip(rx, ry, dir, 'R');
				Tip(bx, by, dir, 'B');
			}
			break;
		}

		// 판을 기울였을 때 판의 상태가 이전과 동일하지 않을 때만 탐색을 이어 나간다.
		bool isSame = true;

		for (int i = 0; i < n; ++i)
		{
			for (int j = 0; j < m; ++j)
			{
				if (board[i][j] != tmpBoard[i][j])
				{
					isSame = false;
					break;
				}
			}

			if (!isSame)
			{
				break;
			}
		}

		if (!isSame)
		{
			DFS(cnt + 1);

			// 보드 상태 복원
			for (int i = 0; i < n; ++i)
			{
				for (int j = 0; j < m; ++j)
				{
					board[i][j] = tmpBoard[i][j];
				}
			}
		}
	}
}

void Tip(int x, int y, int dir, char color)
{
	int nx = x, ny = y;

	while (true)
	{
		if ((nx + dx[dir] < 0) || (nx + dx[dir] >= n) || (ny + dy[dir] < 0) || (ny + dy[dir] >= m))
		{
			break;
		}

		if (board[nx + dx[dir]][ny + dy[dir]] == '.')
		{
			board[nx][ny] = '.';
			nx += dx[dir];
			ny += dy[dir];
			board[nx][ny] = color;
		}
		else if (board[nx + dx[dir]][ny + dy[dir]] == 'O')
		{
			board[nx][ny] = '.';
			break;
		}
		else
		{
			break;
		}
	}
}
