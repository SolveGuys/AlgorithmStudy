#include<bits/stdc++.h>

const int dx[]{-1,1,0,0,0,0};
const int dy[]{0,0,1,-1,0,0};
const int dz[]{0,0,0,0,1,-1};

int x, y, z;
int tomato_count = 0;
int main() 
{
	std::cin >> x >> y >> z;

	std::vector<std::vector<std::vector<int>>> box(x, std::vector<std::vector<int>>(y, std::vector<int>(z)));
	std::vector<std::vector<std::vector<bool>>> bVisited(x, std::vector<std::vector<bool>>(y, std::vector<bool>(z)));

	struct node 
	{
		int x, y, z;
	};
	std::queue<node> q;
	for (int k = 0; k < z; k++)
	for (int j = 0; j < y; j++)
	for (int i = 0; i < x; i++)
	//for (int i = 0; i < x; i++)
	//for (int j = 0; j < y; j++)
	//for (int k = 0; k < z; k++)
	{
		std::cin >> box[i][j][k];
		if (box[i][j][k] == 1)
		{
			q.push({i,j,k});
			bVisited[i][j][k] = true;
		}
		else if (box[i][j][k] == -1)
		{
			bVisited[i][j][k] = true;
		}
		else if (box[i][j][k] == 0) 
		{
			tomato_count++;
		}
	}

	int time = 0;
	while (!q.empty())
	{
		if (tomato_count == 0)
			break;

		time++;
		int sz = q.size();
		for (int i = 0; i < sz; i++)
		{
			node front = q.front();
			q.pop();

			for (int dir = 0; dir < 6; dir++)
			{
				int nx = front.x + dx[dir];
				int ny = front.y + dy[dir];
				int nz = front.z + dz[dir];

				if (nx < 0 || nx >= x || ny < 0 || ny >= y || nz < 0 || nz >= z)
					continue;

				if (bVisited[nx][ny][nz])
					continue;

				if (box[nx][ny][nz] == 0)
				{
					bVisited[nx][ny][nz] = true;
					box[nx][ny][nz] = 1;
					q.push({ nx,ny,nz });
					tomato_count--;
				}
			}
		}
		/*
		std::cout << '\n';
		for (int k = 0; k < z; k++)
		{
			for (int j = 0; j < y; j++)
			{
				for (int i = 0; i < x; i++)
				{
					std::cout << box[i][j][k] << ' ';
				}
				//std::cout << '\n';
			}
			std::cout << '\n';
		}
		std::cout << '\n';
		*/
	}

	if (tomato_count != 0)
		std::cout << -1;
	else
		std::cout << time;

	return 0;
}