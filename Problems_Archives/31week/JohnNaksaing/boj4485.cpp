#include <bits/stdc++.h>
int map[125][125];
int visit[125][125];
const int big = 987654321;
struct node 
{
	int x, y, a;
};
const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
auto cmp = [](const node& lft, const node& rht)->bool {return lft.a > rht.a; };
void reset(int N) 
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			visit[i][j] = big;
}

bool not_valid(int x, int y, int N) 
{
	return (x < 0 || x >= N || y < 0 || y >= N);
}
int search(int N) 
{
	//dijkstra for [0][0] ~ [N-1][N-1]
	visit[0][0] = map[0][0];

    //https://blog.naver.com/typeon/221584690090
	std::priority_queue < node, std::vector<node>, decltype(cmp)> pq(cmp);
	pq.push({0,0,map[0][0]});
	
	while (!pq.empty()) 
	{
		auto here = pq.top();

		pq.pop();
			
		for (int i = 0; i < 4; i++) 
		{
			int next_x = here.x + dx[i];
			int next_y = here.y + dy[i];

			if (not_valid(next_x, next_y, N)) 
				continue;

			int next_a = here.a + map[next_x][next_y];

			if (next_a < visit[next_x][next_y])
			{
				visit[next_x][next_y] = next_a;
				pq.push({next_x,next_y,next_a});
			}
		}
	}

	return visit[N - 1][N - 1];
}

int main()
{
	std::ios_base::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	
	int N;
	int prob_idx = 1;

	while (true) 
	{
		std::cin >> N;
		if (N == 0) break;

		for (int i = 0; i < N; i++) 
		{
			for (int j = 0; j < N; j++)
				std::cin >> map[i][j];
		}
		reset(N);
		int dist = search(N);
		std::cout << "Problem " << prob_idx++ << ": " << dist << '\n';
	}

	return 0;
}