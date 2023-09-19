#include <iostream>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>

using namespace std;

int n, k;
int vis[300010]; // - + *
int v;

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    // if(n == k)
    // {
    //     cout << "0" << endl;
    //     cout << "1";
    //     return 0;
    // }

    int b = max(n, k);
    int cnt = 0;
    queue<pair<int, int>> q;
    q.push(make_pair(n, 0));
    vis[n] = 1;
    while(!q.empty())
    {
        int cur = q.front().first;
        int dist = q.front().second;

        q.pop();
        vis[cur] = 1;

        if(cnt > 0 && dist == v &&  cur == k)
        {
            cnt++;
        }
        if(cur == k && cnt == 0)
        {
            cnt++;
            v = dist;
        }
        
        for(int i = 0; i < 3; i++)
        {
            int nxt = 0;
            if(i == 0) nxt = cur - 1;
            else if(i == 1) nxt = cur + 1;
            else nxt = cur * 2;

            if(nxt < 0) continue;
            if(nxt > b * 3) continue;

            if(vis[nxt] == 0)
            {
                q.push(make_pair(nxt, dist+1));
                
            }
        }
    }

    cout << v << endl;
    cout << cnt;


}
