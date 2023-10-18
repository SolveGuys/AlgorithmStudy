#include <bits/stdc++.h>


using namespace std;

vector<int> adj[100002];
int d[100002];
vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination) {
    vector<int> answer;
    
    for(int i = 0; i < roads.size(); i++)
    {
        int u = roads[i][0]; int v = roads[i][1];
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
    
    //부대원들 현 위치로 bfs
    for(int i = 0; i < sources.size(); i++)
    {        
        fill(d, d+100001, -1);
        queue<int> q;
        q.push(sources[i]);
        d[sources[i]] = 0;
        while(!q.empty())
        {
            int cur = q.front();
            q.pop();
            
            for(int nxt: adj[cur])
            {
                if(d[nxt] != -1) continue;
                d[nxt] = d[cur] +1;
                q.push(nxt);
            }
            
        }
        
        if(d[destination] == -1) answer.push_back(-1);
        else answer.push_back(d[destination]);
        
        
    }
    
    return answer;
}
