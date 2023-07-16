#include <iostream>
#include <string>
#include <vector>

using namespace std;

int n;

int dx[4] = {0,-1,0,1};
int dy[4] = {1,0,-1,0};
int board[102][102];
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    int x, y, d, g;
    int nx, ny;
    int enx, eny;
    int ddx, ddy;
    int tenx, teny;
    for(int i = 0; i < n; i++)
    {
        cin >> y >> x >> d >> g;
        board[x][y] = 1;
        vector<pair<int, int>> _vec;
        _vec.push_back(make_pair(x, y));
        for(int k = 0; k <= g; k++)
        {
            if(k == 0) // 0세대일때
            {
                nx = x + dx[d];
                ny = y + dy[d];
                _vec.push_back(make_pair(nx, ny));
                board[nx][ny] = 1;
                enx = nx;
                eny = ny;
            }
            else
            {
                int ss = _vec.size();
                for(int j = 0; j < ss; j++)
                {
                    ddx = _vec[j].first - enx;
                    ddy = _vec[j].second - eny;
                    nx = enx + ddy;
                    ny = eny - ddx;
                    if(j == 0)
                    {
                        tenx = nx;
                        teny = ny;
                    }
                    _vec.push_back(make_pair(nx, ny));
                    board[nx][ny] = 1;
                }
                enx = tenx;
                eny = teny;
  
            }

        }
        

    }
    int ans = 0;
    for(int i = 0; i < 101; i++)
    {
        for(int j = 0; j < 101; j++)
        {
            if(board[i][j] == 1 && board[i][j+1] && board[i+1][j] && board[i+1][j+1])
            {
                ans++;
            }
        }
    }

    cout << ans;


}
