#include<queue>
#include<iostream>
#include<algorithm>

bool bMap[25 + 2][25 + 2];
bool bVisited[25 + 2][25 + 2];

const int dx[]{-1,1,0,0};
const int dy[]{0,0,1,-1};
int main()
{
	struct node 
	{
		int x, y;
	};

	int n;
	std::cin >> n;
	int b;
	std::queue<node> q;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		scanf("%1d", &b);
		bMap[i][j] = b;
	}
	std::vector<int> sizes;

	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	{
		if (bMap[i][j] && !bVisited[i][j])
		{
			q.push({ i,j });
			bVisited[i][j] = true;

			int count = 1;
			while (!q.empty())
			{
				node here = q.front();
				q.pop();

				for (int i = 0; i < 4; i++)
				{
					node next{ here.x + dx[i],here.y + dy[i] };
					
					if (bMap[next.x][next.y] && !bVisited[next.x][next.y] )
					{
						bVisited[next.x][next.y] = true;
						count++;
						q.push(next);
					}
				}
			}
			sizes.push_back(count);
		}
    }
	std::sort(sizes.begin(),sizes.end());
	std::cout << sizes.size();
	for (int sz : sizes) 
	{
		std::cout << '\n' << sz;
	}
	
	return 0;
}