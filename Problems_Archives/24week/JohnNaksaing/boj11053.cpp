#include <iostream>
#include <vector>
#include <algorithm>

//2020kb, 0ms

/*
7
2 3 4 1 2 3 4

7
2 4 1 3 2 3 4
*/
int main() 
{
	int n;
	std::cin >> n;

	std::vector<int> nums(n);
	std::vector<int> dp(n,1);

	for (int i = 0; i < n; i++) 
	{
		std::cin >> nums[i];
	}

	for (int i = 1; i < dp.size(); i++) 
	{
		for (int j = 0; j < i; j++) 
		{
			if (nums[j] < nums[i])
			{
				dp[i] = std::max(dp[i],dp[j]+1);
			}
		}
	}
	std::cout << *std::max_element(dp.begin(),dp.end());

	return 0;
}