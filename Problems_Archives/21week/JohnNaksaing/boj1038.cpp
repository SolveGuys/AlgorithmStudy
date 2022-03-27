#include <iostream>
#include <vector>
#include <algorithm>

int main() 
{
	int N;
	std::cin >> N;
	std::vector <int> decliners;
	
	if (N < 10) return std::cout << N, 0;
	if (N == 1022) return std::cout << "9876543210", 0;
	if (N > 1022) return std::cout << -1, 0;


	for (int i = 1; i < 1023; i++) 
	{
		int decliner = 0;

		int j = i;
		for (int k = 9; k >= 0; k--) 
		{
			if (j % 2)
				decliner = 10 * decliner + k;
			j = j >> 1;
		}

		decliners.push_back(decliner);
	}

	std::sort(decliners.begin(),decliners.end());

	std::cout << decliners[N];
	return 0;
}