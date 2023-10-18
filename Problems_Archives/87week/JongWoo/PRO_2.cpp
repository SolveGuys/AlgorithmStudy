#include <iostream>
#include <vector>
#include <queue>
#include <utility>
#include <algorithm>

using namespace std;

const int INF = 0x7f7f7f7f;

vector<int> adjList[100'002];
int dist[100'002];

vector<int> solution(int n, vector<vector<int>> roads, vector<int> sources, int destination)
{
    vector<int> answer;
    
    for (const vector<int>& r : roads)
    {
        adjList[r[0]].push_back(r[1]);
        adjList[r[1]].push_back(r[0]);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // <cost, index>
    
    fill(dist, dist + n + 1, INF);
    dist[destination] = 0;
    minHeap.emplace(dist[destination], destination);
    
    while (!minHeap.empty())
    {
        int w = minHeap.top().first;
        int idx = minHeap.top().second;
        
        minHeap.pop();
        
        if (w != dist[idx])
        {
            continue;
        }
        
        for (int v : adjList[idx])
        {
            if (dist[v] > dist[idx] + 1)
            {
                dist[v] = dist[idx] + 1;
                minHeap.emplace(dist[v], v);
            }
        }
    }
    
    // for (int i = 1; i <= n; ++i)
    // {
    //     cout << "i: " << i << ", dist: " << dist[i] << '\n';
    // }
    
    for (int v : sources)
    {
        answer.push_back(((dist[v] == INF) ? -1 : dist[v]));
    }
    
    return answer;
}
