#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <set>
#include <cstring>
#include <string>
#include <stdio.h>
using namespace std;

int board[20][20];
int n;
int ans;
int dx[3] = {0, 1, 1};
int dy[3] = {1, 1, 0};
queue<tuple<int, int, int>> q; // x, y, 방향(0: 가로, 1: 세로, 2: 대각선)
void next(int x, int y, int dir)
{
    int nx = x + dx[dir];
    int ny = y + dy[dir]; 

    if(board[nx][ny] != 0) return;
    if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1) return;
    if(dir == 1)
    {
        if(board[nx-1][ny] == 1 || board[nx][ny-1] == 1)
        {
            return;
        }
    } 

    q.push(make_tuple(nx, ny, dir));
     

}

int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n;

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> board[i][j];
        }
    }

    
    q.push(make_tuple(0, 1, 0));
    
    while(!q.empty())
    {
        int curx = get<0>(q.front());
        int cury = get<1>(q.front());
        int curdir = get<2>(q.front());

        q.pop();

        if(curx == n-1 && cury == n-1) ans++;

        if(curdir == 0) //가로
        {
            for(int i = 0; i < 2; i++) // 0, 1
            {
                next(curx, cury, i);
            }
        }
        if(curdir == 1) // 대각선
        {
            for(int i = 0; i < 3; i++) // 1, 2
            {
                next(curx, cury, i);
            }
        }
        if(curdir == 2) //세로
        {
            for(int i = 1; i < 3; i++) // 0, 1, 2
            {
                next(curx, cury, i);
            }
        }


    }

    cout << ans;

    


    
}
