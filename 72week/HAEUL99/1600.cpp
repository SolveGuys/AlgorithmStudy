#include <iostream>
#include <vector>
#include <queue>
#include <deque>
#include <stack>
#include <tuple>
#include <set>
#include <cstring>
#include <stdio.h>
using namespace std;


int board[202][202];
int dx[4] = {0, 0, -1, 1}; //원숭이 
int dy[4] = {-1, 1, 0, 0};

int dxx[8] = {2, 1, -2, -1, -2, -1, 2, 1}; //말
int dyy[8] = {1, 2, 1, 2, -1, -2, -1, -2};

int visited[202][202][32]; //시작점부터 현재 좌표까지 거리(말처럼 이동한 횟수를 3번째 인자로 관리)
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int k, n, m;
    cin >> k;
    cin >> m >> n; 

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> board[i][j];
        }
    }

    fill(&visited[0][0][0], &visited[201][201][31], -1);
    bool isTrue = false;
    queue<tuple<int, int, int> > _queue;
    _queue.push(make_tuple(0, 0, 0)); // x, y, 말처럼 이동한 횟수
   visited[0][0][0] = 1;

    while(!_queue.empty())
    {
        int x, y, horse;
        tie(x, y, horse) = _queue.front();
        _queue.pop();

        if(x == n -1 && y == m - 1)
        {
            cout << visited[x][y][horse] - 1; // visited[0][0][0] = 1 로 시작했으므로 결과값에서 - 1 해준다

            isTrue = true;
            return 0;
        }

        for(int dir = 0; dir < 4; dir++)
        {
            int nx = x + dx[dir];
            int ny = y + dy[dir];

            if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
            if(visited[nx][ny][horse] == -1 && board[nx][ny] == 0)
            {
                _queue.push(make_tuple(nx, ny, horse));
                visited[nx][ny][horse] = visited[x][y][horse] + 1;
            }
        }


        if(horse + 1 <= k)
        {
            for(int dir = 0; dir < 8; dir++)
            {
                int nx = x + dxx[dir];
                int ny = y + dyy[dir];

                if(nx < 0 || nx >= n || ny < 0 || ny >= m) continue;
                if(visited[nx][ny][horse + 1] == -1 && board[nx][ny] == 0) // visited[nx][ny][horse] == -1 라고 해서 메모리초과
                {
                    _queue.push(make_tuple(nx, ny, horse + 1));
                    visited[nx][ny][horse + 1] = visited[x][y][horse] + 1;
                }
            }

        }
        
    }
    if(!isTrue)
        cout << "-1";
    
    
}
