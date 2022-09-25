#include <iostream>
#include <vector>
int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	struct binary 
	{
		//끝자리
		long zero, one;
	};
	int n;
	std::cin >> n;
	std::vector<binary> series(n + 1);

	series[0] = { 0,1 };
	series[1] = { 1,0 };
	for (int i = 2; i <= n; i++) 
	{
		series[i] = { series[i - 1].one + series[i - 1].zero, series[i-1].zero };
	}

	std::cout << series[n-1].one + series[n-1].zero;
	
	return 0;
}