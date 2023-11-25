#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<int> adjList[202];
bool isVisited[202];

void BFS(int st);

int solution(int n, vector<vector<int>> computers)
{
    int answer = 0;
    
    for (int i = 0; i < n; ++i)
    {
        for (int j = 0; j < n; ++j)
        {
            if ((i == j) || (computers[i][j] == 0))
            {
                continue;
            }
            
            adjList[i].push_back(j);
        }
    }
    
//     for (int i = 0; i < n; ++i)
//     {
//         cout << "(i: " << i << ") ";
        
//         for (int j = 0; j < adjList[i].size(); ++j)
//         {
//             cout << adjList[i][j] << " -> ";
//         }
        
//         cout << '\n';
//     }
    
    for (int i = 0; i < n; ++i)
    {
        if (!isVisited[i])
        {
            BFS(i);
            ++answer;
        }
    }
    
    return answer;
}

void BFS(int st)
{
    queue<int> q;
    
    isVisited[st] = true;
    q.push(st);
    
    while (!q.empty())
    {
        int cur = q.front();
        
        q.pop();
        
        for (int v : adjList[cur])
        {
            if (!isVisited[v])
            {
                isVisited[v] = true;
                q.push(v);
            }
        }
    }
}
