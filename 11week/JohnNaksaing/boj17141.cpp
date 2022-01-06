#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

class lab_map
{
	int N, M;
	std::vector<std::pair<int, int>> walls;
	std::vector<std::vector<int>> visited;

	std::queue<std::pair<int, int>> q;
	std::vector<std::pair<int, int>> viruses;

	int space_two;

	int space_total;

	static const int dx[4];
	static const int dy[4];
public:
	lab_map(int N, int M) : N(N), M(M),
		visited(std::vector<std::vector<int>>(N, std::vector<int>(N))), space_two(0), space_total(0)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				int ij;
				std::cin >> ij;
				if (ij == 2)
					viruses.push_back(std::make_pair(i, j));

				if (ij == 1)
					walls.push_back({i,j});

				else space_total++;
			}
		}
	}

	int solve();

	int bfs();
};
const int lab_map::dx[4] = { 1,-1, 0, 0 };
const int lab_map::dy[4] = { 0, 0, -1, 1 };

int lab_map::solve()
{
	int min_time = 1 << 30;

	space_two = viruses.size();

	std::vector<bool> selected(space_two, false);

	for (int i = 0; i < M; i++)
	{
		selected[space_two - i - 1] = true;
	}

	do
	{
		int min_time_current = -1;
		
		std::fill(visited.begin(), visited.end(), std::vector<int>(N, -1));

		for (auto wall : walls) 
		{
			visited[wall.first][wall.second] = -2;
		}

		int infected_num = 0;
		for (int i = 0; i < space_two; i++)
		{
			if (selected[i])
			{
				q.push(viruses[i]);
				visited[viruses[i].first][viruses[i].second] = 0;
				infected_num++;
			}
		}

		//bfs
		while (!q.empty())
		{
			int x = q.front().first;
			int y = q.front().second;

			q.pop();
			min_time_current = std::max(min_time_current, visited[x][y]);
			
			for (int i = 0; i < 4; i++)
			{
				int next_x = dx[i] + x;
				int next_y = dy[i] + y;

				if (next_x >= 0 && next_x < N && next_y >= 0 && next_y < N)
				{
					//-1 : 미방문, -2 : 벽, 나머지 숫자 : 걸린 시간
					if (visited[next_x][next_y] == -2 || visited[next_x][next_y] != -1) continue;

					visited[next_x][next_y] = visited[x][y] + 1;
					q.push({ next_x, next_y });

					infected_num++;
				}
			}
		}
		
		if (infected_num == space_total)
			min_time = std::min(min_time_current, min_time);

	} while (std::next_permutation(selected.begin(), selected.end()));

	return min_time;
}

int main()
{
	int N, M;
	std::cin >> N >> M;

	lab_map* map = new lab_map(N, M);

	int answer = map->solve();

	if (answer == 1 << 30) std::cout << -1;
	else std::cout << answer;

	delete map;
	return 0;
}