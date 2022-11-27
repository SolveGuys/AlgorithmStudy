#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

int n,idx, maxDepth,diameter;
const int maxi = 10001;
vector<pair<int, int>> graph[maxi];//그래프
int depth[maxi];//루트 노드에서의 길이
int dist[maxi];//i->j까지의 길이

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n;
    for (int i = 0; i < n-1; i++) {
        int a, b, c;
        cin >> a >> b>>c;
        graph[a].push_back({ b,c });
        graph[b].push_back({ a,c });
    }
    //초기화
    memset(depth, -1, sizeof(depth));
    memset(dist, -1, sizeof(dist));
    depth[1] = 0;
}
//루트노드에서의 길이 구하기
void RootDepth(int st,int len) {
    //다음 지점
    for (int j = 0; j < graph[st].size(); j++) {
        int next = graph[st][j].first;//다음 지점
        int nextLen = graph[st][j].second;//다음 지점까지의 거리
        if (depth[next] != -1) continue;//이미 저장된 거리가 있다.

        depth[next] = len + nextLen;//거리 누적
        RootDepth(next, depth[next]);
    }
}
//가장 거리가 먼 인덱스 구하기
void SearchIndex() {
    idx = 0; maxDepth = 0;
    for (int i = 1; i <= n; i++) {
        if (maxDepth < depth[i]) {
            maxDepth = depth[i];
            idx = i;
        }
    }
    dist[idx] = 0;
}
//인덱스로부터 거리 구하기
void SearchDist(int st, int diam) {
    //다음 지점
    for (int j = 0; j < graph[st].size(); j++) {
        int next = graph[st][j].first;//다음 지점
        int nextLen = graph[st][j].second;//다음 지점까지의 거리
        if (dist[next] != -1) continue;//이미 저장된 거리가 있다.

        dist[next] = diam + nextLen;//거리 누적
        SearchDist(next, dist[next]);
    }
}
//트리의 지름
void Diameter() {
    diameter = 0;
    for (int i = 1; i <= n; i++) {
        if (diameter < dist[i]) diameter = dist[i];
    }
    cout << diameter;//출력
}
int main() {
	//빠른 입력
	ios_base::sync_with_stdio(false);
	cin.tie(0);
	
    input();//입력
    RootDepth(1,0);//루트 노드에서부터의 길이
    SearchIndex();//가장 거리가 먼 인덱스 구하기
    SearchDist(idx, 0);//트리의 지름
    Diameter();//트리의 지름
	return 0;
}
