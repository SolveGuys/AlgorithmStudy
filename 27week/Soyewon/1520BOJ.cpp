// 백준 1520 - 내리막길

#include <iostream>
#include <cstring>
#define max 500

using namespace std;


int n, m;
int coo[max][max]; // 해당 좌표값의 높이 저장
int dp[max][max]; // 경로 가짓수 저장

int dx[] = { 0, 0, -1, 1}; // 상하좌우
int dy[] = { 1, -1, 0, 0}; 

void input()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
    {
        for (int j=0; j<m; j++)
        {
            cin >> coo[i][j];
            dp[i][j] = -1; // 0으로 초기화하면 경우의 수가 0일 때와 겹치므로 -1로 초기화
        }
    }
}
 
int dfs(int x, int y)
{
    if (x==n-1 && y==m-1) return 1;
    if (dp[x][y] != -1) return dp[x][y];
 
    dp[x][y] = 0;
    for (int i=0; i<4; i++) // 상하좌우 경로탐색
    {
        int move_x = x + dx[i]; // 이동 후 x위치 move_x
        int move_y = y + dy[i]; // 이동 후 y위치 move_y
        if (move_x>=0 && move_x<n && move_y>=0 && move_y<m) // 좌표 범위 내 있는지 확인
        {
            if (coo[move_x][move_y] < coo[x][y]) // 높이가 현재 높이보다 낮다면
            {
                dp[x][y] = dp[x][y] + dfs(move_x, move_y); // 재귀 이용하여 dp배열에 저장
            }
        }
    }
    return dp[x][y];
}

int main()
{
    input();
    int ans = dfs(0,0);
    cout << ans << endl;
}
