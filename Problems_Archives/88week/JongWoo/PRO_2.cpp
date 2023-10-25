#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

struct Edge
{
    int u;
    int v;
    int cost;
    
    bool operator <(const Edge& other)
    {
        if (cost == other.cost)
        {
            return u < other.u;
        }
        
        return cost < other.cost;
    }
};

// 1. 크루스칼 알고리즘을 이용한 풀이
int parent[102];

int Kruskal(int n, const vector<vector<int>>& costs);
int GetRoot(int v);
void SetUnion(int root1, int root2);

// 2. 프림 알고리즘을 이용한 풀이
const int MAX = 0x7f7f7f7f;
bool isSelected[102];

int Prim(int n, const vector<vector<int>>& costs);

int solution(int n, vector<vector<int>> costs)
{
    int answer = 0;
    
    answer = Kruskal(n, costs);
    //answer = Prim(n, costs);
    
    return answer;
}

int Kruskal(int n, const vector<vector<int>>& costs)
{
    int ret = 0;
    vector<Edge> edges;
    
    edges.reserve(costs.size());
    
    for (int i = 1; i <= n; ++i)
    {
        parent[i] = i;
    }
    
    for (const vector<int>& c : costs)
    {
        edges.push_back({ c[0], c[1], c[2] });
    }
    
    sort(edges.begin(), edges.end());
    
    int cnt = 0;
    
    for (const Edge& e : edges)
    {
        int root1 = GetRoot(e.u);
        int root2 = GetRoot(e.v);
        
        if (root1 != root2)
        {
            SetUnion(root1, root2);
            ret += e.cost;
            ++cnt;
            
            if (cnt == n - 1)
            {
                break;
            }
        }
    }
    
    return ret;
}

int GetRoot(int v)
{
    if (v == parent[v])
    {
        return v;
    }
    
    return parent[v] = GetRoot(parent[v]);
}

void SetUnion(int root1, int root2)
{
    if (root1 <= root2)
    {
        parent[root2] = root1;
    }
    else
    {
        parent[root1] = root2;
    }
}

int Prim(int n, const vector<vector<int>>& costs)
{
    int ret = 0;
    vector<pair<int, int>> adjList[102];
    
    for (const vector<int>& c : costs)
    {
        adjList[c[0]].emplace_back(c[2], c[1]);
        adjList[c[1]].emplace_back(c[2], c[0]);
    }
    
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> minHeap; // <cost, index>
    
    // 1번 정점을 시작 정점으로 선택
    int st = 1, cnt = 0;
    
    minHeap.emplace(0, st);
    
    while ((!minHeap.empty()) && (cnt < n))
    {
        int cost = minHeap.top().first;
        int idx = minHeap.top().second;
        
        minHeap.pop();
        
        if (isSelected[idx])
        {
            continue;
        }
        
        isSelected[idx] = true;
        ret += cost;
        ++cnt;
        
        for (const auto& p : adjList[idx])
        {
            if (!isSelected[p.second])
            {
                minHeap.emplace(p.first, p.second);
            }
        }
    }
    
    return ret;
}
