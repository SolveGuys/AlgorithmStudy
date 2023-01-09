#include <bits/stdc++.h>
const int move_cost[5][5] = 
{
	{1,2,2,2,2},
	{0,1,3,4,3},
	{0,3,1,3,4},
	{0,4,3,1,3},
	{0,3,4,3,1}
};

int dp[100'001][5][5];

int main()
{
    memset(dp, 0x3f, sizeof(dp));

	dp[0][0][0] = 0;
	
	int num;
    int i = 0;
	while (scanf("%d", &num),i++, num != 0) 
	{
		for (int left = 0;  left < 5;	left++)
		for (int right = 0; right < 5; right++)
		{
			dp[i][left][num]	= std::min(dp[i][left][num]		, dp[i-1][left][right] + move_cost[right][num]);
			dp[i][num][right]	= std::min(dp[i][num][right]	, dp[i-1][left][right] + move_cost[left][num]);
		}
	}

	int score = 0x3f3f3f3f;
	for (int left = 0; left < 5; left++)
	for (int right = 0; right < 5; right++) 
	{
		score = std::min(score,dp[i-1][left][right]);
	}
	
	printf("%d", score);

	return 0;
}