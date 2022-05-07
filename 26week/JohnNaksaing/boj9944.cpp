#include <iostream>
#include <cstring>

char map[32][32];
bool bVisited[32][32];
constexpr int MAX = 900;//1'000'001;
constexpr int dx[] = {-1,1,0,0};
constexpr int dy[] = { 0,0,1,-1};
int n, m;
int total_r, min_d;

void dfs(int x, int y, int now_d, int now_reached) 
{
	if (now_d >= min_d)
	{
		return;
	}

	if (now_reached == total_r)
	{
		min_d = std::min(min_d, now_d);
		return;
	}
	
	for (int dir = 0; dir < 4; dir++) 
	{
		int nx = x + dx[dir];
		int ny = y + dy[dir];

		if (bVisited[nx][ny])
			continue;
		
		int next_reached = now_reached;
		while (!bVisited[nx][ny]) 
		{
			bVisited[nx][ny] = true;
			next_reached++;
			nx += dx[dir];
			ny += dy[dir];
		}

		nx -= dx[dir]; ny -= dy[dir];

		dfs(nx, ny, now_d + 1, next_reached);
		
		while (nx != x || ny != y)
		{
			bVisited[nx][ny] = false;
			next_reached--;
			nx -= dx[dir];
			ny -= dy[dir];
		}
	}
}
int main() {
    int idx = 1;
	while (scanf("%d %d", &n, &m) == 2) {
		memset(bVisited, true, sizeof(bVisited));
		min_d = MAX;
		total_r = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf(" %c", &map[i][j]);
				if (map[i][j] == '.')
				{
                    total_r++;
                    bVisited[i][j] = false;
                }
			}
		}

		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (map[i][j] == '.') {
					bVisited[i][j] = true;
					dfs(i, j, 0, 1);
					bVisited[i][j] = false;
				}
			}
		}
		printf("Case %d: %d\n", idx++, min_d != MAX ? min_d : -1);
	}
}