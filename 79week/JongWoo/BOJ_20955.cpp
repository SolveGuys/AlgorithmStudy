#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int answer;
int n, m;
vector<int> adjList[100'001];
bool isVisited[100'001];

int BFS(int st);

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;

    for (int i = 0; i < m; ++i)
    {
        int u = 0, v = 0;

        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }

    for (int i = 1; i <= n; ++i)
    {
        if (!isVisited[i])
        {
						// 그룹이 존재할 때마다 + 1
            answer += BFS(i) + 1;
        }
    }

		// 각 그룹을 연결하는 데 필요한 간선의 수 : 그룹의 수 - 1
    cout << answer - 1 << '\n';
}

int BFS(int st)
{
    queue<int> q;
    int vertexCnt = 0, edgeCnt = 0;

    isVisited[st] = true;
    q.push(st);

    while (!q.empty())
    {
        int cur = q.front();

        q.pop();
        ++vertexCnt;
        edgeCnt += static_cast<int>(adjList[cur].size());

        for (int v : adjList[cur])
        {
            if (!isVisited[v])
            {
                isVisited[v] = true;
                q.push(v);
            }
        }
    }

		// 간선을 계산할 때 양방향 그래프이므로 똑같은 간선을 2번 계산하기 때문에 2로 나누어 준다.
		// return 값은 총 간선의 수에서 사용한 간선의 수를 뺀 값으로, 지워야 하는 간선의 수이다.
    return (edgeCnt / 2) - (vertexCnt - 1);
}
