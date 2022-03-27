#include <vector>
#include <iostream>
#include <algorithm>
#include <cstring>
struct Fish 
{
	int x, y, dir;        //dir=-1: 죽은 물고기
};

Fish fishes[17];

const int dx[8] = { -1,-1,0,1,1,1,0,-1 };
const int dy[8] = { 0,-1,-1,-1,0,1,1,1 };
const int dead_idx = -1;

int g_maxSum = 0;
int map[4][4];      //1~16: 물고기, 0: Shark, -1: 죽은 물고기


void move_fishes() 
{
	for (int i = 1; i < 17; i++)
	{
		int cx = fishes[i].x;
		int cy = fishes[i].y;
		int cd = fishes[i].dir;

		if (cd == dead_idx) continue;       //죽은 물고기
		
		int nx, ny;
		int nd = cd;
		for (int j = 0; j < 8; j++)
		{
			nx = cx + dx[nd];
			ny = cy + dy[nd];
			if (nx >= 0 && ny >= 0 && nx < 4 && ny < 4)
			{
				int idx = map[nx][ny];
				if (idx == 0)
				{     //shark
					nd = (nd + 1) % 8;
					continue;
				}
				//물고기 자리 교환
				map[nx][ny] = i;
				fishes[i].x = nx;
				fishes[i].y = ny;
				fishes[i].dir = nd;

				map[cx][cy] = idx;
				fishes[idx].x = cx;
				fishes[idx].y = cy;
				break;
			}
			nd = (nd + 1) % 8;
		}
	}
}

void dfs(int x, int y, int dir, int sum) 
{
	Fish f_next[17];
	int map_next[4][4];
	//복사
	for (int i = 1; i < 17; i++)
		f_next[i] = fishes[i];
	memcpy(map_next, map, sizeof(map_next));

	//물고기 이동
	move_fishes();

	//상어 이동
	int next_x = x;
	int next_y = y;

	for(int dist = 1; dist < 4; dist++)
	{
		next_x += dx[dir];
		next_y += dy[dir];
		if (next_x >= 0 && next_y >= 0 && next_x < 4 && next_y < 4)
		{
			int idx = map[next_x][next_y];
			if (idx == dead_idx)
				continue;
			
			//물고기
			int food_dir = fishes[idx].dir;
			
			fishes[idx].dir = dead_idx;
			map[x][y] = dead_idx;
			map[next_x][next_y] = 0;
			dfs(next_x, next_y, food_dir, sum + idx);
			

			fishes[idx].dir = food_dir;
			map[x][y] = 0;
			map[next_x][next_y] = idx;
		}
		else break;
	}
	g_maxSum = std::max(g_maxSum, sum);

	//원복
	memcpy(map, map_next, sizeof(map_next));
	for (int i = 1; i < 17; i++)
		fishes[i] = f_next[i];
	return;
}

int main() {
	int num, dir, food_idx;
	for (int i = 0; i < 4; i++) 
	{
		for (int j = 0; j < 4; j++)
		{
			std::cin >> num >> dir;
			map[i][j] = num;
			fishes[num].x = i;
			fishes[num].y = j;
			fishes[num].dir = dir - 1;
		}
	}
	food_idx = map[0][0];
	int food_dir = fishes[food_idx].dir;
	fishes[food_idx].dir = -1;
	map[0][0] = 0;

	dfs(0, 0, food_dir, food_idx);
	std::cout << g_maxSum;
	return 0;
}