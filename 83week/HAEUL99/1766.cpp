#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<int> adj[32002];
int deg[32002];
priority_queue<int, vector<int>, greater<int>> pq; 
vector<int> result;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;

    for(int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        deg[v]++;
    }

    for(int i = 1; i <= n; i++)
    {
        if(deg[i] == 0) pq.push(i);
    }

    while(!pq.empty())
    {
        int cur = pq.top(); pq.pop();
        result.push_back(cur);
        for(auto nxt: adj[cur])
        {
            deg[nxt]--;
            if(deg[nxt] == 0) pq.push(nxt);
        }
    }
    
    for(auto x: result) cout << x << ' ';
}
