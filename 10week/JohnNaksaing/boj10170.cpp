template<typename _Ty>
using map_2d = std::vector<std::vector<_Ty>>;

struct pipe 
{
	//num of pipes from left/up/diagonal
	int right, down, diag;

	static map_2d<bool> bBlocked;
};
map_2d<bool> pipe::bBlocked;

int main()
{
	int N;
	std::cin >> N;

	pipe::bBlocked = std::vector<std::vector<bool>>(N + 1, std::vector<bool>(N + 1));
	for (size_t i = 1; i < N + 1; i++)
	{
		for (size_t j = 1; j < N + 1; j++)
		{
			int ij; std::cin >> ij;
			pipe::bBlocked[i][j] = ij;
		}
	}

	map_2d<pipe> dp(N + 1, std::vector<pipe>(N + 1));
	dp[1][2] = pipe{ 1,0,0 };
	for (size_t i = 1; i < N + 1; i++)
	{
		for (size_t j = 1; j < N + 1; j++)
		{
			if (pipe::bBlocked[i][j]) continue;
			bool bUp = pipe::bBlocked[i - 1][j], bLeft = pipe::bBlocked[i][j - 1], bDiag = bUp || bLeft;
			
			int from_left = dp[i][j - 1].right + dp[i][j - 1].diag;
			int from_up = dp[i - 1][j].down + dp[i - 1][j].diag;
			int from_diag = dp[i - 1][j - 1].right + dp[i - 1][j - 1].down + dp[i - 1][j - 1].diag;

			dp[i][j].right += from_left;
			dp[i][j].down += from_up;
			dp[i][j].diag += bDiag? 0 : from_diag;
		}
	}

	std::cout << dp[N][N].right + dp[N][N].down + dp[N][N].diag << "\n";
	/*
	for (size_t i = 1; i < N + 1; i++)
	{
		for (size_t j = 1; j < N + 1; j++)
		{
			std::cout << dp[i][j].right + dp[i][j].down + dp[i][j].diag << ' ';
			//std::cout << pipe::bBlocked[i][j];
		}std::cout << "\n";
	}
	*/
	return 0;
}