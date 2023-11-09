#include <iostream>
#include <vector>
#include <queue>
using namespace std;
typedef long long ll;

int n,m;
const int inf = 21000000;
const int maxi = 50001;
vector<pair<int, int>> graph[maxi];//그래프
int dist[maxi];//거리

//max
inline ll max(ll x, ll y) {
    return x > y ? x : y;
}

//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
}
//초기화
void Init() {
    for (int i = 1; i <= n; i++) dist[i] = inf;
}
//다익스트라
void Dijk(int start) {
    priority_queue<pair<int, int>> pq;
    dist[start] = 0;
    pq.push({ 0,start });

    while (!pq.empty()) {
        int curNode = pq.top().second;
        int curDist = -pq.top().first;
        pq.pop();

        if (dist[curNode] < curDist) continue;

        for (int i = 0; i < graph[curNode].size(); i++) {
            int nextNode = graph[curNode][i].first;
            int nextDist = graph[curNode][i].second;

            if (curDist + nextDist < dist[nextNode]) {
                dist[nextNode] = curDist + nextDist;
                pq.push({ -dist[nextNode], nextNode });
            }
        }
    }
    cout << dist[n];//출력
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Init();//초기화
    Dijk(1);//다익스트라
    return 0;
}
