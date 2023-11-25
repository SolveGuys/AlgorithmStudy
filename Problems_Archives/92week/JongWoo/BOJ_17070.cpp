#include <iostream>
#include <vector>

using namespace std;

int n;
int board[18][18];
int dp[18][18][3]; // [x][y][dir]
int dx[] = { 0, 1, 1 };
int dy[] = { 1, 0, 1 };
vector<int> directions[3];

int DFS(int x, int y, int dir);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	cin >> n;

	for (int i = 1; i <= n; ++i)
	{
		for (int j = 1; j <= n; ++j)
		{
			cin >> board[i][j];
			dp[i][j][0] = dp[i][j][1] = dp[i][j][2] = - 1;
		}
	}

	// 0: 가로, 1: 세로, 2: 대각선
	// dx, dy의 인덱스를 저장
	directions[0].push_back(0); directions[0].push_back(2);
	directions[1].push_back(1); directions[1].push_back(2);
	directions[2].push_back(0); directions[2].push_back(1); directions[2].push_back(2);
	cout << DFS(1, 2, 0) << '\n';

	//for (int d = 0; d < 3; ++d)
	//{
	//	for (int i = 1; i <= n; ++i)
	//	{
	//		for (int j = 1; j <= n; ++j)
	//		{
	//			cout << dp[i][j][d] << ' ';
	//		}

	//		cout << '\n';
	//	}

	//	cout << "===========================\n";
	//}
}

int DFS(int x, int y, int dir)
{
	if ((x == n) && (y == n))
	{
		dp[x][y][dir] = 1;
	}
	else if (dp[x][y][dir] == -1)
	{
		dp[x][y][dir] = 0;

		for (int d : directions[dir])
		{
			int nx = x + dx[d];
			int ny = y + dy[d];

			if ((nx < 1) || (nx > n) || (ny < 1) || (ny > n) || (board[nx][ny] != 0))
			{
				continue;
			}

			// 대각선 방향일 때
			if (d == 2)
			{
				if ((nx - 1 < 1) || (ny - 1 < 1) || (board[nx - 1][ny] == 1) || (board[nx][ny - 1] == 1))
				{
					continue;
				}
			}

			dp[x][y][dir] += DFS(nx, ny, d);
		}
	}

	return dp[x][y][dir];
}
