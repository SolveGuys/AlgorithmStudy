#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> adj[20001];
int dist[20001];
priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
const int INF=987654321;

int solution(int n, vector<vector<int>> edge) {
    int answer = 0;
    fill(dist,dist+20001,INF);
    
    for(int i=0;i<edge.size();i++)
    {
        adj[edge[i][0]].push_back({1,edge[i][1]});
        adj[edge[i][1]].push_back({1,edge[i][0]});
        
    }
    dist[1]=0;
    pq.push({0,1});
    
    while(pq.size())
    {
        int here=pq.top().second;
        int here_dist=pq.top().first;
        pq.pop();
        
        if(dist[here]!=here_dist) continue;
        
        for(pair<int,int> there : adj[here])
        {
            int _there=there.second;
            int _there_dist=there.first;
            
            if(dist[_there]>dist[here]+_there_dist)
            {
                dist[_there]=dist[here]+_there_dist;
                pq.push({dist[_there],_there});
            }
        }
    }
    int tmp=0;
    for(int i=1;i<=n;i++)
    {
        
        if(dist[i]==INF) continue;
        tmp=max(tmp,dist[i]);
    }
    
    for(int i=1;i<=n;i++)
    {
        if(tmp==dist[i])
        {
            answer++;
        }
    }
    
    
    
    
    
    
    return answer;
}
