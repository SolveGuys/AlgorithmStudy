#include <cstdio>
#include <vector>

class tetromino 
{
	// (0,0) + (offset_x, offset_y)
	const int offset_x0, offset_x1, offset_x2;
	const int offset_y0, offset_y1, offset_y2;

public:	
	tetromino(std::pair<int,int> p0, std::pair<int,int> p1, std::pair<int,int>p2) : offset_x0(p0.first),offset_x1(p1.first),offset_x2(p2.first),offset_y0(p0.second),offset_y1(p1.second),offset_y2(p2.second) {}

	int get_score(const std::vector<std::vector<int>>& map, int start_x, int start_y) 
	{
		return map[start_x][start_y] + map[start_x + offset_x0][start_y + offset_y0] + map[start_x + offset_x1][start_y + offset_y1] + map[start_x + offset_x2][start_y + offset_y2];
	}
};
tetromino tetrominos[]
{
	//line piece
	tetromino({0,1},{0,2},{0,3}),
	tetromino({1,0},{2,0},{3,0}),
	
	//square
	tetromino({1,0},{0,1},{1,1}),
	
	//l-block
	tetromino({1,0},{2,0},{2,1}),
	tetromino({0,1},{0,2},{1,0}),
	tetromino({0,1},{1,1},{2,1}),
	tetromino({1,0},{1,-1},{1,-2}),
	tetromino({1,0},{2,0},{2,-1}),
	tetromino({1,0},{1,1},{1,2}),
	tetromino({0,1},{1,0},{2,0}),
	tetromino({0,1},{0,2},{1,2}),

	//s-block
	tetromino({1,0},{1,1},{2,1}),
	tetromino({0,1},{1,0},{1,-1}),
	tetromino({1,0},{1,-1},{2,-1}),
	tetromino({0,1},{1,1},{1,2}),
	
	//t-block
	tetromino({1,0},{1,1},{1,-1}),
	tetromino({1,0},{1,1},{2,0}),
	tetromino({0,1},{0,2},{1,1}),
	tetromino({0,1},{-1,1},{1,1})
};
int main() 
{
	int n, m;
	
	scanf("%d %d",&n, &m);
	std::vector<std::vector<int>> map(n + 6,std::vector<int>(m + 6, -4096));

	int max_sum = 0;

	for (int i = 3; i < n + 3; i++) 
	{
		for (int j = 3; j < m + 3; j++) 
		{
			scanf("%d",&map[i][j]);
		}
	}

	for (int i = 3; i < n + 3; i++) 
	{
		for (int j = 3; j < m + 3; j++) 
		{
			for (int k = 0; k < 19; k++) 
			{
				int score = tetrominos[k].get_score(map,i,j);
				max_sum = std::max(max_sum, score);
			}
		}
	}
	
	printf("%d", max_sum);
	return 0;
}
