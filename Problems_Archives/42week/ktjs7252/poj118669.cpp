#include <bits/stdc++.h>
#include <string>
#include <vector>

using namespace std;

vector<pair<int,int>> adj[50001];
priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
int dist[50001];
int visited[50001];
const int INF=987654321;
vector<pair<int,int>> v;


vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
    vector<int> answer;
    answer.push_back(0);
    answer.push_back(INF);
    fill(dist,dist+50001,INF);
    for(int i=0;i<paths.size();i++)
    {
        adj[paths[i][0]].push_back({paths[i][2],paths[i][1]});
        adj[paths[i][1]].push_back({paths[i][2],paths[i][0]});
    }
    for(int i=0;i<summits.size();i++)
    {
        visited[summits[i]]=1;
    }
    
    for(int i=0;i<gates.size();i++)
    {
        pq.push({0,gates[i]});
        dist[gates[i]]=0;
    }
    
    while(pq.size())
    {
        int here=pq.top().second;
        int here_dist=pq.top().first;
        pq.pop();
        if(dist[here]<here_dist) continue; // S3
        
        for(pair<int,int> there:adj[here])
        {
            int _there=there.second;
            int _dist=there.first;
            //자신의 값과 노드사이의 최댓값중에 최솟값을 넣어줌
            
            if(dist[_there]>max(dist[here],_dist))
            {
                dist[_there]=max(dist[here],_dist);
                if(visited[_there]==1) continue;
                pq.push({dist[_there],_there});
            }
        }
    }
    sort(summits.begin(),summits.end());
    for(int i=0;i<summits.size();i++)
    {
        //cout<<summits[i]<<" "<<dist[summits[i]]<<"\n";
        if(answer[1]>dist[summits[i]])
        {
            answer[0]=summits[i];
            answer[1]=dist[summits[i]];
        }
    }
    
    
    
    return answer;
}

// Q1) 다익스트라는 양방향으로 넣어주어야 한다. 하지만 정상에서 출입구로 되돌아올때를 생각해야 하는가?
//     ->갈떄의 최솟값이 생성되었기에 필요가 없음, 다익스트라꼴이지만 다익스트라 아님(S3)

// S1) 출발지를 가다가 다른 출발지를 거쳐서 갈때의 최솟값이 갱신 될 수 있다. (탈출조건)
// S2) 각 출발지는 정상에 해당하는 return값을 전부 담아두고 한번에 비교하는게 편함
//     -> 정상에 도착했으면 더 이상 다른 정상에 가지 않기 위해 바로 값을 넣어줘야함

// S3) 각 노드에선 현재까지의 최댓값을 가짐 , 정점에 도착해서야 최솟값을 판별
//     -> 판별하기 위해선 정점에 도착해서 판별해야 할까, 도착직전에 판별해서 정점에 값을 넣어줘야 할까
//     -> 도착해서 판별하려면 매번 정점인지 체크해주면서 최솟값을 갱신

//  ***  정점인지를 판별하는게 아니라 정점이 어디인지 모른다는 가정하에 노드를 방문했을떄 최솟값이 생기게 한다.
//       정점을 두번 방문했을때와 출발지를 두번 방문했을때를 무시? 이렇게 해야 시간초과가 안걸린    


// 시간초과를 피하기 위해선
// -> 모든 출입구에서 한 번씩 다익스트라 하지않고 어느 출입구에서 출발하는지 상관없게 한번에 다익스트라
// -> 정점인지 판별도 한번에 해야함, 매번하면 시간초과

// 
