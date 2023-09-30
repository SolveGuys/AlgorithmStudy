#include <iostream>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

struct Node
{
    int idx;
    int dist;
};

const int INF = 0x7f7f7f7f;

vector<pair<int, int>> adjList[50'001]; // <weight, index>
int minDist[50'001];

void BFS(int n, int st, const vector<int>& gates, const vector<int>& summits, vector<int>& answer);

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits)
{
    vector<int> answer(2, INF);
    
    for (const auto& path : paths)
    {
        int a = path[0], b = path[1], w = path[2];
        
        adjList[a].emplace_back(w, b);
        adjList[b].emplace_back(w, a);
    }
    
    for (int gate : gates)
    {
        BFS(n, gate, gates, summits, answer);
    }
    
    return answer;
}

void BFS(int n, int st, const vector<int>& gates, const vector<int>& summits, vector<int>& answer)
{
    for (int i = 1; i <= n; ++i)
    {
        minDist[i] = INF;
    }
    
    for (int g : gates)
    {
        if (g == st)
        {
            continue;
        }
        
        minDist[g] = -INF;
    }
    
    queue<Node> q;
    
    minDist[st] = 0;
    q.push({ st, minDist[st] });
    
    while (!q.empty())
    {
        Node cur = q.front();
        
        q.pop();
        
        if (cur.dist > answer[1])
        {
            continue;
        }
        
        bool isArrived = false;
        
        for (int summit : summits)
        {
            if (summit == cur.idx)
            {
                //cout << summit << ", " << cur.dist << '\n';
                
                if (cur.dist == answer[1])
                {
                    if (cur.idx < answer[0])
                    {
                        answer[0] = summit;
                        answer[1] = cur.dist;
                    }
                }
                else
                {
                    answer[0] = summit;
                    answer[1] = cur.dist;   
                }
                
                isArrived = true;
            }
        }
        
        if (isArrived)
        {
            continue;
        }
        
        for (const auto& nxt : adjList[cur.idx])
        {
            if ((cur.dist < minDist[nxt.second]) && (nxt.first < minDist[nxt.second]))
            {
                minDist[nxt.second] = max(cur.dist, nxt.first);
                q.push({ nxt.second, minDist[nxt.second] });
            }
        }
    }
    
    //cout << "===============\n";
}
