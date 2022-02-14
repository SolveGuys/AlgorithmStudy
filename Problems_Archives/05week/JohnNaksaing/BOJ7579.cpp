#include<iostream>
#include<vector>

int main()
{
	int N, M;
	std::cin >> N >> M;
	std::vector<int> mems(N);
	std::vector<int> costs(N);
	
	int cost_sum = 0;
	for (int& mem  : mems ) std::cin >> mem;
	for (int& cost : costs) 
	{
		std::cin >> cost;
		cost_sum += cost;
	}

	std::vector<int> max_mem(cost_sum+1);

	for (int i = 0; i < N; i++) 
	{
		for (int j = cost_sum; j > 0; j--) 
		{
			if(max_mem[j])
				max_mem[j + costs[i]] = std::max(max_mem[j] + mems[i], max_mem[j + costs[i]]);
		}

		max_mem[costs[i]] = std::max(mems[i],max_mem[costs[i]]);
	}

	int answer = 0;
	for (; answer < cost_sum, max_mem[answer] < M ; answer++);
	std::cout << answer;

	return 0;
}
