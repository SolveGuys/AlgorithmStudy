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

int board[102][102];

int visited[102][102];
int visited1[102][102];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int n, m;
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;


    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {

            cin >> board[i][j];
        }
    }


    int cnt = 0;
    int area = 0;
    int prevarea = 0;
        
    while(true)
    {
        for(int i = 0; i < n; i++)
        {
            fill(visited[i], visited[i] + m, -1);
            fill(visited1[i], visited1[i] + m, -1);
        } 

        queue<pair<int, int>> _queue1; 
     
        int islandNum = 0;
        prevarea = 0;
        prevarea = area;
        area = 0;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1 && visited1[i][j] == -1) 
                {
                    islandNum++;
                    area++;
                    _queue1.push(make_pair(i, j));
                    visited1[i][j] = 1;
                    while(!_queue1.empty())
                    {
                        auto cur = _queue1.front();
                        _queue1.pop();

                        for(int dir = 0; dir < 4; dir++)
                        {
        
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(board[nx][ny] != 1 || visited1[nx][ny] != -1) continue;
                            _queue1.push(make_pair(nx, ny));
                            visited1[nx][ny] = 1; 
                            area++;
                        }
                    }
                
                }
            }

        }
        
        
        if(islandNum == 0)
        {
            break;
        }

        cnt++;
        
        queue<pair<int, int> > _queue; //바다에 번호 부여

        int seanum = 10; //board[][] 가 10이상이면 바다
        int firstseanum = seanum;
        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 0 && visited[i][j] == -1)
                {
                    _queue.push(make_pair(i, j));
                    visited[i][j] = 1;
                    board[i][j] = seanum;
                    while(!_queue.empty())
                    {
                        auto cur = _queue.front();
                        _queue.pop();

                        for(int dir = 0; dir < 4; dir++)
                        {
                            int nx = cur.first + dx[dir];
                            int ny = cur.second + dy[dir];

                            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                            if(board[nx][ny] != 0 || visited[nx][ny] != -1) continue;
                            _queue.push(make_pair(nx, ny));
                            visited[nx][ny] = 1; 
                            board[nx][ny] = seanum;
                        }
                    }
                    seanum = seanum + 1;
                }
            }
        }

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == 1)
                {
                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = i + dx[dir];
                        int ny = j + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                        if(board[nx][ny] == 10)
                        {
                            board[i][j] = -1;
                            break;
                        }
                    }
                }
            }

        }  
    

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < m; j++)
            {
                if(board[i][j] == -1 || board[i][j] >= 10)
                {
                    board[i][j] = 0;
                }
            }

        }    
        
    }
   
    
    std::cout << cnt << '\n';
    std::cout << prevarea;
    





}
