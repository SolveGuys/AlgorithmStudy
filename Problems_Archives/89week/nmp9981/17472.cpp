#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int n,m;
const int maxi = 11;
int islandCount = 0;//섬 개수
int root[maxi];//각 노드의 루트 노드
int world[maxi][maxi];//지도 
int dist[maxi][maxi];//i->j번 섬까지의 최단거리
bool visit[maxi][maxi];//방문 여부
vector<pair<int, pair<int, int>>> road;//길
//4방 탐색
int dx[4] = { 1,0,-1,0 };
int dy[4] = { 0,1,0,-1 };
//min
inline int min(int x, int y) {
    return x > y ? y : x;
}

//입력
void input() {
    cin >>n>>m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) cin >> world[i][j];
    }
}
//초기화
void Init() {
    for (int i = 1; i <= 6; i++) {
        for (int j = 1; j <=6; j++) dist[i][j] = maxi;
    }
    for (int i = 1; i <= 6; i++) root[i] = i;
}
//넘버링(섬을 num번으로 붙여줌)
void Numbering(int i, int j, int num) {
    visit[i][j] = true;
    world[i][j] = num;
    queue<pair<int, int>> q;
    q.push({ i,j });

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        //다음 지점
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (nx < 0 || nx >= n || ny < 0 || ny >= m) continue;//범위 조건
            if (visit[nx][ny]) continue;//이미 방문
            if (world[nx][ny] == 0) continue;//바다

            world[nx][ny] = num;
            visit[nx][ny] = true;
            q.push({ nx,ny });
        }
    }

}
//섬 넘버링
void NumberIsland() {
    int num = 1;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (!visit[i][j] && world[i][j] == 1) {//미방문 섬 지역
                Numbering(i, j, num);//num으로 번호를 붙여준다.
                num++;//번호 증가
            }
        }
    }
    islandCount = num - 1;//섬 개수
}
//섬 탐색
void SearchIsland() {
    //각 지점에서
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (world[i][j] >= 1) {//섬 지역
                //동남서북 탐색
                for (int k = 0; k < 4; k++) {
                    int x = i; int y = j;//현 위치
                    int start = world[i][j];//출발 지점

                    int arrive = 0;//도착 지점
                    int len = 0;
                    while (true) {
                        x += dx[k];
                        y += dy[k];
                        if (x < 0 || x >= n || y < 0 || y >= m) break;//범위 조건
                        if (world[x][y] == start) break;//같은 섬
                        if (world[x][y] > 0 && world[x][y] != start) {//다른 섬
                            arrive = world[x][y];
                            break;
                        }
                        len++;
                    }
                    //다리 최단길이 갱신
                    if (len >= 2 && arrive>0) dist[start][arrive] = min(dist[start][arrive], len);
                }
            }
        }
    }
    //교통 정리
    for (int i = 1; i <= 5; i++) {
        for (int j = i + 1; j <= 6; j++) {
            if(dist[i][j]<maxi) road.push_back({ dist[i][j],{i,j} });
        }
    }
}
//루트 노드 찾기
int Find(int r) {
    if (root[r] == r) return r;
    return root[r] = Find(root[r]);
}
//그래프 연결
void Connect(int a, int b) {
    if (a < b) root[b] = a;
    else root[a] = b;
}
//다리 연결
void ConnectBridge() {
    if(road.size()>0) sort(road.begin(), road.end());//거리순 정렬

    int node = 0;
    int total = 0;
    for (int i = 0; i < road.size(); i++) {
        int curDist = road[i].first;
        int x = road[i].second.first;
        int y = road[i].second.second;

        int fx = Find(x);
        int fy = Find(y);
        if (fx != fy) {//루트노드가 서로 다르면 연결
            Connect(fx, fy);
            node++;
            total += curDist;
        }
        if (node == islandCount - 1) {//모두 연결
            cout << total;
            return;
        }
    }
    cout << -1;//모두 연결 불가
}
int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    input();//입력
    Init();//초기화
    NumberIsland();//섬 넘버링
    SearchIsland();//섬 탐색
    ConnectBridge();//다리 연결
    return 0;
}
