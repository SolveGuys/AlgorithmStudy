#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <queue>
#include <set>
using namespace std;

int n, m;
vector<int> adj[100002];
int vis[100004];
int u, v;
int main()
{           
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> n >> m;

    //뉴런개수가 1,2,,,, n 이렇게?
    for(int i = 0; i < m; i++)
    {   
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    queue<int> _queue;
    int gn = 0;
    int sn = 0;
    for(int i = 1; i <= n; i++)
    {
        if(vis[i] != 0) continue;
        gn++;
        vis[i] = 1;
        _queue.push(i);

        set<int> _set; // 지금 순회하는 정점에 연결된 정점
        _set.insert(i);
         
        while(!_queue.empty())
        {
            int cur = _queue.front();
            _queue.pop();
            for(auto m: adj[cur])
            {
                if(vis[m]!=0) continue;
                vis[m] = 1;
                _queue.push(m);
                _set.insert(m);

            }

        }
        int edges = 0;
        for(auto s:_set) edges += adj[s].size();
        sn += (edges/2) - (_set.size() -1);



    }
    
    cout <<gn + sn - 1;
    
}
