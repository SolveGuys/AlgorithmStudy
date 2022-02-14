#include <iostream>
#include <vector>

struct dice 
{
	//a-f, b-d, c-e
	//012345
	//534120
	int arr[6];
	const static int other_side[6];

public:
	dice() {}
	
	int biggest_side(int bottom) 
	{
		int top = otherside_val(bottom);

		int max_val = 0;
		for (int i = 0; i < 6; i++) 
		{ 
			if (arr[i] == top || arr[i] == bottom) continue;
				
			max_val = std::max(max_val,arr[i]);
		}
		return max_val;
	}

	int otherside_val(int val) 
	{
		for (int i = 0; i < 6; i++) 
		{
			if (arr[i] == val)
				return (arr[other_side[i]]);
		}
		return -99999;
	}
};

const int dice::other_side[6] = { 5,3,4,1,2,0 };

int main() 
{
	int n;
	std::cin >> n;

	std::vector<dice> vec_dices(n);
	for (int i = 0; i < n; i++) 
	{
		for (int j = 0; j < 6; j++) 
		{
			std::cin >> vec_dices[i].arr[j];
		}
	}

	int max_sum = 0;
	for (int bottom_idx = 0; bottom_idx < 6; bottom_idx++)
	{

		int lowest_bottom = vec_dices[0].arr[bottom_idx];

		int bottom = lowest_bottom;
		int top = vec_dices[0].otherside_val(bottom);

		for (int i = 0; i < 4; i++)
		{
			int side_sum = 0;

			for (int j = 0; j < n; j++) 
			{
				bottom = top;
				top = vec_dices[j].otherside_val(bottom);
			
				side_sum += vec_dices[j].biggest_side(bottom);
				
			}
			
			max_sum = std::max(max_sum, side_sum);
		}
		
	}

	std::cout << max_sum;

	return 0;
}