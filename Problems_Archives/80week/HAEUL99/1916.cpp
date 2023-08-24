#include <iostream>
#include <vector>
#include <queue>
#include <limits.h>
using namespace std;

int n, m;
int u, v, w;
int st, en;
vector<pair<int, int>> adj[1004]; //비용, 도착도시 (출발도시별)
int d[1004];

int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    fill(d, d + n + 1, INT_MAX);
    for(int i = 0; i < m; i++)
    {
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
    }
    cin >> st >> en;

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq; //최소값 출력하는 우선순위 큐
    d[st] = 0;
    pq.push(make_pair(0, st));

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();
        if(cur.first != d[cur.second]) continue;
        for(auto nxt:adj[cur.second])
        {
            if(d[nxt.second] <= d[cur.second] + nxt.first) continue;

            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push(make_pair(d[nxt.second], nxt.second));
        }
    }

    cout << d[en];
    
}
