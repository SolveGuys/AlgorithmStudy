#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n;
	std::cin >> n;

	std::vector<int> order(n+1);

	int max = 0;
	int num;

	for (int i = 0; i < n; i++) 
	{
		//std::cin >> order[i];
		std::cin >> num;
		//num--;
        order[num] = order[num-1] + 1;
		max = std::max(max,order[num]);
	}
	
	std::cout << n - max;

	return 0;
}