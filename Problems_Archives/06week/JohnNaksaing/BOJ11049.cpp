#include <iostream>
#include <vector>
#include <climits>
#include <algorithm>
struct matrix 
{
	int row;
	int col;
};

int main()
{

	int N;
	std::cin >> N;

	std::vector<matrix> matrices(N+1);

	for(int i = 1; i <= N; i++)
	//for (matrix& mat : matrices)
	{
		std::cin >> matrices[i].row >> matrices[i].col;
	}

	std::vector<std::vector<int>> cost(N+1,std::vector<int>(N+1));


	const int BIG = INT_MAX >> 2;

	for (int d = 1; d <= N; d++)
	{
		for (int i = 0; i + d <= N; i++)
		{
			int j = i + d;
			cost[i][j] = BIG;

			for (int mid = i; mid < j; mid++)
				cost[i][j] = std::min(cost[i][j],cost[i][mid] + cost[mid+1][j] + matrices[i].row * matrices[mid].col * matrices[j].col);
			//std::cout << cost[i][j] << " ";
		}
		//std::cout << "\n";
	}

	int result = cost[1][N];
	std::cout << result;
	return 0;
}