#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,k,w;
const int maxi = 1001;
int getNode[maxi];//진입 노드
int build[maxi];//각 건물
int buildTime[maxi];//각 건물 짓는데 드는 시간
vector<int> graph[maxi];//그래프
//4방 탐색
int dx[4] = { -1,0,1,0 };
int dy[4] = { 0,1,0,-1 };

//max
inline int max(int x, int y) {
    return x > y ? x : y;
}
//입력
void input() {
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> build[i];
    for (int i = 0; i < k; i++) {
        int a, b;
        cin >> a >> b;
        graph[a].push_back(b);
        getNode[b]+=1;
    }
    cin >> w;
}
//초기화
void Init() {
    for (int i = 1; i < maxi; i++) {
        build[i] = 0;
        graph[i].clear();
        getNode[i] = 0;
        buildTime[i] = 0;
    }
}
//건설
void Building() {
    queue<int> q;
    //진입노드 0인것 모두 큐에 넣기
    for (int i = 1; i <= n; i++) {
        if (getNode[i] == 0) {
            q.push(i);
            buildTime[i] = build[i];
        }
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        //다음 지점
        for (int i = 0; i < graph[x].size(); i++) {
            int next = graph[x][i];
            getNode[next]--;//진입노드 제거

            if (getNode[next] == 0) q.push(next);
            buildTime[next] = max(buildTime[next], buildTime[x] + build[next]);
        }
    }
    cout << buildTime[w] << "\n";
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int t; cin >> t;
    while (t--) {
        Init();//초기화
        input();//입력
        Building();//건물짓기
    }
    return 0;
}
