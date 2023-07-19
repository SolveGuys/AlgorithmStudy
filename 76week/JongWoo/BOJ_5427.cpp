#include <iostream>
#include <queue>
#include <utility>

using namespace std;

char board[1'000][1'000];

// dist[0]: 불의 이동 거리
// dist[1]: 상근이의 이동 거리
int dist[2][1'000][1'000];

// 0: 상, 1: 하, 2: 좌, 3: 우
int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int w = 0, h = 0;

        cin >> w >> h;

        // fq: 불의 이동을 처리할 큐
        // sq: 상근이의 이동을 처리할 큐
        queue<pair<int, int>> fq, sq;

        for (int x = 0; x < h; ++x)
        {
            for (int y = 0; y < w; ++y)
            {
                // 테스트 케이스마다 이동 거리를 -1로 초기화
                dist[0][x][y] = dist[1][x][y] = -1;
                cin >> board[x][y];

                switch (board[x][y])
                {
                case '*': // 불
                    dist[0][x][y] = 0;
                    fq.emplace(x, y);
                    break;
                case '@': // 상근이의 시작 위치
                    dist[1][x][y] = 0;
                    sq.emplace(x, y);
                    break;
                }
            }
        }

        // 1. 불의 이동 거리 계산
        while (!fq.empty())
        {
            pair<int, int> cur = fq.front();

            fq.pop();

            for (int i = 0; i < 4; ++i)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                // 범위를 벗어나거나, 이미 방문했거나, 벽인 경우 continue
                if ((nx < 0) || (nx >= h) || (ny < 0) || (ny >= w) || (board[nx][ny] == '#') || (dist[0][nx][ny] != -1))
                {
                    continue;
                }

                // 현재까지의 거리에서 1만큼 더한 값이 다음 노드의 거리가 된다.
                dist[0][nx][ny] = dist[0][cur.first][cur.second] + 1;
                fq.emplace(nx, ny);
            }
        }

        // 2. 상근이의 이동 거리 계산
        int answer = 0x7fffffff;

        while (!sq.empty())
        {
            pair<int, int> cur = sq.front();

            sq.pop();

            // 가장자리에 도착하여 탈출할 수 있는 경우
            if ((cur.first == 0) || (cur.first == h - 1) || (cur.second == 0) || (cur.second == w - 1))
            {
                // 현재 위치에서 1을 더한 값이 답이된다.
                answer = dist[1][cur.first][cur.second] + 1;
                break;
            }

            for (int i = 0; i < 4; ++i)
            {
                int nx = cur.first + dx[i];
                int ny = cur.second + dy[i];

                // 범위를 벗어나거나, 이미 방문했거나, 벽인 경우 continue
                // + 불의 이동 거리(dist[0][nx][ny])보다 상근이의 이동 거리가 크거나 같은 경우, 즉 불이 붙은 곳으로 이동하거나 붙을 때 이동하는 경우
                // 이때, 주의할 점은 불이 붙을 수 없는 곳의 dist[0] 값은 -1이므로 (dist[0][nx][ny] != -1) 이 조건이 없다면, 항상 참이되어 불이 붙지 않은 곳으로 이동할 수 없게 된다.
                if ((nx < 0) || (nx >= h) || (ny < 0) || (ny >= w) || (board[nx][ny] == '#') || (dist[1][nx][ny] != -1) ||
                    ((dist[0][nx][ny] != -1) && (dist[1][cur.first][cur.second] + 1 >= dist[0][nx][ny])))
                {
                    continue;
                }

                // 현재까지의 거리에서 1만큼 더한 값이 다음 노드의 거리가 된다.
                dist[1][nx][ny] = dist[1][cur.first][cur.second] + 1;
                sq.emplace(nx, ny);
            }
        }

        if (answer == 0x7fffffff)
        {
            cout << "IMPOSSIBLE\n";
        }
        else
        {
            cout << answer << '\n';
        }
    }
}
