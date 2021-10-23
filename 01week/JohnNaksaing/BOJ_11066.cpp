#include <iostream>
#include <vector>

int solve_N3() 
{
	const int BIG = 536870911;
	//input handling
	int T;
	std::cin >> T;
	while (T-- > 0)
	{
		int K;
		std::cin >> K;
		std::vector<int> files(K + 1);
		std::vector<int> sum(K + 1);
		std::vector<std::vector<int>> cost(K + 1, std::vector<int>(K + 1));

		for (int i = 1; i <= K; i++)
		{
			std::cin >> files[i];
			sum[i] = sum[i - 1] + files[i];
		}

		//sol
		//cost 초기화
		/*
		for (int i = 1; i <= K; i++)
		{
			cost[i][i] = files[i];


			cost[i-1][i] = files[i-1] + files[i];
		}

		// cost(i,j) = min( cost(i,k) + cost(k,j) )

		for (int start = 1; start <= K; start++)
		{
			for (int end = start; end <= K; end++)
			{
				for (int i = start; i < end; i++)
				{
					cost[start][end] = std::min(cost[start][end], cost[start][i] + cost[i + 1][end]);
				}
				cost[start][end] += sum[end] - sum[start - 1];
			}
		}
		*/
		for (int d = 1; d < K; ++d) {
			for (int tx = 1; tx + d <= K; ++tx) {
				int ty = tx + d;
				cost[tx][ty] = BIG;

				for (int mid = tx; mid < ty; ++mid)
					cost[tx][ty] = std::min(cost[tx][ty], cost[tx][mid] + cost[mid + 1][ty] + sum[ty] - sum[tx - 1]);
			}
		}
		std::cout << cost[1][K] << '\n';
	}

	return 0;
}

int solve_N2() 
{
	const int BIG = 536870911; //INT_MAX >> 2;
	//input handling
	int T;
	std::cin >> T;
	while (T-- > 0)
	{
		int K;
		std::cin >> K;
		std::vector<int> files(K + 1);
		std::vector<int> sum(K + 1);
		std::vector<std::vector<int>> cost(K + 1, std::vector<int>(K + 1));
		std::vector<std::vector<int>> knuth(K + 1, std::vector<int>(K + 1));

		//input
		for (int i = 1; i <= K; i++)
			std::cin >> files[i], sum[i] = sum[i - 1] + files[i];

		//sol
		for (int i = 1; i <= K; i++)
			cost[i - 1][i] = 0, knuth[i - 1][i] = i;

		for (int d = 2; d <= K; ++d) {
			for (int tx = 0; tx + d <= K; ++tx) {
				int ty = tx + d;
				cost[tx][ty] = BIG;

				for (int mid = knuth[tx][ty - 1]; mid <= knuth[tx + 1][ty]; ++mid)
				{
					int v = cost[tx][mid] + cost[mid][ty] + sum[ty] - sum[tx];
					if (cost[tx][ty] > v)
					{
						cost[tx][ty] = v;
						knuth[tx][ty] = mid;
					}
				}
			}
		}
		std::cout << cost[0][K] << '\n';
	}

	return 0;
}

int main()
{
    solve_N2();
    return 0;
}