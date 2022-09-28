#include <stdio.h>

int dp[1002][10] = { 0 };
int main(void)
{
	int n;
	int i, j;
	int answer=0;

	scanf("%d", &n);

	for (i = 0; i < 10; i++)
	{
		dp[1][i] = 1;
	}

	for (i = 2; i <= n; i++)
	{
		for (j = 9; j >=0; j--)
		{
			if (j == 9)
			{
				dp[i][j] = 1;
			}
			else if (j == 0)
			{
				dp[i][j] = 0;
			}
			else
			{
				dp[i][j] = (dp[i][j + 1]%10007) + (dp[i - 1][j]%10007);
			}
		}
	}
	
	for (i = 1; i <= n; i++)
	{
		for (j = 0; j <= 9; j++)
		{
			answer += dp[i][j]%10007;
		}
	}
	
	printf("%d", answer%10007);
	return 0;
}
