#include <stdio.h>
int MAX(int a, int b)
{
	return a > b ? a : b;
}
int main(void)
{
	int g[10001];
	int dp[10001];
	int n, i;

	scanf("%d",&n);

	for (i = 1; i <= n; i++)
	{
		scanf("%d", &g[i]);
	}
	dp[0] = 0;
	dp[1] = g[1];
	dp[2] = g[1] + g[2];

	for (i = 3; i <= n; i++)
	{
		dp[i] = MAX(dp[i-1],MAX(dp[i-2]+g[i],dp[i-3]+g[i-1]+g[i]));

	}

	printf("%d", dp[n]);
	return 0;
}
