#include <bits/stdc++.h>

const int dx[]{-1,1,0,0};
const int dy[]{0,0,1,-1};

int max_count = -1;
int r, c;

using bits = int;
bits hist[21][21];
char map[21][21];


void dfs(int x, int y, int score, bits visit) 
{
    //상위권 풀이에서 참고한 backtracking
    if(hist[x][y] == visit)
        return;
    hist[x][y] = visit;
    //////////////////////////
    /*
        다음 그림에서 C의 경우
        AABAA
        ABCBA
        어느 B에서 C에 오던 간에 이후에 탐색되는 경우의 수는 모두 한 가지(아래방향)밖에 없다.
        남은 알파벳의 경우의 수가 같으면 가지치기가 가능함.

        이런걸 실전에서 생각하라고...?
    */

    if(max_count < score)
        max_count = score;

	for (int dir = 0; dir < 4; dir++)
	{
        int nx = x + dx[dir];
        int ny = y + dy[dir];
        
		if (nx < 0 || nx >= r || ny < 0 || ny >= c)
			continue;

		if (visit >> (map[nx][ny] - 'A') & 0x1)
			continue;

        dfs(nx,ny,score+1,visit | 1 << (map[nx][ny] - 'A'));
	}
}

int main() 
{
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    
	std::cin >> r >> c;
	
	for (int i = 0; i < r; i++)
	for (int j = 0; j < c; j++)
		std::cin >> map[i][j];

	dfs(0,0,1,1 << (map[0][0] - 'A'));

	std::cout << max_count;
	return 0;
}