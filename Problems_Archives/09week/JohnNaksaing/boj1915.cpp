#include <iostream>
#include <vector>
#include <algorithm>

//5852KB, 44ms
int main()
{
	int n, m;
	std::cin >> n >> m;

	std::vector<std::vector<int>> data(n, std::vector<int>(m));

	for (int i = 0; i < n; i++)
	{
		std::string s;
		std::cin >> s;
		for (int j = 0; j < m; j++)
			data[i][j] = s[j] - '0';
	}

	int max_length = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			if (data[i][j] == 0 )
			{
				continue;
			}

			if(i != 0 && j != 0)
				data[i][j] = std::min(data[i - 1][j - 1], std::min(data[i][j - 1], data[i - 1][j])) + 1;
			max_length = std::max(max_length, data[i][j]);
		}
	}
	std::cout << max_length * max_length;
	return 0;
}