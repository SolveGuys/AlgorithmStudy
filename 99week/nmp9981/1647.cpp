#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
const int maxi = 100001;
vector<pair<int, pair<int, int>>> graph;
int root[maxi];//각 노드의 루트노드

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}
//초기화
void init() {
    for (int i = 0; i < maxi; i++) root[i] = i;
}
//입력
void input() {
    cin >> n>>m;
    for (int i = 0; i < m; i++) {
        int a, b, c;
        cin >> a >> b >> c;
        graph.push_back({ c,{a,b} });
        //graph.push_back({ c,{b,a} });
    }
    sort(graph.begin(), graph.end());//가중치 기준으로 오름차순
}
//루트 노드
int Find(int x) {
    if (root[x] == x) return x;
    return root[x] = Find(root[x]);
}
//합치기
void Merge(int fx,int fy) {
    if (fx < fy) root[fy] = fx;
    else root[fx] = fy;
}
//길 연결
void RoadConnect() {
    int node = 0;
    int total = 0;
    int graphSize = graph.size();
    for (int i = 0; i < graphSize; i++) {
        int x = graph[i].second.first;
        int y = graph[i].second.second;
        int cost = graph[i].first;

        if (node == n - 2) break;//모두 연결

        int fx = Find(x);
        int fy = Find(y);
        if (fx != fy) {//연결
            Merge(fx, fy);
            node++;
            total += cost;
        }
    }
    cout << total;
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    init();//초기화
    input();//입력
    RoadConnect();//길 연결
    return 0;
}
