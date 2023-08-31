#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include<algorithm>
using namespace std;

//11:24 - 
int n, m;
string board[1002];
int vis[1004][1004][4];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }

    fill(&vis[0][0][0], &vis[1003][1003][3], -1);

    queue<tuple<int, int, int>> q;
    vis[0][0][0] = 1;
    q.push(make_tuple(0, 0, 0)); // x, y, 1제거횟수


    while(!q.empty())
    {
        int curx = get<0>(q.front());
        int cury = get<1>(q.front());
        int num = get<2>(q.front());
        q.pop();
        if(curx == n-1 && cury == m-1) 
        {
            cout << vis[curx][cury][num]; 
            return 0;
        }
        for(int dir = 0; dir < 4; dir++)
        {
            int nx = curx + dx[dir];
            int ny = cury + dy[dir];
            
            if(nx < 0 || nx >= n || ny < 0 || ny>=m) continue;

            if(board[nx][ny] == '0')
            {
                if(vis[nx][ny][num] != -1) continue;
                vis[nx][ny][num] = vis[curx][cury][num] + 1;
                q.push(make_tuple(nx, ny, num));

            }
            if(board[nx][ny] == '1' && num == 0)
            {

                if(vis[nx][ny][num+1] != -1) continue;
                vis[nx][ny][num+1] = vis[curx][cury][num] + 1;
                q.push(make_tuple(nx, ny, num+1));

            }
        }
    }
    
    cout << -1;


}
