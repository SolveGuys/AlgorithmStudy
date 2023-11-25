#include <iostream>
#include <algorithm>

using namespace std;

int answer;
int n;
char board[2][102];
int restMineCnt[102];

void DFS(int depth, int mineCnt);

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 0;

	cin >> t;

	for (int i = 0; i < t; ++i)
	{
		cin >> n;

		for (int r = 0; r < 2; ++r)
		{
			for (int c = 0; c < n; ++c)
			{
				cin >> board[r][c];
			}
		}

		for (int j = 0; j < n; ++j)
		{
			restMineCnt[j] = board[0][j] - '0';
		}

		DFS(0, 0);
		cout << answer << '\n';
		answer = 0;
	}
}

void DFS(int depth, int mineCnt)
{
	if (depth == n)
	{
		answer = max(answer, mineCnt);
		return;
	}

	if (restMineCnt[depth] == 0)
	{
		DFS(depth + 1, mineCnt);
	}
	else
	{
		// 이미 현재 위치가 이미 지뢰인 경우
		if (board[1][depth] == '*')
		{
			if (((depth - 1 >= 0) && (restMineCnt[depth - 1] - 1 < 0)) ||
				(restMineCnt[depth] - 1 < 0) ||
				((depth + 1 < n) && (restMineCnt[depth + 1] - 1 < 0)))
			{
				return;
			}

			--restMineCnt[depth - 1];
			--restMineCnt[depth];
			--restMineCnt[depth + 1];
			DFS(depth + 1, mineCnt + 1);
			++restMineCnt[depth - 1];
			++restMineCnt[depth];
			++restMineCnt[depth + 1];
		}
		else
		{
			// 현재 위치에 지뢰를 놓지 않는 경우
			if ((depth - 1 >= 0) && (restMineCnt[depth - 1] == 0))
			{
				DFS(depth + 1, mineCnt);
			}

			// 현재 위치에 지뢰를 놓는 경우
			if (((depth - 1 >= 0) && (restMineCnt[depth - 1] - 1 < 0)) ||
				(restMineCnt[depth] - 1 < 0) ||
				((depth + 1 < n) && (restMineCnt[depth + 1] - 1 < 0)))
			{
				return;
			}

			--restMineCnt[depth - 1];
			--restMineCnt[depth];
			--restMineCnt[depth + 1];
			DFS(depth + 1, mineCnt + 1);
			++restMineCnt[depth - 1];
			++restMineCnt[depth];
			++restMineCnt[depth + 1];
		}
	}
}
