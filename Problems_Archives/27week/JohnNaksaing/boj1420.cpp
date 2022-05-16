#include <iostream>
#include <vector>
std::vector<std::vector<int>> map;
std::vector<std::vector<int>> dp;

const int dx[]{-1,1,0,0};
const int dy[]{0,0,-1,1};
constexpr int OUT_OF_RANGE = 0;
constexpr int NOT_VISITED = -2;

int dfs(int x, int y)
{
	if (x == map.size() -2 && y == map[0].size() -2)
		return 1;

	if(dp[x][y] == NOT_VISITED)
    {
        dp[x][y] = 0;
	    for (int dir = 0; dir < 4; dir++)
	    {
		    int next_x = x + dx[dir];
		    int next_y = y + dy[dir];

		    if (map[next_x][next_y] != OUT_OF_RANGE && map[next_x][next_y] < map[x][y])
		    {
		    	dp[x][y] += dfs(next_x,next_y);
		    }
	    }
    }

	return dp[x][y];
};

int main() 
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);

	int m, n;
	std::cin >> m >> n;

	map.resize(m + 2, std::vector<int>(n + 2, OUT_OF_RANGE));
	dp.resize(m + 2, std::vector<int>(n + 2, NOT_VISITED));

	for (int i = 1; i <= m; i++)
	for (int j = 1; j <= n; j++) 
	{
		std::cin >> map[i][j];
	}

	std::cout << dfs(1,1);
	return 0;
}