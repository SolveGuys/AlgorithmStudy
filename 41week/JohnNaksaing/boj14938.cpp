#include <bits/stdc++.h>

const int big = 1e9;
int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int n, m, r;
	std::cin >> n >> m >> r;
	std::vector<int> items(n + 1);
	std::vector<std::vector<int>> map(n + 1, std::vector<int>(n + 1,big));
	
	for (int i = 1; i <= n; i++)
		std::cin >> items[i];

	for (int k = 1; k <= n; k++)
		map[k][k] = 0;

	for (int _ = 0; _ < r; _++)
	{
		int i, j, val;
		std::cin >> i >> j >> val;
		map[i][j] = val;
		map[j][i] = val;
	}

	for (int k = 1; k <= n; k++)
    	for (int i = 1; i <= n; i++)
    	for (int j = 1; j <= n; j++)
	    if (map[i][j] > map[i][k] + map[k][j])
            	map[i][j] = map[i][k] + map[k][j];

	int result = 0;
	for (int i = 1; i <= n; i++) 
    	{
		int temp = 0;
		for (int j = 1; j <= n; j++)
			if (map[i][j] <= m)
				temp += items[j];
		result = std::max(result, temp);
	}
	std::cout << result;
	return 0;
}
