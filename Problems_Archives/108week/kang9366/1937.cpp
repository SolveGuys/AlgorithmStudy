#include <iostream>

#define MAX 500

using namespace std;

int N;
int map[MAX][MAX];
int dp[MAX][MAX];
bool visited[MAX][MAX];
int dx[4] = {1, 0, 0, -1};
int dy[4] = {0, 1, -1, 0};

int dfs(int x, int y) {
    if(visited[x][y]) return dp[x][y];
    visited[x][y] = true;
    dp[x][y] = 1;

    for(int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx < 0 || ny < 0 || nx >= N || ny >= N) continue;
        if(map[nx][ny] > map[x][y]) dp[x][y] = max(dp[x][y], dfs(nx, ny)+1);
    }
    return dp[x][y];
}

int main() {
    int answer = 0;
    cin >> N;
    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            cin >> map[i][j];
        }
    }

    for(int i = 0; i < N; i++) {
        for(int j = 0; j < N; j++) {
            answer = max(answer, dfs(i, j));
        }
    }

    cout << answer;
}
