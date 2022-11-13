#include <bits/stdc++.h>

int main()
{
	int n, m;
	std::cin >> n >> m;
	std::vector<std::vector<int>> map(n, std::vector<int>(n, 1e6));

	std::vector<int> plan(m,-1);

	for (int i = 0; i < n; i++)
	{
		map[i][i] = 0;
		for (int j = 0; j < n; j++)
		{
			int b;
			std::cin >> b;
			if(b == 1)
				map[i][j] = map[j][i] = b;
		}
	}

	for (int i = 0; i < m; i++)
		std::cin >> plan[i], plan[i]--;;
	
	for (int k = 0; k < n; k++) 
	for (int i = 0; i < n; i++)
	for (int j = 0; j < n; j++)
	{
		map[i][j] = std::min(map[i][j],map[i][k] + map[k][j]);
	}

	for (int i = 0; i < m - 1; i++)
	{
		if (map[plan[i]][plan[i + 1]] == 1e6)
			return std::cout << "NO", 0;
	}
	std::cout << "YES";
	return  0;
}