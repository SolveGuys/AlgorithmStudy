#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
#include<algorithm>
using namespace std;

int n; 
string str;
int a[7][20005];
int vis[7][20005];
int dx[4] = {0, 0, -1, 1};
int dy[4] = {-1, 1, 0, 0};
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n; 
    cin >> str;

    string ans;
    int k = n/5; //k==8

    for(int i = 0; i < 5; i++)
    {
        for(int j = 0; j < k; j++)
        {
            if(str[i*k + j] == '#') a[i][j] = 1;
            else a[i][j] = 0;
        }
    }


    // for(int i = 0; i < 5; i++)
    // {
    //     for(int j = 0; j < k; j++)
    //     {
    //         cout << a[i][j] << ' ';
    //     }
    //     cout << endl;
    // }

    for(int i = 0; i < 7; i++)
    {
        fill(vis[i], vis[i]+20004, -1);
    }
    for(int i = 0; i < k; i++)
    {

        if(a[0][i] == 1 && vis[0][i] == -1)
        {

            //if(i == 5)cout << i << endl;
            queue<pair<int, int>> q;
            q.push(make_pair(0, i)); // xy
            vis[0][i] = 1;
            int num = 1;
            
            while(!q.empty())
            {
                int curx = q.front().first; 
                int cury = q.front().second; 
                q.pop();

                for(int dir = 0; dir < 4; dir++)
                {
                    int nx = curx + dx[dir];
                    int ny = cury + dy[dir];
                    
                    if(nx < 0 || nx >=5 || ny< i || ny >= i+3) continue;
                    if(vis[nx][ny] != -1) continue;
                    if(a[nx][ny] == 0) continue;
                    vis[nx][ny] = 1;
                    q.push(make_pair(nx, ny));
                    num++;
                    

                }
            }
            //  0/ 1/  2/  3/ 4/  5/  6/ 7/  8/  9
            // 12/ 5/ 11/ 11/ 9/ 11/ 12/ 7/ 13/ 12
            if(num == 5) ans += "1"; 
            if(num == 9) ans += "4";
            if(num == 7) ans += "7";
            if(num == 13) ans += "8";
            if(num == 12) // 0, 6, 9
            {
                if(a[3][i] == 1 && a[1][i+2] == 1) ans += "0";
                if(a[3][i] == 1 && a[1][i+2] == 0) ans += "6";
                if(a[3][i] == 0) ans += "9";

            }
            if(num == 11) // 2 3 5 
            {
                if(a[3][i] == 1) ans += "2";
                if(a[3][i] == 0 && a[1][i] == 0) ans+= "3";
                if(a[3][i] == 0 && a[1][i] == 1) ans+= "5";

            }

        }
    }


    cout << ans;

}
