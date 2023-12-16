#include <iostream>

using namespace std;

int n, m, x, y, k;
int board[22][22];
int dice[6]; // 주사위의 면에 써있는 수(0: 위쪽, 1: 아래쪽, 2: 왼쪽, 3: 오른쪽, 4: 앞쪽, 5: 뒤쪽)
int dx[] = { 0, 0, -1, 1 }; // (0: 동, 1: 서, 2: 북, 3: 남)
int dy[] = { 1, -1, 0, 0 };

void Simulate(int dir);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n >> m >> x >> y >> k;

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < m; ++j)
		{
			cin >> board[i][j];
		}
	}

	for (int i = 0; i < k; ++i)
	{
		int dir = 0;

		cin >> dir;
		Simulate(dir);
	}
}

void Simulate(int dir)
{
	int nx = x + dx[dir - 1];
	int ny = y + dy[dir - 1];

	if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= m))
	{
		return;
	}

	x = nx;
	y = ny;

	int tmp = dice[0];

	switch (dir)
	{
	case 1:
		dice[0] = dice[2];
		dice[2] = dice[1];
		dice[1] = dice[3];
		dice[3] = tmp;
		break;
	case 2:
		dice[0] = dice[3];
		dice[3] = dice[1];
		dice[1] = dice[2];
		dice[2] = tmp;
		break;
	case 3:
		dice[0] = dice[5];
		dice[5] = dice[1];
		dice[1] = dice[4];
		dice[4] = tmp;
		break;
	case 4:
		dice[0] = dice[4];
		dice[4] = dice[1];
		dice[1] = dice[5];
		dice[5] = tmp;
		break;
	}

	if (board[nx][ny] == 0)
	{
		board[nx][ny] = dice[1];
	}
	else
	{
		dice[1] = board[nx][ny];
		board[nx][ny] = 0;
	}

	cout << dice[0] << '\n';
}
