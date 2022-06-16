#include <cstdio>
#include <queue>
bool map[51][51];
int visit[51][51];
const int big = 987654321;

struct node 
{
	int x, y, a;
};

bool operator<(const node& lft, const node& rht )
{
	if (lft.a == rht.a)
		return lft.x + lft.y < rht.x + rht.y;
	return lft.a < rht.a;
}

const int dx[] = {1,-1,0,0};
const int dy[] = {0,0,1,-1};
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

//dijkstra for [0][0] ~ [N-1][N-1]
int search(int N) 
{
	auto cmp = [](const node& lft, const node& rht)->bool {return lft.a > rht.a; };
	std::priority_queue < node, std::vector<node>, decltype(cmp)> pq(cmp);
	
	pq.push({0,0,0});
	while (!pq.empty()) 
	{
		auto here = pq.top();

		pq.pop();
			
		if (here.x == N - 1 && here.y == N - 1) 
		{
			continue;
		}

		for (int i = 0; i < 4; i++) 
		{
			int next_x = here.x + dx[i];
			int next_y = here.y + dy[i];

			if (not_valid(next_x, next_y, N)) 
				continue;
            
			switch (map[next_x][next_y]) 
			{
			case 1:
				if (visit[next_x][next_y] > here.a) 
				{
					visit[next_x][next_y] = here.a;
					pq.push({ next_x,next_y,here.a });
				}
				break;
			case 0:
				if (visit[next_x][next_y] > here.a + 1)
				{
					visit[next_x][next_y] = here.a + 1;
					pq.push({next_x,next_y,here.a+1});
				}
				break;
			default:
				break;
			}

		}
	}

	return visit[N - 1][N - 1];
}

int main()
{
	int N;
	scanf("%d",&N);

	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			scanf("%1d",&map[i][j]);

	reset(N);
	int result = search(N);
	printf("%d",result);

	return 0;
}