#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n, m;
int u, v;
vector<int> adj[102];
vector<int> adj1[102];
int vis[102];
int main()
{           
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        cin >> u >> v;
        adj[u].push_back(v);
        adj1[v].push_back(u);
    }
    int ans = 0;
    int cmpv = (n+1)/2;
    for(int i = 1; i <= n; i++)
    {
        fill(vis+1, vis+n+1, -1);
        queue<int> _queue;
        _queue.push(i);
        vis[i] = 1;
        int cnt = 0;
        while(!_queue.empty())
        {
            int cur = _queue.front();
            _queue.pop();

            for(auto m:adj[cur])
            {
                if(vis[m] == 1) continue;
                vis[m] = 1;
                _queue.push(m);
                cnt++;

            }
        }


        fill(vis+1, vis+n+1, -1);
        queue<int> _queue1;
        _queue1.push(i);
        vis[i] = 1;
        int cnt1 = 0;
        while(!_queue1.empty())
        {
            int cur = _queue1.front();
            _queue1.pop();

            for(auto m:adj1[cur])
            {
                if(vis[m] == 1) continue;
                vis[m] = 1;
                _queue1.push(m);
                cnt1++;

            }
        }
        if(cnt>=cmpv || cnt1>=cmpv) ans++;

    }    

    cout << ans;

}
