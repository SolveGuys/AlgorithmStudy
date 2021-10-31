template<typename T>
using matrix = std::vector<std::vector<T>>;

template<typename contry>
void reset_visited_map(std::vector<std::vector<contry>>& World)
{
	for (int i = 0; i < World.size(); i++)
	for (int j = 0; j < World[0].size(); j++)
	{
		World[i][j].visited = false;
	}
}

template<typename contry, typename where>
void search(bool& out_men_moved, std::queue<where>& bfs_unions, matrix<contry>& World, std::vector<where>& bfs_results, int L, int R)
{
	static const int dirX[4] = { 1,-1,0,0 };
	static const int dirY[4] = { 0,0,1,-1 };
	while (!bfs_unions.empty()) 
	{
		where current = bfs_unions.front();
		bfs_unions.pop();
		for (int idx = 0; idx < 4; idx++)
		{
			where next = where(current.x + dirX[idx], current.y + dirY[idx]);

			if (next.x >= 0 && next.y < World.size() && next.y >= 0 && next.y < World.size()
				&& !World[current.x][current.y].visited)
			{
				int diff = std::abs(World[current.x][current.y].population - World[next.x][next.y].population);
				if (diff >= L && diff <= R)
				{
					World[current.x][current.y].visited = true;
					out_men_moved = true;
					bfs_results.push_back(next);
					bfs_unions.push(next);
				}
			}
			
		}
	}
}

int main() {

	int N, L, R;
	std::cin >> N  >> L >> R;
	
	struct contry
	{
		int population;
		bool visited = false;
	};

	struct where
	{
		int x;
		int y;

		where(int x, int y) : x(x),y(y) {}
	};

	::matrix<contry> World(N,std::vector<contry>(N));

	for(int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			std::cin >> World[i][j].population;
		}
	}
	

	int days_count = 0;
	while (true)
	{
		bool men_moved = false;
		
		for (int i = 0; i < N; i++)	
		for (int j = 0; j < N; j++)
		{
			if (World[i][j].visited) continue;
			
			int total_population = 0;
			int nation_size = 0;
			std::queue<where> bfs_unions;
			std::vector<where> bfs_results;
			bfs_unions.push(where(i,j));
			
			search(men_moved, bfs_unions, World, bfs_results, L, R);

			if (men_moved) 
			{
				for (int i = 0; i < bfs_results.size(); i++) 
				{
					total_population += World[bfs_results[i].x][bfs_results[i].y].population;
					nation_size++;
				}
			}
		}

		if (men_moved) 
		{
			reset_visited_map(World);
			days_count++;
		}
	}
	std::cout << days_count;
	return 0;
}