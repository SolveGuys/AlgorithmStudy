#include <iostream>
#include <vector>

int main() 
{
	int n, h;

	std::cin >> n >> h;

	std::vector<int> top(h+1), bottom(h+1);

	for (int i = 0; i < n/2; i++)
	{
		int down, up;
		std::cin >> down >> up;

		top[up]++, bottom[down]++;
	}

	for (int i = h; i > 1; i--) 
	{
		bottom[i - 1] += bottom[i];
		top[i - 1] += top[i];
	}

	int min_distruct_count = n;
	int min_d_height_count = 0;

	for (int i = 1; i <= h; i++) 
	{	
		int distruct_count = bottom[i] + top[h + 1 - i];
		if (distruct_count < min_distruct_count) 
		{
			min_distruct_count = distruct_count;
			min_d_height_count = 1;
		}
		else if (distruct_count == min_distruct_count)
		{
			min_d_height_count++;
		}
	}
	std::cout << min_distruct_count << ' ' << min_d_height_count;

    return 0;
}