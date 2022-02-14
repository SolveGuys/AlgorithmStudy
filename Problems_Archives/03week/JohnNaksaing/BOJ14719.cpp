#include <iostream>
#include <vector>
#include <cmath>.

int main() 
{
	int H, W;
	std::cin >> H >> W;

	std::vector<int> world(W);
	for (int& floor : world) 
	{
		std::cin >> floor;
	}

	int rain_total = 0;
	for (int i = 0; i < W; i++) 
	{
		int left = i, right = i;
		int left_h = world[i]; int right_h = world[i];
		while (left >= 0) 
		{
			left_h = std::max(left_h, world[left--]);
		}
		while (right < W) 
		{
			right_h = std::max(right_h, world[right++]);
		}
		
		rain_total += std::min( left_h - world[i], right_h - world[i] );
	}

	std::cout << rain_total;
	return 0;
}