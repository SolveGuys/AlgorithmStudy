#include<iostream>
#include<queue>
#include<algorithm>
#include<functional>
#include<vector>
bool bWall[101][101];

const int dx[]{0,0,1,-1};
const int dy[]{ 1,-1, 0,0};
int main()
{
	struct node 
	{
		int x, y;

		int dist;
	};

	int n, m;
	scanf("%d %d",&m,&n);
	
	int b;
	for (int i = 0; i < n; i++)
	for (int j = 0; j < m; j++)
	{
		scanf("%1d", &b);
		bWall[i][j] = b;
	}

	std::vector<std::vector<int>> dist(n,std::vector<int>(m,1e9));
	auto d = [](const node& a, const node& b)->bool {return a.dist < b.dist; };
	std::priority_queue<node,std::vector<node>,decltype(d)> pq(d);
	
	pq.push({0,0,0});
	dist[0][0] = 0;
	
	while (!pq.empty()) 
	{
		node top = pq.top();
		pq.pop();

		for (int dir = 0; dir < 4; dir++) 
		{
			node next {top.x + dx[dir], top.y + dy[dir],top.dist};

			if (next.x < 0 || next.x >= n || next.y < 0 || next.y >= m)
				continue;

			if (bWall[next.x][next.y])
				next.dist++;

			if (next.dist < dist[next.x][next.y])
			{
				dist[next.x][next.y] = next.dist;
				pq.push(next);
			}
		}
	}	

	printf("%d",dist[n-1][m-1]); 
	return 0;
}