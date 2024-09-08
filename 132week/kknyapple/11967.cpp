#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <tuple>
using namespace std;
using ll = long long;

int n, m;
vector<pair<int, int>> node[104][104]; // 각 방에서 불을 켤 수 있는 다른 방들 저장
int dy[] = { -1,0,1,0 }, dx[] = { 0,1,0,-1 };
int a, b, c, d;
bool light[104][104];
bool visited[104][104];
int ans;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> a >> b >> c >> d;
        node[a][b].push_back({ c,d });
    }

    int y, x;
    queue<pair<int, int>> q;
    light[1][1] = 1;
    ans++;

    while (1) { // (1, 1) 부터 불켜고 bfs 탐색 반복
        int flag = 0;
        q.push({ 1,1 });

        for (int i = 1; i <= n; i++) {
            for (int j = 1; j <= n; j++) {
                visited[i][j] = 0;
            }
        }

        visited[1][1] = 1;

        while (!q.empty()) {

            tie(y, x) = q.front();
            q.pop();

            // 현재 방에서 켤 수 있는 방 불 켜기
            for (auto e : node[y][x]) {
                if (light[e.first][e.second] == 0) {
                    light[e.first][e.second] = 1;
                    ans++;
                    flag = 1;
                }
            }

            // 불 켜진 방 탐색
            for (int i = 0; i < 4; i++) {
                int ny = dy[i] + y;
                int nx = dx[i] + x;

                if (ny < 1 || nx < 1 || ny > n || nx > n) continue;
                if (visited[ny][nx]) continue;
                if (light[ny][nx]) { // 불 켜진 방만 탐색 가능
                    q.push({ ny, nx });
                    visited[ny][nx] = 1;
                }

            }
        }

        if (flag == 0) break; // 새로운 불이 켜지지 않았다면 종료
    }

    cout << ans << "\n";

    return 0;
}
