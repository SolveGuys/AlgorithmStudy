#include <iostream>
#include <unordered_set>
#include <vector>
#include <queue>
using namespace std;

int t;
int v, e;
int u, w;
vector<int> adj[20002];

//bool map[20002][20002];

int dist[20002];

bool solve()
{
    fill(dist+1, dist+v+1, -1);
    for(int i = 1; i <= v; i++)
    {
        if(dist[i] != -1) continue;
        queue<int> _queue;

        
        _queue.push(i);
        dist[i] = 0;



        while(!_queue.empty())
        {
            int cur = _queue.front();
            _queue.pop();

            for(auto m:adj[cur])
            {
                if(dist[m] != -1)
                {
                    if(dist[m] == dist[cur]) return false;
                    else continue;
                }
                dist[m] = (dist[cur] + 1)%2;
                _queue.push(m);

            }
        }

    }
    return true;
}
int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        for(int i =1; i<=v;i++)
            adj[i].clear();
        for(int i = 0; i < e; i++)
        {
            cin >> u >> w;
            adj[u].push_back(w);
            adj[w].push_back(u);

        }

        
        if(solve()) cout << "YES\n";
        else cout << "NO\n";



    }


    
}
