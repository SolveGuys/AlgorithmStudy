#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjList[20'002];
bool isVisited[20'002];

int BFS(int st);

int solution(int n, vector<vector<int>> edge)
{
    int answer = 0;
    
    for (const vector<int>& e : edge)
    {
        adjList[e[0]].push_back(e[1]);
        adjList[e[1]].push_back(e[0]);
    }
    
    answer = BFS(1);
    
    return answer;
}

int BFS(int st)
{
    int ret = 0;
    queue<int> q;
    
    isVisited[st] = true;
    q.push(st);
    
    while (!q.empty())
    { 
        ret = q.size();
        
        for (int i = 0; i < ret; ++i)
        {
            int cur = q.front();
            
            q.pop();
            
            for (int v : adjList[cur])
            {
                if (isVisited[v])
                {
                    continue;
                }
                
                isVisited[v] = true;
                q.push(v);
            }
        }
    }
    
    return ret;
}
