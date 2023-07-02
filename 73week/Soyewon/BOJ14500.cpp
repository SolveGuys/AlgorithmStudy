// 백준 14500 - 테트로미노

#include <iostream>
#include <algorithm>

using namespace std;

// 상하좌우 이동
int dx[4] = {0, 0, -1, 1}; 
int dy[4] = {1, -1, 0, 0};

int map[500][500];
int visit[500][500];
int n, m, result; // 가로, 세로, 결과

// ㅏ모양 체크
void FindOtherShaperesult(int y, int x)
{
    // ㅏ
    if (y + 2 < n && x + 1 < m)
        result = max(result, map[y][x] + map[y + 1][x] + map[y + 1][x + 1] + map[y + 2][x]);
    // ㅜ
    if (y + 1 < n && x + 2 < m)
        result = max(result, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y + 1][x + 1]);
    // ㅓ
    if (y + 2 < n && x - 1 >= 0)
        result = max(result, map[y][x] + map[y + 1][x] + map[y + 1][x - 1] + map[y + 2][x]);
    // ㅗ
    if (y - 1 >= 0 && x + 2 < m)
        result = max(result, map[y][x] + map[y][x + 1] + map[y][x + 2] + map[y - 1][x + 1]);
}

// depth 4인 도형들 체크
void FindDepth4Mac(int L, int sum, int y, int x)
{
    if (L == 4)
    {
        result = max(result, sum);
        return;
    }
    for (int i = 0; i < 4; i++)
    {
        int nx = x + dx[i]; // 상하좌우 이동
        int ny = y + dy[i];
        if (ny < 0 || nx < 0 || ny >= N || nx >= M)
            continue;
        if (visit[ny][nx])
            continue;
        visit[ny][nx] = true; 
        findDepth4Max(L + 1, sum + map[ny][nx], ny, nx);
        visit[ny][nx] = false; // 새로 dfs 돌기 전 visit 초기화
    }
}

void FindMax(int y, int x)
{
    FindOtherShapeMax(y, x); // depth가 4가 아닌 'ㅏ' 먼저 찾기

    visit[y][x] = true;
    FindDepth4Max(1, map[y][x], y, x);
    visit[y][x] = false;
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            cin >> map[i][j];
        }
    }

    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            FindMax(i, j);
        }
    }

    cout << result;
    return 0;

}
