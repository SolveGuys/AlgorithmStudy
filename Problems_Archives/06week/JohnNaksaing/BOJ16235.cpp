#include <iostream>
#include <deque>
class map_
{
	int N, M;
	int Grid[11][11];
	int A[11][11];
	std::deque<int> Trees[11][11];
	std::deque<int> Deads[11][11];

	const int dx[8] = { -1, -1, -1,  0, 0,  1, 1, 1 };
	const int dy[8] = { -1,  0,  1, -1, 1, -1, 0, 1 };

public:
	map_(int& N, int& M) : N(N), M(M)
	{
		for (int i = 1; i <= N; i++)
		{
			for (int j = 1; j <= N; j++)
			{
				std::cin >> A[i][j];
				Grid[i][j] = 5;
			}
		}

		for (int i = 1; i <= M; i++)
		{
			int r, c, age;
			std::cin >> r >> c >> age;

			Trees[r][c].push_back(age);
		}
	}

	void season();
	int getTrees();

	void print_map();
};

void map_::print_map() 
{

	std::cout << "\n";
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			std::cout << Grid[i][j] << " ";
		}
		std::cout << "\n";
	}
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			if (Trees[i][j].size())
				for (auto age : Trees[i][j])
					std::cout << i << " " << j << " " << age << "\n";
		}
	}
}

void map_::season() 
{
	//spring
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			//std::sort(Trees[i][j].begin(),Trees[i][j].end());
			int size = Trees[i][j].size();
			while (size--) 
			{
				int age = Trees[i][j].front(); Trees[i][j].pop_front();

				if (Grid[i][j] < age) 
				{
					Deads[i][j].push_back(age);
				}
				else 
				{
					Grid[i][j] -= age;
					Trees[i][j].push_back(age+1);
				}
			}
		}
	}

	
	//summer
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for(int age : Deads[i][j])
				Grid[i][j] += age / 2;

			Deads[i][j].clear();
		}
	}

	//autumn
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			for (int k = 0; k < Trees[i][j].size(); k++) 
			{
				if (Trees[i][j][k] % 5 != 0) continue;

				for (int dir = 0; dir < 8; dir++) 
				{
					int nr = i + dx[dir];
					int nc = j + dy[dir];
					if (nr < 1 || nr > N || nc < 1 || nc > N) continue;
					Trees[nr][nc].push_front(1);
				}
			}
		}
	}


	//winter
	for (int i = 1; i <= N; i++)
	{
		for (int j = 1; j <= N; j++)
		{
			Grid[i][j] += A[i][j];
		}
	}


}

int map_::getTrees() 
{
	int dau = 0;
	for (int i = 1; i <= N; i++) 
	{
		for (int j = 1; j <= N; j++) 
		{
			dau += Trees[i][j].size();
		}
	}
	return dau;
}


int main()
{

	int N, M, K;
	std::cin >> N >> M >> K;

	map_ sangdo_land = map_(N, M);

	for (int i = 0; i < K; i++) 
	{
		sangdo_land.season();
	}


	std::cout << sangdo_land.getTrees();
	return 0;
}
