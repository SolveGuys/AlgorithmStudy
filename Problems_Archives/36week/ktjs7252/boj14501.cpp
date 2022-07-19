#include<stdio.h>

#define MAX(a,b) a>b ? a:b
int period[1001];
int pay[1001];
int dp[1001]; //지금까지 온날 중 최고가

int main(void)
{
	int i, j;
	int N;
	int answer = 0;

	scanf("%d", &N);

	for (i = 1; i <= N; i++)
	{
		scanf("%d %d", &period[i], &pay[i]);
	}
	//main logic
	for (i = 1; i <= N+1; i++)
	{
		for (j = 1; j < i; j++)
		{
			if (j + period[j] == i)
			{
				dp[i] = MAX(dp[i], dp[j] + pay[j]);
			}
			else
			{
				dp[i] = MAX(dp[i], dp[i - 1]);
			}
		}
	}

	//답
	for (i = 1; i <= N+1; i++)
	{
		answer = MAX(answer, dp[i]);
	}

	printf("%d", answer);

	return 0;
}
