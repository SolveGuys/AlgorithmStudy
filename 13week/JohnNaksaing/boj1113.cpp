#include <iostream>
#include <vector>
#include <queue>

struct node { int x, y; };
const int g_dx[] = { 1,-1,0,0 };
const int g_dy[] = { 0,0,1,-1 };

int main() 
{
	int N, M;

	std::cin >> N >> M; //N,M <= 50

	int max = 0;
	std::vector<std::vector<int>> pool(N,std::vector<int>(M));

	//input
	for (int i = 0; i < N; i++) 
	{
		for (int j = 0; j < M; j++)
		{
			scanf_s("%1d", &pool[i][j]);
			max = std::max(max,pool[i][j]);
		}

	}

	std::vector<std::vector<bool>> bVisited(N,std::vector<bool>(M,false));

	//solve
	int total_water = 0;
	for (int floor = 1; floor <= max; floor++)
	{
		int floor_water = 0;
		//printf("%d ",floor);
		std::fill(bVisited.begin(), bVisited.end(), std::vector<bool>(M, false));
		
		for (int x = 0; x < N; x++)
		{
			for (int y = 0; y < M; y++)
			{
				///bfs
				
				std::queue<node> q_water;

				//
				if (pool[x][y] >= floor || bVisited[x][y])
				{
					continue;
				}

				q_water.push({ x,y });
				std::vector<node> vec_chunk({ {x,y} });
				bVisited[x][y] = true;
				
				bool bBoundary = false;
				while (!q_water.empty())
				{
					auto current_node = q_water.front();
					q_water.pop();

					for (int dir = 0; dir < 4; dir++) 
					{
						int next_x = current_node.x + g_dx[dir];
						int next_y = current_node.y + g_dy[dir];

						if (next_x < 0 || next_x >= N || next_y < 0 || next_y >= M)
						{
							bBoundary = true;
							continue;
						}

						//
						if (!bVisited[next_x][next_y] && (pool[next_x][next_y] < floor))
						{
							q_water.push({ next_x,next_y });
							bVisited[next_x][next_y] = true;
							vec_chunk.push_back({ next_x,next_y });
						}
					}
				}

				if (!bBoundary)
				{
					//for (auto chunk : vec_chunk) printf("[%d,%d]", chunk.x, chunk.y);

					floor_water += vec_chunk.size();
				}
			}
		}

		total_water += floor_water;
		//printf("%d %d\n",floor_water, total_water);
	}

		

	printf("%d",total_water);
	return 0;
}