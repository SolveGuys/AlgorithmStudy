#include <iostream>
#include <stack>
#include <vector>
#include <deque>
#include <sstream>
#include <algorithm>
#include <queue>
#include <climits>
#include <tuple>
#include <string>

using namespace std;

string board[25];
int visited[25][25];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {1, -1, 0, 0};
int main(void)
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;
    

    for(int i = 0; i < n; i++)
    {
        cin >> board[i];
    }
    
    for(int i = 0; i < n; i++)
    {
        fill(visited[i], visited[i] + n, 0);
    }
    int cnt = 0;
    int area = 0;
    vector<int> vec;

    queue<pair<int, int> > _queue;  
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            if(board[i][j] == '1' && visited[i][j] == 0)
            {
                area = 0;
                cnt++;
                _queue.push(make_pair(i, j));
                visited[i][j] = 1;

                while(!_queue.empty())
                {
                    area++;
                    pair<int, int> cur = _queue.front();
                    _queue.pop();

                    for(int dir = 0; dir < 4; dir++)
                    {
                        int nx = cur.first + dx[dir];
                        int ny = cur.second + dy[dir];

                        if(nx < 0 || nx >= n || ny < 0 || ny >=n) continue;
                        if(board[nx][ny] == '0' || visited[nx][ny] == 1) continue;
                        visited[nx][ny] = 1;
                        _queue.push(make_pair(nx, ny));

                    }

                }
                vec.push_back(area);
            }
        }
    }

    sort(vec.begin(), vec.end());

    cout << cnt << '\n';
    for(int i = 0; i < vec.size(); i++)
    {
        cout << vec[i] << '\n';
    }
 
}

