#include<iostream>
#include<vector>
#include <climits>
using namespace std;

int n, m;
int hx, hy;
string board[12];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int ans = INT_MAX;
void moveR(int dir, int& rx, int& ry)
{
    while(true)
    {
        int nx = rx + dx[dir];
        int ny = ry + dy[dir];

        if(board[nx][ny] == '#') break;
        if(board[nx][ny] == 'B') break;
        if(board[nx][ny] == 'O')
        {
            board[rx][ry] = '.';
            rx = nx;
            ry = ny;
            break;
        }
        if(board[nx][ny] == '.')
        {
            board[nx][ny] = 'R';
            board[rx][ry] = '.';
            rx = nx;
            ry = ny;   
        }
    }
}

void moveB(int dir, int& bx, int& by)
{
    while(true)
    {
        int nx = bx + dx[dir];
        int ny = by + dy[dir];

        if(board[nx][ny] == '#') break;
        if(board[nx][ny] == 'R') break;
        if(board[nx][ny] == 'O')
        {
            board[bx][by] = '.';
            bx = nx;
            by = ny;
            break;
        }
        if(board[nx][ny] == '.')
        {
            board[nx][ny] = 'B';
            board[bx][by] = '.';
            bx = nx;
            by = ny;
        }
    }
}

void dfs(int cur, int bx, int by, int rx, int ry)
{
    if(cur > 10) return;
    if(bx == hx && by == hy) return;
    if(rx == hx && ry == hy)
    {
        ans = min(cur, ans);
        return;
    }
    int curbx = bx; int curby = by;
    int currx = rx; int curry = ry;
    string curboard[12];

    for(int i = 0; i < n; i++) curboard[i] = board[i];
    bool left = false; bool up = false; //빨강색이 더 왼쪽/ 위쪽 있는 경우 true
    if(ry < by) left = true;
    if(rx < bx) up = true;

    for(int dir = 0; dir < 4; dir++) //왼 오 위 아래
    {
        bx = curbx; by = curby; rx = currx; ry = curry;
        for(int i = 0; i < n; i++) board[i] = curboard[i];
        if(dir == 0)
        {
            if(left)
            {
                //r 먼저
                moveR(dir, rx, ry);
                moveB(dir, bx, by);
            }
            else
            {
                // b 먼저
                moveB(dir, bx, by);
                moveR(dir, rx, ry);
            }
        }

        if(dir == 1)
        {
            if(left)
            {
                //b 먼저
                moveB(dir, bx, by);
                moveR(dir, rx, ry);
            }
            else
            {
                // r 먼저
                moveR(dir, rx, ry);
                moveB(dir, bx, by);
            }
        }

        if(dir == 2)
        {
            if(up)
            {
                //r 먼저
                moveR(dir, rx, ry);
                moveB(dir, bx, by);
            }
            else
            {
                // b 먼저
                moveB(dir, bx, by);
                moveR(dir, rx, ry);
            }
        }

        if(dir == 3)
        {
            if(up)
            {
                //b 먼저
                moveB(dir, bx, by);
                moveR(dir, rx, ry);
            }
            else
            {
                // r 먼저
                moveR(dir, rx, ry);
                moveB(dir, bx, by);
            }
        }
        
        dfs(cur+1, bx, by, rx, ry);
    }
}

int main ()
{
    cin >> n >> m;

    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
        
    }
    int bx, by, rx, ry;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(board[i][j] == 'B')
            {
                bx = i; by = j;
            }
            if(board[i][j] == 'R')
            {
                rx = i; ry = j;
            }
            if(board[i][j] == 'O')
            {
                hx = i; hy = j;
            }
        }
    }

    dfs(0, bx, by, rx, ry);
    if(ans != INT_MAX)cout << ans;
    else cout << "-1";

}
