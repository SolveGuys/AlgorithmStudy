#include <bits/stdc++.h>

const int M = 7;
const int SMOL = -1e9;
int n, m, p[M][M], ans = SMOL;

enum class dir { updown, downup, leftright, rightleft };

int Length(int total, int len)
{
	if (len >= (total + 1) / 2)
		return len;
	else return total - len;
}

int get_max(int R, int C, int(*t)[M])
{
	int ret = SMOL;

	for (int i = 0; i < R; i++)
		for (int j = 0; j < C; j++)
			ret = std::max(ret, t[i][j]);

	return ret;
}

void fold(int R, int C, dir pos, int len, int(*t)[M])
{
	int temp[M][M] = { 0 };

	if (pos == dir::updown)
	{
		for (int i = 2 * len; i < R; i++)
			for (int j = 0; j < C; j++)
				temp[i - len][j] = t[i][j];
	}
	else if (pos == dir::leftright)
	{
		for (int i = 0; i < R; i++)
			for (int j = 2 * len; j < C; j++)
				temp[i][j - len] = t[i][j];
	}
	if (pos == dir::updown)
	{
		int idx = len - 1;

		for (int u = 0, d = 2 * len - 1; u < d; u++, d--)
		{
			for (int j = 0; j < C; j++)
			{
				temp[idx][j] = t[u][j] + t[d][j];
			}
			--idx;
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				t[i][j] = temp[i][j];
			}
		}
	}
	else if (pos == dir::downup)
	{
		if (R - 2 * len >= 0)
		{
			for (int j = 0; j < C; j++)
			{
				for (int u = R - 2 * len, d = R - 1; u < d; u++, d--)
				{
					t[u][j] = t[u][j] + t[d][j];
					t[d][j] = 0;
				}
			}
		}
	}
	else if (pos == dir::leftright)
	{
		int idx = len - 1;

		for (int l = 0, r = 2 * len - 1; l < r; l++, r--)
		{
			for (int i = 0; i < R; i++)
			{
				temp[i][idx] = t[i][l] + t[i][r];
			}
			--idx;
		}

		for (int i = 0; i < R; i++)
		{
			for (int j = 0; j < C; j++)
			{
				t[i][j] = temp[i][j];
			}
		}
	}
	else if (pos == dir::rightleft)
	{
		if (C - 2 * len >= 0)
		{
			for (int l = C - 2 * len, r = C - 1; l < r; l++, r--)
			{
				for (int i = 0; i < R; i++)
				{
					t[i][l] = t[i][l] + t[i][r];
					t[i][r] = 0;
				}
			}
		}
	}
}

void dfs(int rlen, int clen, int(*t)[M], int num)
{
	ans = std::max(ans, get_max(rlen, clen, t));

	int temp[M][M] = { 0 };

	for (int i = 0; i < rlen; i++)
		for (int j = 0; j < clen; j++)
			temp[i][j] = t[i][j];

	if (rlen > 1)
	{
		for (int i = 1; i <= rlen / 2; i++)
		{
			if (rlen - i >= 1)
			{
				fold(rlen, clen, dir::updown, i, t);
				dfs(Length(rlen, i), clen, t, num + 1);

				for (int a = 0; a < rlen; a++)
					for (int b = 0; b < clen; b++)
						t[a][b] = temp[a][b];

			}
		}

		for (int i = 1; i <= rlen / 2; i++)
		{
			if (rlen - i >= 1)
			{
				fold(rlen, clen, dir::downup, i, t);
				dfs(Length(rlen, i), clen, t, num + 1);

				for (int a = 0; a < rlen; a++)
					for (int b = 0; b < clen; b++)
						t[a][b] = temp[a][b];

			}
		}
	}
	if (clen > 1)
	{
		for (int i = 1; i <= clen / 2; i++)
		{
			if (clen - i >= 1)
			{
				fold(rlen, clen, dir::leftright, i, t);
				dfs(rlen, Length(clen, i), t, num + 1);

				for (int a = 0; a < rlen; a++)
					for (int b = 0; b < clen; b++)
						t[a][b] = temp[a][b];
			}
		}
		for (int i = 1; i <= clen / 2; i++)
		{
			if (clen - i >= 1)
			{
				fold(rlen, clen, dir::rightleft, i, t);
				dfs(rlen, Length(clen, i), t, num + 1);

				for (int a = 0; a < rlen; a++)
					for (int b = 0; b < clen; b++)
						t[a][b] = temp[a][b];
			}
		}
	}
}

int main()
{
	scanf("%d %d", &n, &m);

	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			scanf("%d", &p[i][j]);

	if (n == 1 && m == 1)
	{
		printf("%d", p[0][0]);
	}
	else
	{
		dfs(n, m, p, 1);
		printf("%d", ans);
	}

	return 0;
}