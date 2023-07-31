#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int n, m;
vector<vector<int>> inDegrees;
vector<vector<int>> outDegrees;

int BFS(const vector<vector<int>>& v, int st);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    inDegrees.resize(n + 1);
    outDegrees.resize(n + 1);

    for (int i = 0; i < m; ++i)
    {
        int u = 0, v = 0;

        cin >> u >> v;
        inDegrees[u].push_back(v);
        outDegrees[v].push_back(u);
    }

    int answer = 0;
    int half = (n + 1) / 2;

    for (int i = 1; i <= n; ++i)
    {
        int lightCnt = BFS(inDegrees, i);
        int heavyCnt = BFS(outDegrees, i);

        if ((lightCnt >= half) || (heavyCnt >= half))
        {
            ++answer;
        }
    }

    cout << answer << '\n';
}

int BFS(const vector<vector<int>>& v, int st)
{
    int cnt = 0;
    queue<int> q;
    vector<bool> isVisited(n + 1);

    isVisited[st] = true;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();

        q.pop();

        for (int u : v[cur])
        {
            if (isVisited[u])
            {
                continue;
            }

            isVisited[u] = true;
            q.push(u);
            ++cnt;
        }
    }

    return cnt;
}
