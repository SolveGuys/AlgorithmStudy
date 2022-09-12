#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
	std::ios_base::sync_with_stdio(false); 
	std::cin.tie(nullptr); 
	std::cout.tie(nullptr);
	
	int k;
	int s[13];
	
	while (true)
	{
		std::cin >> k;
		if (k == 0)
			break;
		for (int i = 0; i < k; i++)
		{
			std::cin >> s[i];
		}
		std::vector<bool> combination;

		combination.resize(6, false);
		combination.insert(combination.end(), k - 6, true);
	
		do
		{
			for (int i = 0; i < combination.size(); i++)
			{
				if (!combination[i])
				{
					std::cout << s[i] << ' ';
				}
			}
			std::cout << '\n';
		}
		while (std::next_permutation(combination.begin(), combination.end()));
        std::cout << '\n';
	}

	return 0;
}