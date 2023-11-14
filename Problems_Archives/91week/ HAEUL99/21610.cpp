#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int n, m;
int a[52][52];
int d[102];
int s[102];

int dx[8] = {0, -1, -1, -1, 0, 1, 1, 1};
int dy[8] = {-1, -1, 0, 1, 1, 1, 0, -1};

int dxx[4] = {-1, -1, 1, 1};
int dyy[4] = {-1, 1, 1, -1};

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m; // 5 4

    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            cin >> a[i][j];
        }
    }
    
    for(int i = 0; i < m; i++)
    {
        cin >> d[i] >> s[i]; //d 방향으로 s칸
    }

    vector<pair<int, int>> cloud; 
    cloud.push_back(make_pair(n-2, 0)); cloud.push_back(make_pair(n-1, 0));
    cloud.push_back(make_pair(n-2, 1)); cloud.push_back(make_pair(n-1, 1));

    int cloudsize = cloud.size();

    
    for(int i = 0; i < m; i++)
    {
        int di = d[i]-1;
        int si = s[i];
        cloudsize = cloud.size();
        for(int j = 0; j < cloudsize; j++)
        {
            int curx = cloud[j].first;
            int cury = cloud[j].second;
            int cnt = si;
            while(true)
            {
                if(cnt == 0) break;
                curx = curx + dx[di];
                cury = cury + dy[di];

                if(curx < 0) curx = n-1;
                if(cury < 0) cury = n-1;
                if(curx > n-1) curx = 0;
                if(cury > n-1) cury = 0; 
                cnt--;
            }   
            cloud[j].first = curx;
            cloud[j].second = cury;
            a[curx][cury]++;  
  
        }
        
        set<pair<int, int>> s;
        for(int j = 0; j < cloudsize; j++)
        {
            int curx = cloud[j].first;
            int cury = cloud[j].second;
            int cnt = 0;
            for(int dir = 0; dir < 4; dir++)   
            {
                int nx = curx + dxx[dir];
                int ny = cury + dyy[dir];

                if(nx < 0 || nx > n-1 || ny < 0 || ny > n-1) continue;
                if(a[nx][ny] > 0) cnt++;

            }
            a[curx][cury] += cnt;
            s.insert(make_pair(curx, cury));

        }


        cloud.clear();
        for(int j = 0; j < n; j++)
        {
            for(int k = 0; k < n; k++)
            {
                if(s.find(make_pair(j, k)) != s.end()) continue;
                if(a[j][k] >= 2)
                {
                    cloud.push_back(make_pair(j, k));
                    a[j][k] = a[j][k]-2;   
                }
                
            }
        }



    }
    int ans = 0;
    for(int i = 0; i< n; i++)
    {
        for(int j = 0; j < n; j++)
        {
            ans += a[i][j];
        }
    }
    cout << ans;
}
