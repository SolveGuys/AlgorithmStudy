#include <iostream>
#include <string>
#include <queue>
using namespace std;

int t;
int w, h;
string board[1002];

int dx[4] = {0, 0, -1, 1}; // 좌 우 위 아래
int dy[4] = {-1, 1, 0, 0};

int firemap[1002][1002];
int playermap[1002][1002];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> w >> h;
        
        for(int i = 0; i < h; i++)
        {
            cin >> board[i];
        }

        queue<pair<int, int>> _fire;
        queue<pair<int, int>> _player;  

        for(int i = 0; i < h; i++)
        {
            fill(firemap[i], firemap[i]+ w, 0);
            fill(playermap[i], playermap[i]+ w, 0);
        }
        //불 위치
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(board[i][j] == '*')
                {
                    _fire.push(make_pair(i, j));
                    firemap[i][j] = 1;
                }
            }
        }
        //상근이 위치
        for(int i = 0; i < h; i++)
        {
            for(int j = 0; j < w; j++)
            {
                if(board[i][j] == '@')
                {
                    _player.push(make_pair(i, j));
                    playermap[i][j] = 1;
                }
            }
        }

        while(!_fire.empty())
        {
            int curx = _fire.front().first;
            int cury = _fire.front().second;
            _fire.pop();

            for(int dir = 0; dir < 4; dir++)
            {
                int nx = curx + dx[dir];
                int ny = cury + dy[dir];

                if(nx < 0 || nx > h-1|| ny < 0 || ny > w-1) continue;
                if(board[nx][ny] == '#') continue;
                if(firemap[nx][ny] > 0) continue;
                _fire.push(make_pair(nx, ny));
                firemap[nx][ny] = firemap[curx][cury] + 1;
            }
        }


        //int ans = 0;
        bool isP = false;
        while(!_player.empty())
        {
            int curx = _player.front().first;
            int cury = _player.front().second;
            _player.pop();

            if(curx == 0 || curx == h-1 || cury ==0 || cury == w-1)
            {
                cout << playermap[curx][cury]<< '\n';
                isP = true;
                break;
                
            }
            for(int dir = 0; dir < 4; dir++)
            {
                int nx = curx + dx[dir];
                int ny = cury + dy[dir];

                if(nx < 0 || nx > h-1|| ny < 0 || ny > w-1) continue;
                if(board[nx][ny] == '#') continue;
                if((firemap[nx][ny] <= playermap[curx][cury] + 1) && firemap[nx][ny] > 0) continue;
                if(playermap[nx][ny] > 0) continue;
                _player.push(make_pair(nx, ny));
                playermap[nx][ny] = playermap[curx][cury] + 1;
            }
        }

        if(isP == false)
            cout << "IMPOSSIBLE\n";

    }

}
