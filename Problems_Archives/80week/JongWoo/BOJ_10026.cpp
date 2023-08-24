#include <iostream>
#include <queue>
#include <utility>

using namespace std;

int n;
char board[100][100];
bool isVisited[100][100];

int dx[] = { -1, 1, 0, 0 };
int dy[] = { 0, 0, -1, 1 };

void BFS(int sx, int sy);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            cin >> board[i][j];
        }
    }

    // 1. 적록색약이 아닌 사람이 봤을 때의 구역의 수
    int cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!isVisited[i][j])
            {
                BFS(i, j);
                ++cnt;
            }
        }
    }

    cout << cnt << ' ';

    // 2. 적록색약인 사람이 봤을 때의 구역의 수
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (board[i][j] == 'G')
            {
                board[i][j] = 'R';
            }

            isVisited[i][j] = false;
        }
    }

    cnt = 0;

    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if (!isVisited[i][j])
            {
                BFS(i, j);
                ++cnt;
            }
        }
    }

    cout << cnt << '\n';
}

void BFS(int sx, int sy)
{
    queue<pair<int, int>> q;

    isVisited[sx][sy] = true;
    q.emplace(sx, sy);

    while (!q.empty())
    {
        pair<int, int> cur = q.front();

        q.pop();

        for (int i = 0; i < 4; ++i)
        {
            int nx = cur.first + dx[i];
            int ny = cur.second + dy[i];

            if ((nx < 0) || (nx >= n) || (ny < 0) || (ny >= n) || (board[cur.first][cur.second] != board[nx][ny]) || (isVisited[nx][ny]))
            {
                continue;
            }

            isVisited[nx][ny] = true;
            q.emplace(nx, ny);
        }
    }
}
