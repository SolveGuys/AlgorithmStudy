#include <iostream>
#include <vector>

int main() 
{
	int n;
	scanf("%d",&n);
    	
	int* dp = new int[n + 1];

	dp[0] = 0;

	for (int k = 1; k <= n; k++) 
	{
		dp[k] = k;

		int j = 0;
		while (k - j * j >= 0) 
		{
			dp[k] = std::min(dp[k],dp[k - j*j] + 1);

			j++;
		}
	}
	printf("%d",dp[n]);
	delete[] dp;
	return 0;
}