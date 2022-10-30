#include <bits/stdc++.h>
int chart[103][103];
int n, k;
int x[103], y[103];

int dp(int d, int c)
{
	if (d == 0)
		return 0;
	else if (c == n)
		return 1e9;

	int& ret = chart[d][c];

	if (ret != -1)
		return ret;

	ret = 1e9;

	for (int i = d / y[c]; i >= 1; i--) 
	{
        //덧셈 대신 이차식으로 구현
		ret = std::min(ret, dp(d - i * y[c], c + 1) + x[c] * i + i * (i - 1) / 2 * k);
	}
	ret = std::min(ret, dp(d, c + 1));
	return ret;
}

int main()
{
	int m;
	scanf_s("%d %d %d", &n, &m, &k);

	for (int i = 0; i < n; i++) 
	{
		scanf_s("%d %d", &x[i], &y[i]);
	}

	for (int i = 0; i <= m; i++)
		for (int j = 0; j <= n; j++)
			chart[i][j] = -1;

	printf("%d\n", dp(m, 0));

}
