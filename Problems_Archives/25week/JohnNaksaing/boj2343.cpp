#include <iostream>
#include <vector>
//https://www.acmicpc.net/board/view/83220
//https://www.acmicpc.net/source/18344146

int main() 
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);

	int n, m;
	std::cin >> n >> m;
	std::vector<int> lectures(n);
	int total_sum{};

	int max_val = 0;

	for (int i = 0; i < n; i++) 
	{
		std::cin >> lectures[i];
		max_val = std::max(max_val,lectures[i]);
		total_sum += lectures[i];
	}

	int left_bound = max_val, right_bound = total_sum;

	while (left_bound <= right_bound) 
	{
		int mid = (left_bound + right_bound) >> 1;

		int bluray_count = 0;
		int temp_sum = 0;

		for (int i = 0; i < n; i++) 
		{
			if (temp_sum + lectures[i] > mid) 
			{
				temp_sum = 0;
				bluray_count++;
				//continue;
			}
			temp_sum += lectures[i];
		}
		if (temp_sum != 0)
			bluray_count++;

		if (bluray_count > m) 
		{
			left_bound = mid + 1;
		}
		else
		{
			right_bound = mid - 1;
		}

	}

	std::cout << left_bound;
	return 0;
}

