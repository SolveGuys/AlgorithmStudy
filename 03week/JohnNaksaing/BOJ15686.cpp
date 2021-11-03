#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

template<class where>
struct compare_taxi
{
	bool operator()(where a, where b)
	{
		if (a.x < b.x) return true;
		else if (a.x == b.x) return a.y < b.y;
		return false;
	}
};
int main()
{
	int N, M;
	std::cin >> N >> M;
	//std::vector<std::vector<int>> map(N, std::vector<int>(N));
	struct where
	{
		int x, y;
		where(int x, int y) : x{ x }, y{ y }{}
	};
	std::vector<where> houses;
	std::vector<where> chicks;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			int now;
			std::cin >> now;
			//map[i][j] = now;
			switch (now)
			{
			case 1:
				houses.push_back(where(i, j));
				break;
			case 2:
				chicks.push_back(where(i, j));
				break;
			default:
				break;
			}
		}
	}
	std::sort(chicks.begin(), chicks.end(), compare_taxi<where>());

	int chick_size = chicks.size();
	std::vector<int> selected(chick_size);
	for (int i = 0; i < M; i++) 
	{
		selected[chick_size - 1 - i] = 1;
	}

	int dist_sum = 1<<30;
	do
	{
		/*
		auto first = chicks.begin();
		auto last = chicks.begin() + M;
		std::vector<where> left_chicks(first, last);
		*/

		//find distance's sum
		int dist_sum_now = 0;
		for (const auto& house : houses)
		{
			int dist_min = 1 << 30;
			//for (const auto& left_chick : left_chicks)
			for(int i = 0; i < chick_size; i++)
			{
				if(selected[i])
					dist_min = std::min(dist_min, std::abs(chicks[i].x - house.x) + std::abs(chicks[i].y - house.y));
			}
			dist_sum_now += dist_min;
		}
		dist_sum = std::min(dist_sum, dist_sum_now);
	} while (std::next_permutation(selected.begin(), selected.end()));
	
	std::cout << dist_sum;
	return 0;
}
