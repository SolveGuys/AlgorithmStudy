#include <iostream>
#include <vector>
#include <queue>

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> nums(n-1);

	for (int i = 0; i < n-1; i++)
	{
		std::cin >> nums[i];
	}
	int expected;
	std::cin >> expected;

	//dp[i][j] = nums를 nums[0]부터 nums[i]까지 썼을 때 숫자가 j인 경우의 수
	std::vector<std::vector<long>> dp(n-1,std::vector<long>(21,0l));

	dp[0][nums[0]] = 1;

	for (int i = 0; i < n - 2; i++)
	{
		for (int j = 0; j <= 20; j++) 
		{
            // j + nums[i] : j를 만들어와서 nums[i]랑 더하거나 빼거나
			if (j + nums[i+1] <= 20)
			{
				dp[i + 1][j + nums[i+1]] += dp[i][j];
			}

			if (j - nums[i+1] >= 0) 
			{
				dp[i + 1][j - nums[i+1]] += dp[i][j];
			}
		}
	}

	std::cout << dp[n-2][expected];
	return 0;
}

void Using_Queue_MLE(std::vector<int>& nums, int expected)
{
    std::queue<int> results;
	results.push(nums[0]);
	for (int i = 1; i < n-1; i++)
	{
		int size = results.size();
		for (int j = 0; j < size; j++) 
		{
			int from_q = results.front();
			results.pop();

			if(from_q + nums[i] <= 20)
				results.push(from_q + nums[i]);
			if(from_q - nums[i] >= 0)
				results.push(from_q - nums[i]);

			//results.push(from_q);
		}
	}

	int count = 0;
	while (!results.empty()) 
	{
		if (results.front() == expected)
			count++;

		results.pop();
	}

	std::cout << count;
}