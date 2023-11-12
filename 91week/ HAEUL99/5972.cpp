#include <iostream>
#include <string>
#include <set>
#include <vector>
#include <queue>
#include <limits.h>
#include <algorithm>
using namespace std;

int v, e;

vector<pair<int, int>> adj[50002];
int d[50002];

int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> v >> e;
    fill(d, d+v+1, INT_MAX);

    for(int i = 0; i < e; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        adj[u].push_back(make_pair(w, v));
        adj[v].push_back(make_pair(w, u));

    }

    //거리가 작은수부터 출력
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;

    d[1] = 0;

    pq.push(make_pair(d[1], 1));

    while(!pq.empty())
    {
        auto cur = pq.top(); pq.pop();

        if(d[cur.second]!=cur.first) continue;
        for(auto nxt: adj[cur.second])
        {
            if(d[nxt.second] <= d[cur.second] + nxt.first) continue;
            d[nxt.second] = d[cur.second] + nxt.first;
            pq.push(make_pair(d[nxt.second], nxt.second));
        }
    }


    cout << d[v];

    
}
