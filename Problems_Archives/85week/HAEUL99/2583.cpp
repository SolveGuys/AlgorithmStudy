#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n, m, k;
int board[102][102];
int vis[102][102];
int x1, x2, y1, y2; //세로 가로
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
    cin >> n >> m >> k;

    for(int i = 0; i < k; i++)
    {
        cin >> y1 >> x1 >> y2 >> x2;
        for(int a = x1; a < x2; a++)
        {
            for(int b = y1; b < y2; b++)
            {
                board[a][b] = 1;
            }
        }
    }

    // for(int i = 0; i < n; i++)
    // {
    //     for(int j = 0; j < m; j++)
    //     {
    //         cout << board[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    int cnt = 0;
    vector<int> res;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(vis[i][j] == 0 && board[i][j] == 0)
            {
                vis[i][j] = 1;
                int area = 1;
                cnt++;

                queue<pair<int, int>> q;
                q.push(make_pair(i, j));

                while(!q.empty())
                {
                    int curx = q.front().first;
                    int cury = q.front().second;

                    q.pop();

                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = curx + dx[dir];
                        int ny = cury + dy[dir];

                        if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) continue;
                        if(board[nx][ny] == 1) continue;
                        if(vis[nx][ny] == 1) continue;
                        vis[nx][ny] = 1;
                        area++;
                        q.push(make_pair(nx, ny));
                    }
                }
                res.push_back(area);

                
            }
        }
    }

    sort(res.begin(), res.end());
    cout << cnt << endl;
    for(auto x: res) cout << x << ' ';
    
}
