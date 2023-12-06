#include <string>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

map<int, int> m;

int visited[500][500];

int dy[] = { 0,1,0,-1 };
int dx[] = { 1,0,-1,0 };

void BFS(int i, int j, int n, int land_cols, int land_rows, vector<vector<int>>& land) {
    int num = 1;
    queue<pair<int, int>> q;
    q.push({ i,j });
    visited[i][j] = n;
    while (!q.empty()) {
        int y, x;
        tie(y, x) = q.front();
        q.pop();
        for (int k = 0; k < 4; k++) {
            int ny = y + dy[k];
            int nx = x + dx[k];
            if (ny < 0 || nx < 0 || ny >= land_cols || nx >= land_rows || visited[ny][nx]) continue;
            if (!land[ny][nx]) continue;
            visited[ny][nx] = n;
            q.push({ ny,nx });
            num++;
        }
    }
    m[n] = num;
}

// land_rows는 2차원 배열 land의 행 길이, land_cols는 2차원 배열 land의 열 길이입니다.
int solution(vector<vector<int>> land) {
    int n = 1;

    int land_cols = land.size();
    int land_rows = land[0].size();

    for (int i = 0; i < land_cols; i++) {
        for (int j = 0; j < land_rows; j++) {
            if (land[i][j] && !visited[i][j]) {
                BFS(i, j, n, land_cols, land_rows, land);
                n += 1;
            }
        }
    }

    int answer = 0;
    for (int j = 0; j < land_rows; j++) {
        map<int, int> m1;
        int ans = 0;
        for (int i = 0; i < land_cols;i++) {
            if (visited[i][j] && !m1.count(visited[i][j])) {
                ans += m[visited[i][j]];
                m1[visited[i][j]] = 1;
            }
        }
        answer = max(ans, answer);
    }
    return answer;
}