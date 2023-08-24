#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>

using namespace std;

string board[100];
int visited[100][100];

int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
//9:47
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int ans = 0;
    int n = 0;
    //string board[2];
    //int visited[2][2];
    //int visited1[2][2];
    cin >> n;
    for(int i = 0; i < n; i++)
    {
        fill(visited[i], visited[i]+n, 0);
        //fill(visited1[i], visited1[i]+n, 0);
   
    }

    
    for(int i = 0; i < n; i++)
    {   
        //for(int j = 0; j < n; j++)
        cin >> board[i];
        //fill(visited[i], visited[i]+100, 0);
    }
    


    
    queue<pair<int, int> > _queue;

    //visited[0][0] = 1;
    //_queue.push(make_pair(0, 0));

    

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j] == 0)
            {
                ans++;
                _queue.push(make_pair(i, j));
                visited[i][j] = 1;
                while(!_queue.empty())
                {
                    pair<int, int> cur = _queue.front();
                    _queue.pop();

                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= n || ny <0 || ny >= n) continue;
                        if(visited[nx][ny] == 1 || board[nx][ny]!= board[cur.first][cur.second]) continue;               
                        visited[nx][ny] = 1;
                        _queue.push(make_pair(nx, ny));
                    }


                }
            }
        }
    }
    cout << ans << '\n';
 
    ans = 0;
    for(int i = 0; i < n; i++)
    {
        fill(visited[i], visited[i]+n, 0);
        //fill(visited1[i], visited1[i]+n, 0);
   
    }
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(visited[i][j] == 0)
            {
                ans++;
                _queue.push(make_pair(i, j));
                visited[i][j] = 1;
                while(!_queue.empty())
                {
                    pair<int, int> cur = _queue.front();
                    _queue.pop();

                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= n || ny <0 || ny >= n) continue;
                        if(visited[nx][ny] == 1) continue;
                        if(board[cur.first][cur.second] == 'R' && board[nx][ny] == 'B') continue;
                        if(board[cur.first][cur.second] == 'G' && board[nx][ny] == 'B') continue;
                        if(board[cur.first][cur.second] == 'B' && (board[nx][ny] == 'G' || board[nx][ny] == 'R')) continue;             
                        visited[nx][ny] = 1;
                        _queue.push(make_pair(nx, ny));
                    }


                }
            }
        }
    }


    cout << ans;

 
}

