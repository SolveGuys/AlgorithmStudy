#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool BFS(int v, int e, const vector<vector<int>>& adjLists, vector<bool>& isVisited, vector<int>& groups, int st);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int t = 0;

    cin >> t;

    for (int i = 0; i < t; ++i)
    {
        int v = 0, e = 0;

        cin >> v >> e;

        vector<vector<int>> adjLists(v + 1);
        vector<bool> isVisited(v + 1);
        vector<int> groups(v + 1);

        for (int j = 0; j < e; ++j)
        {
            int a = 0, b = 0;

            cin >> a >> b;
            adjLists[a].push_back(b);
            adjLists[b].push_back(a);
        }

        bool isBinary = true;

        for (int i = 1; i <= v; ++i)
        {
            if (!isVisited[i])
            {
                if (!BFS(v, e, adjLists, isVisited, groups, i))
                {
                    isBinary = false;
                    break;
                }
            }
        }

        cout << ((isBinary) ? "YES" : "NO") << '\n';
    }
}

bool BFS(int v, int e, const vector<vector<int>>& adjLists, vector<bool>& isVisited, vector<int>& groups, int st)
{
    queue<int> q;

    isVisited[st] = true;
    groups[st] = 1;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();

        q.pop();

        for (int u : adjLists[cur])
        {
            // 이미 이전에 방문한 정점이라면, 같은 그룹이 아니어야 한다.
            if (isVisited[u])
            {
                if (groups[u] == groups[cur])
                {
                    return false;
                }
            }
            else
            {
                // 인접한 정점들은 현재 정점과 다른 그룹으로 만든다.
                isVisited[u] = true;
                groups[u] = 1 - groups[cur];
                q.push(u);
            }
        }
    }

    return true;
}
