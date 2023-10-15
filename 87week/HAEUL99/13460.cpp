#include<bits/stdc++.h>
using namespace std;

string board[12];
int hx, hy;
int n, m;
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
bool isFind = false;
int ans = INT_MAX;
void dfs(int cur,int bx, int by, int rx, int ry)
{
    if(cur > 10)
    {
        return;
    }
    
    //성공 (빨간 구슬만 빠짐)
    if((rx == hx && ry == hy) && !(bx == hx && by == hy)) 
    {
        ans = min(ans, cur);
        return;
    }

    //실패 (둘다 빠짐)
    if((rx == hx && ry == hy) && (bx == hx && by == hy)) 
    {
        return;
    }

    //실패 (파란 구슬만 빠짐)
    if(!(rx == hx && ry == hy) && (bx == hx && by == hy)) 
    {
        return;
    }
    int origin_rx = rx;
    int origin_ry = ry;
    int origin_bx = bx;
    int origin_by = by;
    string origin_board[12];
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            origin_board[i][j] = board[i][j];
        }
    }
    for(int dir = 0; dir < 4; dir++)
    {
        int first = 0; // 0: r, 1: b
        
        rx = origin_rx; ry = origin_ry; bx = origin_bx; by = origin_by;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                board[i][j] = origin_board[i][j];
            }
        }


        
        if(dir == 0)
        {
            if(ry < by) first = 0;
            else first = 1; 
        }
        if(dir == 1)
        {
            if(ry < by) first = 1;
            else first = 0;
        }
        if(dir == 2)
        {
            if(rx < bx) first = 0;
            else first = 1;
        }
        if(dir == 3)
        {
            if(rx < bx) first = 1;
            else first = 0;
        }

       
        if(first == 0)
        {
            //R 옮기기
            while(true)
            {
                int nx = rx + dx[dir];
                int ny = ry + dy[dir]; 

                if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) break;
                if(board[nx][ny] == '#') break;
                if(nx == hx && ny == hy)
                {
                    board[nx][ny] = 'R'; board[rx][ry] = '.';
                    rx = nx;
                    ry = ny;
   
                    break;
                }
                board[nx][ny] = 'R'; board[rx][ry] = '.';
                rx = nx;
                ry = ny;
            }

            //B 옮기기
            while(true)
            {
                int nx = bx + dx[dir];
                int ny = by + dy[dir]; 

                if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) break;
                if(nx == hx && ny == hy)
                {
                    board[nx][ny] = 'B'; board[bx][by] = '.';
                    bx = nx;
                    by = ny;
                    break;
                }
                if(board[nx][ny] == '#' || board[nx][ny] == 'R') break;
                
                board[nx][ny] = 'B'; board[bx][by] = '.';
                bx = nx;
                by = ny;
            }
        }
        if(first == 1)
        {
            //B 옮기기
            while(true)
            {
                int nx = bx + dx[dir];
                int ny = by + dy[dir]; 

                if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) break;
                if(board[nx][ny] == '#') break;
                if(nx == hx && ny == hy)
                {
                    board[nx][ny] = 'B'; board[bx][by] = '.';
                    bx = nx;
                    by = ny;
                    break;
                }
                board[nx][ny] = 'B'; board[bx][by] = '.';
                
                bx = nx;
                by = ny;
            }

            //R 옮기기
            while(true)
            {
                int nx = rx + dx[dir];
                int ny = ry + dy[dir]; 
            
                if(nx < 0 || nx > n-1 || ny < 0 || ny > m-1) break;
                if(nx == hx && ny == hy)
                {
                    board[nx][ny] = 'R'; board[rx][ry] = '.';
                    rx = nx;
                    ry = ny;
   
                    break;
                }
                if(board[nx][ny] == '#' || board[nx][ny] == 'B') break;
                
                board[nx][ny] = 'R'; board[rx][ry] = '.';
                rx = nx;
                ry = ny;
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
    if(ans == INT_MAX) ans = -1;
    cout << ans;
    


}

